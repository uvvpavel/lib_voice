# Makefile for app_pipeline (alt_arch, vx4b)
# Generated from CMake configuration analysis
#
# Prerequisites:
#   1. Activate virtual environment: source ../../.venv/bin/activate
#   2. Set up tools: source ~/tools/tools/bob_71_0.2.8/SetEnv.sh
#
# Then run: make

# ============================================================================
# Configuration
# ============================================================================

# Compiler settings
CC := clang
CXX := clang++
AS := clang
ARCH := vx4b

# Project directories
PROJECT_ROOT := ../..
LIB_VOICE := $(PROJECT_ROOT)/lib_voice
LIB_XCORE_MATH := $(PROJECT_ROOT)/../lib_xcore_math/lib_xcore_math
APP_SRC := src
BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj
BIN_DIR := $(BUILD_DIR)/bin
VNR_MODEL_DIR := vnr_model

# AI Tools
XMOS_AITOOLSLIB := $(shell python -c "import os; import xmos_ai_tools.runtime as rt; print(os.path.dirname(rt.__file__))")
TFLITE_LIB := $(XMOS_AITOOLSLIB)/lib/libxtflitemicro_vx4b.a

# Output
TARGET := $(BIN_DIR)/app_pipeline_alt_arch

# ============================================================================
# Compiler flags
# ============================================================================

# Preprocessor defines
DEFINES := \
	-D__VX4B__ \
	-DNO_INTERPRETER \
	-DTF_LITE_STATIC_MEMORY \
	-DTF_LITE_STRIP_ERROR_STRINGS \
	-DXCORE \
	-DHEADROOM_CHECK=0 \
	-DALT_ARCH_MODE=1

# Include directories
INCLUDES := \
	-I$(LIB_XCORE_MATH)/api \
	-I$(LIB_XCORE_MATH)/src/vect \
	-I$(LIB_XCORE_MATH)/src/etc/xmath_fft_lut \
	-I$(LIB_VOICE)/api \
	-I$(LIB_VOICE)/api/adec \
	-I$(LIB_VOICE)/api/aec \
	-I$(LIB_VOICE)/src/aec \
	-I$(LIB_VOICE)/api/agc \
	-I$(LIB_VOICE)/api/ic \
	-I$(LIB_VOICE)/src/ic \
	-I$(LIB_VOICE)/api/ns \
	-I$(LIB_VOICE)/src/ns \
	-I$(LIB_VOICE)/api/stage1 \
	-I$(LIB_VOICE)/api/vnr \
	-I$(LIB_VOICE)/src/vnr \
	-I$(VNR_MODEL_DIR) \
	-isystem$(XMOS_AITOOLSLIB)/include

COMMON_FLAGS := \
	-g \
	-Os \
	-mcpu=xmos-vx4b

# Compiler flags
# CFLAGS := -g -Os -mcpu=xmos-vx4b -mllvm --riscv-xcore-emit-stack-usage=1 -ffunction-sections -fdata-sections $(DEFINES) $(INCLUDES)
CFLAGS := -mllvm --riscv-xcore-emit-stack-usage=1 -ffunction-sections -fdata-sections $(COMMON_FLAGS) $(DEFINES) $(INCLUDES)
# CXXFLAGS := -std=c++11 -g -Os -mllvm --riscv-xcore-emit-stack-usage=1 -fvirtual-fptrgroups -mcpu=xmos-vx4b -fno-exceptions -ffunction-sections -fdata-sections $(DEFINES) $(INCLUDES)
CXXFLAGS := -std=c++11 -mllvm --riscv-xcore-emit-stack-usage=1 -fno-exceptions -ffunction-sections -fdata-sections $(COMMON_FLAGS) $(DEFINES) $(INCLUDES)
# ASFLAGS := -g -Os -mcpu=xmos-vx4b $(DEFINES) $(INCLUDES)
ASFLAGS := $(COMMON_FLAGS) $(DEFINES) $(INCLUDES)

# Linker flags
# LDFLAGS :=  -lxcore -Wl,--defsym,__vx4a_divsf3=__divsf3 -Wl,--gc-sections -Wl,--resource-calculation -Wl,-Map,mapfile.map -fno-exceptions
LDFLAGS :=  -lxcore -Wl,--defsym,__vx4a_divsf3=__divsf3 -Wl,--gc-sections -Wl,--resource-calculation -fno-exceptions
LIBS := $(TFLITE_LIB)

# ============================================================================
# Source files
# ============================================================================

# Application sources
APP_C_SOURCES := \
	$(APP_SRC)/app.c \
	$(APP_SRC)/pipeline.c

# lib_voice sources
LIB_VOICE_C_SOURCES := \
	$(LIB_VOICE)/src/adec/adec_impl.c \
	$(LIB_VOICE)/src/adec/adec_priv_impl.c \
	$(LIB_VOICE)/src/adec/de_impl.c \
	$(LIB_VOICE)/src/aec/aec_impl.c \
	$(LIB_VOICE)/src/aec/aec_l2_impl.c \
	$(LIB_VOICE)/src/aec/aec_priv_impl.c \
	$(LIB_VOICE)/src/aec/aec_process_frame.c \
	$(LIB_VOICE)/src/aec/aec_schedule_defaults.c \
	$(LIB_VOICE)/src/agc/agc_impl.c \
	$(LIB_VOICE)/src/ic/ic.c \
	$(LIB_VOICE)/src/ic/ic_low_level.c \
	$(LIB_VOICE)/src/ns/ns_impl.c \
	$(LIB_VOICE)/src/ns/ns_low_level.c \
	$(LIB_VOICE)/src/stage1/delay_buffer.c \
	$(LIB_VOICE)/src/stage1/stage1.c \
	$(LIB_VOICE)/src/vnr/vnr.c \
	$(LIB_VOICE)/src/vnr/vnr_features.c \
	$(LIB_VOICE)/src/vnr/vnr_features_priv.c

LIB_VOICE_CXX_SOURCES := \
	$(LIB_VOICE)/src/vnr/vnr_inference.cpp \
	$(LIB_VOICE)/src/vnr/vnr_inference_priv.cpp \
	$(LIB_VOICE)/src/vnr/wrapper.cpp

# Pre-existing VNR model (not auto-generated)
VNR_MODEL_SOURCE := $(VNR_MODEL_DIR)/trained_model_xcore.tflite.cpp

# lib_xcore_math C sources
LIB_XCORE_MATH_C_SOURCES := \
	$(LIB_XCORE_MATH)/src/arch/vx4b/chunk_s16/chunk_s16_accumulate.c \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/float_s32.c \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_dot.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_alloc.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_complex_s16.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_complex_s32.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_init.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_s16.c \
	$(LIB_XCORE_MATH)/src/bfp/bfp_s32.c \
	$(LIB_XCORE_MATH)/src/bfp/misc/gradient_constraint.c \
	$(LIB_XCORE_MATH)/src/dct/dct8x8.c \
	$(LIB_XCORE_MATH)/src/dct/dct_forward.c \
	$(LIB_XCORE_MATH)/src/dct/dct_inverse.c \
	$(LIB_XCORE_MATH)/src/etc/xmath_fft_lut/xmath_fft_lut.c \
	$(LIB_XCORE_MATH)/src/fft/fft_bfp.c \
	$(LIB_XCORE_MATH)/src/fft/fft_f32.c \
	$(LIB_XCORE_MATH)/src/filter/filters.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_f32.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_float_complex_sXX.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_float_s32.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_float_s64.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_ops.c \
	$(LIB_XCORE_MATH)/src/scalar/scalar_qXX.c \
	$(LIB_XCORE_MATH)/src/vect/chunk_s32.c \
	$(LIB_XCORE_MATH)/src/vect/complex_prepare.c \
	$(LIB_XCORE_MATH)/src/vect/convolve.c \
	$(LIB_XCORE_MATH)/src/vect/mat_mul.c \
	$(LIB_XCORE_MATH)/src/vect/prepare.c \
	$(LIB_XCORE_MATH)/src/vect/vect_complex_mag_rot_tables.c \
	$(LIB_XCORE_MATH)/src/vect/vect_complex_s16.c \
	$(LIB_XCORE_MATH)/src/vect/vect_complex_s32.c \
	$(LIB_XCORE_MATH)/src/vect/vect_f32.c \
	$(LIB_XCORE_MATH)/src/vect/vect_float_s32.c \
	$(LIB_XCORE_MATH)/src/vect/vect_s16.c \
	$(LIB_XCORE_MATH)/src/vect/vect_s32.c \
	$(LIB_XCORE_MATH)/src/vect/vpu_const_vects.c

# lib_xcore_math Assembly sources (vx4b architecture)
LIB_XCORE_MATH_ASM_SOURCES := \
	$(LIB_XCORE_MATH)/src/arch/vx4b/chunk_s32/chunk_s32_dot.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/chunk_s32/chunk_s32_log.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/chunk_s32/chunk_s32_power_series.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/chunk_s32/chunk_s32_power_series_v2.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct12_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct16_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct24_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct6_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct8_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct_adsb_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/dct_deconvolve_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/idct6_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/idct8_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/idct_adsb.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/idct_convolve.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s32/idct_scale.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s8/dct8x8_stageA.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/s8/dct8x8_stageB.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/dct/vect_s32_flip.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/dif_fft.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/dit_fft.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/fft_hr_lut.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/fft_index_bit_reversal.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/fft_mono_adjust.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/fft_spectra_merge.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/fft_spectra_split.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/fft/tail_reverse_complex_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/filter_biquad_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/filter_biquad_sat_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/filter_fir_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/filter_fir_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/push_sample_down_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/push_sample_up_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/filter/vect_s32_convolve_valid.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/matrix/mat_mul_s8_x_s8_yield_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/misc/chunk_float_s32_log.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/misc/util.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/misc/vect_copy.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/misc/vect_float_s32_ln_prepare.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/misc/xs3_memcpy.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/f32_log2.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/f32_norm.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/f32_power_series.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/f32_sin.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/q24_logistic_fast.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/q30_exp_small.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/q30_odd_powers.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/q30_powers.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/radians_to_sbrads.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/sbrad_sin.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/sbrad_tan.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/scalar_op_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/scalar_op_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/scalar_op_s8.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/scalar/sqrt_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_complex_scale.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_conj_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_conj_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_conjugate_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_mag.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_real_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_squared_mag.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s16/vect_complex_s16_to_complex_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_complex_scale.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_conj_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_conj_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_conjugate.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_conjugate_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_mag.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_real_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_squared_mag.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_complex_s32/vect_complex_s32_to_complex_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_complex_f32_conj_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_complex_f32_conj_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_complex_f32_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_complex_f32_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_f32_add.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_f32_dot.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_f32_max_exponent.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_f32/vect_f32_to_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_abs.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_abs_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_argmax.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_argmin.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_clip.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_energy.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_extract_high_byte.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_extract_low_byte.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_inverse.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_max.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_min.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_scale.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_sqrt.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s16/vect_s16_to_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/s32_to_chunk_s32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_abs.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_abs_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_argmax.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_argmin.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_clip.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_dot.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_energy.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_inverse.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_macc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_max.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_merge_accs.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_min.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_mul.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_nmacc.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_scale.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_split_accs.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_sqrt.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_sum.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_to_f32.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_to_s16.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_unzip.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s32/vect_s32_zip.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_s8/vect_s8_is_negative.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_add.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_headroom.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_rect.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_sXX_add_scalar.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_sXX_max_elementwise.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_sXX_min_elementwise.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_set.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_shl.S \
	$(LIB_XCORE_MATH)/src/arch/vx4b/vect_sXX/vect_sub.S

# Combine all source lists
C_SOURCES := $(APP_C_SOURCES) $(LIB_VOICE_C_SOURCES) $(LIB_XCORE_MATH_C_SOURCES)
CXX_SOURCES := $(LIB_VOICE_CXX_SOURCES) $(VNR_MODEL_SOURCE)
ASM_SOURCES := $(LIB_XCORE_MATH_ASM_SOURCES)

# ============================================================================
# Object files
# ============================================================================

# Generate object file paths - organized in build directory
APP_C_OBJECTS := $(patsubst $(APP_SRC)/%.c,$(OBJ_DIR)/app/%.c.o,$(APP_C_SOURCES))

LIB_VOICE_C_OBJECTS := $(patsubst $(LIB_VOICE)/src/%.c,$(OBJ_DIR)/lib_voice/%.c.o,$(LIB_VOICE_C_SOURCES))
LIB_VOICE_CXX_OBJECTS := $(patsubst $(LIB_VOICE)/src/%.cpp,$(OBJ_DIR)/lib_voice/%.cpp.o,$(LIB_VOICE_CXX_SOURCES))

VNR_MODEL_OBJECT := $(OBJ_DIR)/vnr_model/trained_model_xcore.tflite.cpp.o

LIB_XCORE_MATH_C_OBJECTS := $(patsubst $(LIB_XCORE_MATH)/src/%.c,$(OBJ_DIR)/lib_xcore_math/%.c.o,$(LIB_XCORE_MATH_C_SOURCES))
LIB_XCORE_MATH_ASM_OBJECTS := $(patsubst $(LIB_XCORE_MATH)/src/%.S,$(OBJ_DIR)/lib_xcore_math/%.S.o,$(LIB_XCORE_MATH_ASM_SOURCES))

ALL_OBJECTS := $(APP_C_OBJECTS) $(LIB_VOICE_C_OBJECTS) $(LIB_VOICE_CXX_OBJECTS) \
               $(VNR_MODEL_OBJECT) $(LIB_XCORE_MATH_C_OBJECTS) $(LIB_XCORE_MATH_ASM_OBJECTS)

# ============================================================================
# Build rules
# ============================================================================

.PHONY: all clean dirs

all: $(TARGET)

# Link executable
$(TARGET): $(ALL_OBJECTS) $(TFLITE_LIB) | $(BIN_DIR)
	@echo "Linking $(TARGET)..."
	$(CXX) $(LDFLAGS) -o $@ $(ALL_OBJECTS) $(LIBS)
	@echo "Build complete: $(TARGET)"

# Compile application C sources
$(OBJ_DIR)/app/%.c.o: $(APP_SRC)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compile lib_voice C sources
$(OBJ_DIR)/lib_voice/%.c.o: $(LIB_VOICE)/src/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compile lib_voice C++ sources
$(OBJ_DIR)/lib_voice/%.cpp.o: $(LIB_VOICE)/src/%.cpp
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile VNR model
$(OBJ_DIR)/vnr_model/trained_model_xcore.tflite.cpp.o: $(VNR_MODEL_SOURCE)
	@mkdir -p $(dir $@)
	@echo "Compiling VNR model..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile lib_xcore_math C sources
$(OBJ_DIR)/lib_xcore_math/%.c.o: $(LIB_XCORE_MATH)/src/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Compile lib_xcore_math Assembly sources
$(OBJ_DIR)/lib_xcore_math/%.S.o: $(LIB_XCORE_MATH)/src/%.S
	@mkdir -p $(dir $@)
	@echo "Assembling $<..."
	$(AS) $(ASFLAGS) -c $< -o $@

# Create directories
dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)

# Display configuration
info:
	@echo "Configuration:"
	@echo "  CC:          $(CC)"
	@echo "  CXX:         $(CXX)"
	@echo "  ARCH:        $(ARCH)"
	@echo "  TARGET:      $(TARGET)"
	@echo "  AITOOLS:     $(XMOS_AITOOLSLIB)"
	@echo "  BUILD_DIR:   $(BUILD_DIR)"
	@echo ""
	@echo "Source counts:"
	@echo "  App sources:       $(words $(APP_C_SOURCES))"
	@echo "  lib_voice C:       $(words $(LIB_VOICE_C_SOURCES))"
	@echo "  lib_voice C++:     $(words $(LIB_VOICE_CXX_SOURCES))"
	@echo "  lib_xcore_math C:  $(words $(LIB_XCORE_MATH_C_SOURCES))"
	@echo "  lib_xcore_math ASM: $(words $(LIB_XCORE_MATH_ASM_SOURCES))"
	@echo "  Total objects:     $(words $(ALL_OBJECTS))"

# Help target
help:
	@echo "Available targets:"
	@echo "  all     - Build the application (default)"
	@echo "  clean   - Remove all build artifacts"
	@echo "  info    - Display build configuration"
	@echo "  help    - Show this help message"
	@echo ""
	@echo "Prerequisites:"
	@echo "  1. source ../../.venv/bin/activate"
	@echo "  2. source ~/tools/tools/bob_71_0.2.8/SetEnv.sh"
	@echo ""
	@echo "Note: Uses pre-existing VNR model from $(VNR_MODEL_DIR)/"
