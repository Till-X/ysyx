#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>


#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

/**
 * 数字转字符串
*/

static char index[] = "0123456789ABCDEF"; // 索引
char* itoa(int num, char* str, int radix) {
  unsigned unum;/*中间变量*/
  int i = 0, j, k;
  /*确定unum的值*/
  if (radix == 10 && num < 0)/*十进制负数*/
  {
    unum = (unsigned)-num;
    str[i++] = '-';
  }
  else unum = (unsigned)num;/*其他情况*/
  //转换
  do {
    str[i++] = index[unum % (unsigned)radix];
    unum /= radix;
  } while (unum);
  str[i] = '\0';

  // 逆序，若为负数，第一字符为 -
  if (str[0] == '-')
    k = 1;
  else
    k = 0;
  // 头尾交换
  for (j = k;j <= (i - 1) / 2;j++) {
    char temp;
    temp = str[j];
    str[j] = str[i - 1 + k - j];
    str[i - 1 + k - j] = temp;
  }
  return str;
}

int vsprintf(char *out, const char *fmt, va_list args) {
  char* start;
  char str_temp[256];

  for(start = out; *fmt != '\0'; fmt++){
    if(*fmt != '%'){
      *out++ = *fmt;
      continue;
    }
    fmt++;

    switch(*fmt)
    {
      case 's':
        char *s = va_arg(args, char*);
        strcpy(out, s);
        out += strlen(out);
        break;
      case 'd': 
        int num_d = va_arg(args, int);
        char* num_d2str = itoa(num_d, (char*)&str_temp, 10);
        strcpy(out, num_d2str);
        out += strlen(num_d2str);
        break;
      default:break;
    }
  }
  *out = '\0';
  return out - start;
}


int printf(const char *fmt, ...){
  va_list args;
  int i;
  char buf[256];

  va_start(args, fmt);
  i = vsprintf(buf, fmt, args);
  for(int a=0; a <= i; a++){
    putch(buf[a]);
  }
  return i;
}

int sprintf(char *out, const char *fmt, ...) {
  va_list args;
  int i;

  va_start(args, fmt);
  i = vsprintf(out, fmt, args);
  for(int a=0; a <= i; a++){
    putch(out[a]);
  }
  return i;
}

// int printf(const char *fmt, ...){
//   char out[100]; //最多输出100个字节
//   va_list ap;
//   va_start(ap, fmt);
//   int i = 0;
//   while(*fmt != '\0'){
//     if(*fmt == '%'){
//       fmt++;
//       switch(*fmt){
//         case 's': {
//           char *string = va_arg(ap, char *);
//           while(*string != '\0'){
//             out[i] = *string;
//             i++;
//             string++;
//           }
//           break;
//         }
//         case 'd': {
//           int d = va_arg(ap, int);
//           int j = 0;
//           char dd[30];
//           while(d / 10){
//             dd[j] = (char)(d % 10 + '0');
//             j++;
//             d = d / 10;
//           }
//           dd[j] = d + '0';
//           for(; j >= 0; j--){
//             out[i] = dd[j];
//             i++;
//           }
//           break;
//         }
//         default: va_end(ap); return -1;
//       }
//     }
//     else{
//       out[i] = *fmt;
//       i++;
//     }
//     fmt++;
//   }
//   va_end(ap);
//   out[i] = '\0';
//   for(i = 0; out[i] != '\0'; i++){
//     putch(out[i]);
//   }
//   return i;
// }

// int vsprintf(char *out, const char *fmt, va_list ap) {
//   panic("Not implemented");
// }

// int sprintf(char *out, const char *fmt, ...) {
//   va_list ap;
//   va_start(ap, fmt);
//   int i = 0;
//   while(*fmt != '\0'){
//     if(*fmt == '%'){
//       fmt++;
//       switch(*fmt){
//         case 's': {
//           char *string = va_arg(ap, char *);
//           while(*string != '\0'){
//             out[i] = *string;
//             i++;
//             string++;
//           }
//           break;
//         }
//         case 'd': {
//           int d = va_arg(ap, int);
//           int j = 0;
//           char dd[30];
//           while(d / 10){
//             dd[j] = (char)(d % 10 + '0');
//             j++;
//             d = d / 10;
//           }
//           dd[j] = d + '0';
//           for(; j >= 0; j--){
//             out[i] = dd[j];
//             i++;
//           }
//           break;
//         }
//         default: va_end(ap); return -1;
//       }
//     }
//     else{
//       out[i] = *fmt;
//       i++;
//     }
//     fmt++;
//   }
//   va_end(ap);
//   out[i] = '\0';
//   return i;
// }

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}
#endif
