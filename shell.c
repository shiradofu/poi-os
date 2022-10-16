#include "shell.h"

#include "common.h"
#include "graphics.h"
#include "gui.h"

#define MAX_COMMAND_LENGTH 1024

void shell(void) {
  unsigned short command[MAX_COMMAND_LENGTH];
  struct RECT r = {10, 10, 100, 200};

  while (TRUE) {
    puts(L"poi-os >> ");

    if (gets(command, MAX_COMMAND_LENGTH) <= 0) {
      continue;
    }

    if (strcmp(L"hello", command) == 0) {
      puts(L"hello, UEFI!\r\n");
    } else if (strcmp(L"rect", command) == 0) {
      draw_rect(r, white);
    } else if (strcmp(L"gui", command) == 0) {
      gui();
    } else {
      puts(L"Command not found.\r\n");
    }
    puts(L"\r\n");
  }
}
