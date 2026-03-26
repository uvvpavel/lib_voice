// This file is generated. Do not edit.
// Generated on: 26.03.2026 13:49:16

#ifndef vnr_model_GEN_H
#define vnr_model_GEN_H

#include "tensorflow/lite/c/common.h"

#ifdef SHARED_TENSOR_ARENA
  #ifndef LARGEST_TENSOR_ARENA_SIZE
    #define LARGEST_TENSOR_ARENA_SIZE 840
  #elif LARGEST_TENSOR_ARENA_SIZE < 840
    #define LARGEST_TENSOR_ARENA_SIZE 840
  #endif
#endif

// Sets up the model with init and prepare steps.
TfLiteStatus vnr_model_init(void *weights_data_ptr);
// Returns the input tensor with the given index.
TfLiteTensor *vnr_model_input(int index);
// Returns the output tensor with the given index.
TfLiteTensor *vnr_model_output(int index);
// Runs inference for the model.
TfLiteStatus vnr_model_invoke();
// Resets variable tensors in the model.
// This should be called after invoking a model with stateful ops such as LSTM.
TfLiteStatus vnr_model_reset();

// Returns the number of input tensors.
inline size_t vnr_model_inputs() {
  return 1;
}
// Returns the number of output tensors.
inline size_t vnr_model_outputs() {
  return 1;
}

inline void *vnr_model_input_ptr(int index) {
  return vnr_model_input(index)->data.data;
}
size_t vnr_model_input_size(int index);
inline int vnr_model_input_dims_len(int index) {
  return vnr_model_input(index)->dims->data[0];
}
inline int *vnr_model_input_dims(int index) {
  return &vnr_model_input(index)->dims->data[1];
}

inline void *vnr_model_output_ptr(int index) {
  return vnr_model_output(index)->data.data;
}
size_t vnr_model_output_size(int index);
inline int vnr_model_output_dims_len(int index) {
  return vnr_model_output(index)->dims->data[0];
}
inline int *vnr_model_output_dims(int index) {
  return &vnr_model_output(index)->dims->data[1];
}
// Only returns valid value if input is quantized
inline int32_t vnr_model_input_zeropoint(int index) {
  return vnr_model_input(index)->params.zero_point;
}
// Only returns valid value if input is quantized
inline float vnr_model_input_scale(int index) {
  return vnr_model_input(index)->params.scale;
}
// Only returns valid value if output is quantized
inline int32_t vnr_model_output_zeropoint(int index) {
  return vnr_model_output(index)->params.zero_point;
}
// Only returns valid value if output is quantized
inline float vnr_model_output_scale(int index) {
  return vnr_model_output(index)->params.scale;
}

// Sets up the model part of ioserver to communicate 
// with this model from host.
// Requires that ioserver() has been setup and running.
// This is an infinite loop and does not exit.
TfLiteStatus model_ioserver(unsigned io_channel);

#endif
