#include "efi.h"

#define MAX_STR_BUF 100

void putc(unsigned short c) {
  unsigned short str[2] = L" ";
  str[0] = c;
  ST->ConOut->OutputString(ST->ConOut, str);
}

void puts(unsigned short *s) { ST->ConOut->OutputString(ST->ConOut, s); }

unsigned short getc(void) {
  struct EFI_INPUT_KEY key;
  unsigned long long waitidx;

  ST->BootServices->WaitForEvent(1, &(ST->ConIn->WaitForKey), &waitidx);
  while (ST->ConIn->ReadKeyStroke(ST->ConIn, &key)) {}
  return key.UnicodeChar;
}

void puth(unsigned long long val, unsigned char num_digits) {
  int i;
  unsigned short hex_digit;
  unsigned short str[MAX_STR_BUF];

  for (i = num_digits - 1; i >= 0; i--) {
    hex_digit = (unsigned short)(val & 0x0f);
    if (hex_digit < 0xa) {
      str[i] = L'0' + hex_digit;
    } else {
      str[i] = L'A' + (hex_digit - 0xa);
    }
    val >>= 4;
  }

  str[num_digits] = L'\0';
  puts(str);
}

unsigned int gets(unsigned short *buf, unsigned int buf_size) {
  unsigned int i;
  unsigned short c;

  for (i = 0; i < buf_size - 1;) {
    c = getc();

    if (c == L'\b') {
      if (i > 0) {
        putc(c);
        i--;
      }
    } else if (c == L'\r') {
      putc(c);
      putc(L'\n');
      break;
    } else {
      putc(c);
      buf[i] = c;
      i++;
    }
  }

  buf[i] = L'\0';
  return i;
}

int strcmp(const unsigned short *s1, const unsigned short *s2) {
  char is_equal = 1;

  for (; (*s1 != L'\0') && (*s2 != L'\0'); s1++, s2++) {
    if (*s1 != *s2) {
      is_equal = 0;
      break;
    }
  }

  if (is_equal) {
    if (*s1 != L'\0') {
      return 1;
    } else if (*s2 != L'\0') {
      return -1;
    } else {
      return 0;
    }
  } else {
    return (int)(*s1 - *s2);
  }
}
