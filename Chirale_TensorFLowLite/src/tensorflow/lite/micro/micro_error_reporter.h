#ifndef TENSORFLOW_LITE_MICRO_MICRO_ERROR_REPORTER_H_
#define TENSORFLOW_LITE_MICRO_MICRO_ERROR_REPORTER_H_

#include <stdarg.h>
#include <stdio.h>

namespace tflite {

/**
 * Simple error reporter for TensorFlow Lite Micro on Arduino / ESP32.
 * Prints error messages to Serial.
 */
class MicroErrorReporter {
 public:
  MicroErrorReporter() {}

  // Basic print wrapper
  int Report(const char* format, va_list args) {
    char buf[128];
    vsnprintf(buf, sizeof(buf), format, args);
    Serial.println(buf);
    return 0;
  }

  // Variadic helper
  int Report(const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = Report(format, args);
    va_end(args);
    return ret;
  }
};

}  // namespace tflite

#endif  // TENSORFLOW_LITE_MICRO_MICRO_ERROR_REPORTER_H_
