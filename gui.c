#include "gui.h"

#include "common.h"
#include "efi.h"
#include "graphics.h"

void gui(void) {
  struct RECT r = {10, 10, 20, 20};
  ST->ConOut->ClearScreen(ST->ConOut);
  draw_rect(r, white);
  while (TRUE) {}
}
