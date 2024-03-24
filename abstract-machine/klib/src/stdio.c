#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

int printf(const char *fmt, ...){
  char out[100]; //最多输出100个字节
  va_list ap;
  va_start(ap, fmt);
  int i = 0;
  while(*fmt != '\0'){
    if(*fmt == '%'){
      fmt++;
      switch(*fmt){
        case 's': {
          char *string = va_arg(ap, char *);
          while(*string != '\0'){
            out[i] = *string;
            i++;
            string++;
          }
          break;
        }
        case 'd': {
          int d = va_arg(ap, int);
          int j = 0;
          char dd[30];
          while(d / 10){
            dd[j] = (char)(d % 10 + '0');
            j++;
            d = d / 10;
          }
          dd[j] = d + '0';
          for(; j >= 0; j--){
            out[i] = dd[j];
            i++;
          }
          break;
        }
        default: va_end(ap); return -1;
      }
    }
    else{
      out[i] = *fmt;
      i++;
    }
    fmt++;
  }
  va_end(ap);
  out[i] = '\0';
  for(i = 0; out[i] != '\0'; i++){
    putch(out[i]);
  }
  return i;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {
  va_list ap;
  va_start(ap, fmt);
  int i = 0;
  while(*fmt != '\0'){
    if(*fmt == '%'){
      fmt++;
      switch(*fmt){
        case 's': {
          char *string = va_arg(ap, char *);
          while(*string != '\0'){
            out[i] = *string;
            i++;
            string++;
          }
          break;
        }
        case 'd': {
          int d = va_arg(ap, int);
          int j = 0;
          char dd[30];
          while(d / 10){
            dd[j] = (char)(d % 10 + '0');
            j++;
            d = d / 10;
          }
          dd[j] = d + '0';
          for(; j >= 0; j--){
            out[i] = dd[j];
            i++;
          }
          break;
        }
        default: va_end(ap); return -1;
      }
    }
    else{
      out[i] = *fmt;
      i++;
    }
    fmt++;
  }
  va_end(ap);
  out[i] = '\0';
  return i;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}
#endif
