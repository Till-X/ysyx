#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

size_t strlen(const char *s) {
  assert(s!=NULL);
  size_t len = 0;
  while(*s++ != '\0'){
    len++;
  }
  return len;
}

char *strcpy(char *dst, const char *src) {
  assert(dst != NULL && src != NULL);
  char* ret = dst;
  for(;*src != '\0'; src++, dst++){
    *dst = *src;
  }
  *dst = '\0';
  return ret;
  //panic("Not implemented");
}

char *strncpy(char *dst, const char *src, size_t n) {
  assert(dst != NULL && src != NULL);
  char* ret = dst;
  for(int i=0; i < n; i++){
    *(dst+i) = *(src+i);
  }
  *(dst+n) = '\0';
  return ret;
  //panic("Not implemented");
}

char *strcat(char *dst, const char *src) {
  char* ret = dst;
  while (*dst != '\0') {dst++;}
  strcpy(dst,src);
  return ret;
}

int strcmp(const char *s1, const char *s2) {
  while(*s1 == *s2){
    if(*s1 == '\0'){
      return 0;
    }
    s1++;
    s2++;
  }
  return *s1 - *s2; //需要检验，暂未测试
  //panic("Not implemented");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  int ret = 0;
  for(int i=0;i<n;i++){
    ret = *(s1+i) - *(s2+i);
    if(ret!=0) break;
  }
  return ret;
  //panic("Not implemented");
}

void *memset(void *s, int c, size_t n) {
  unsigned char *p = s;
  for(size_t i=0;i<n;i++){
    *(p+i) = c;
  }
  return s;
  //panic("Not implemented");
}

void *memmove(void *dst, const void *src, size_t n) {
// this function can be uesd for overlapping areas.
  if (dst <= src) {
    // ----|dst----------|src---------|----------
    char *pdst = (char *) dst;
    char *psrc = (char *) src;
    for(size_t i=0; i<n; i++){
      *pdst++ = *psrc++;
    }
  } 
  else {
    // ----|src----------|dst---------|----------
    char *pdst = (char *) dst + n;
    char *psrc = (char *) src + n;
    for(size_t i=0; i<n; i++){
      *--pdst = *--psrc;
    }
  }
  return dst; 
  //panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
// this function can not be uesd for overlapping areas!
  char *pout = (char *) out;
  const char *pin = (char *) in;
  for(size_t i=0; i<n; i++){
    *pout++ = *pin++;
  }
  return out;
  //panic("Not implemented");
}

int memcmp(const void *s1, const void *s2, size_t n) {
  int ret = 0;
  const unsigned char *p1 = s1;
  const unsigned char *p2 = s2;
  for(int i=0; i<n ;i++){
    ret = *(p1+i) - *(p2+i);
    if(ret!=0)
      break;
  }
  return ret;
  //panic("Not implemented");
}

#endif
