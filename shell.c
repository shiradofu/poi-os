#include "shell.h"
#include "common.h"

#define MAX_COMMAND_LENGTH 1024

void shell(void) {
  unsigned short command[MAX_COMMAND_LENGTH];

  while (TRUE) {
    puts(L"poi-os >> ");

    if (gets(command, MAX_COMMAND_LENGTH) <= 0) {
      continue;
    }

    if (strcmp(L"hello", command) == 0) {
      puts(L"hello, UEFI!\r\n");
    } else {
      puts(L"Command not found.\r\n");
    }
  }
}
