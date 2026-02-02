// Copyright 2022-2026 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include "aec.h"
#include "aec_priv.h"

static aec_state_t aec_state;
void test_init()
{
    #if BUILD_NATIVE
    aec_task_distribution_t tdist = aec_tdist_chans2_threads1;
    #else
    aec_task_distribution_t tdist = aec_tdist_chans2_threads2;
    #endif

    aec_init(&aec_state, 1, 1, 9, 0, &tdist);
}

void test(int32_t *output, int32_t *input)
{
    aec_frame_init(&aec_state.main_state, NULL, &input[2], &input[AEC_PROC_FRAME_LENGTH + 2 + 2]); //frame init will copy y[240:480] into output

    bfp_s32_init(&aec_state.main_state.y_hat[0], (int32_t*)&aec_state.main_state.Y_hat[0].data[0], 0, AEC_PROC_FRAME_LENGTH, 0);


    aec_state.main_state.shared_state->y[0].exp = input[0];
    aec_state.main_state.shared_state->y[0].hr = input[1];
    aec_state.main_state.shared_state->y[0].data = &input[2];

    aec_state.main_state.y_hat[0].exp = input[AEC_PROC_FRAME_LENGTH + 2];
    aec_state.main_state.y_hat[0].hr = input[AEC_PROC_FRAME_LENGTH + 2 + 1];
    aec_state.main_state.y_hat[0].data = &input[AEC_PROC_FRAME_LENGTH + 2 + 2];

    // since aec_state.main_state.shared_state->y is being initialised with a new frame after calling aec_frame_init(), 
    // we need to update aec_state.main_state->shared_state->prev_y again since that's where y[240:480] is read from in aec_calc_coherence()
    memcpy(aec_state.main_state.shared_state->prev_y[0].data,
        &aec_state.main_state.shared_state->y[0].data[AEC_FRAME_ADVANCE],
        (AEC_PROC_FRAME_LENGTH-AEC_FRAME_ADVANCE)*sizeof(int32_t));

    aec_state.main_state.shared_state->prev_y[0].exp = aec_state.main_state.shared_state->y[0].exp;
    aec_state.main_state.shared_state->prev_y[0].hr = aec_state.main_state.shared_state->y[0].hr;

    aec_calc_coherence(&aec_state.main_state, 0);

    coherence_mu_params_t *coh_mu_state_ptr = &aec_state.main_state.shared_state->coh_mu_state[0];

    memcpy(output, &coh_mu_state_ptr->coh, sizeof(float_s32_t));
    memcpy((int8_t *)output + sizeof(float_s32_t), &coh_mu_state_ptr->coh_slow, sizeof(float_s32_t));
}
