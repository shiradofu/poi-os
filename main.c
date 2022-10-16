#include "common.h"
#include "efi.h"
#include "shell.h"

void efi_main(void *ImageHandle __attribute__((unused)),
              struct EFI_SYSTEM_TABLE *SystemTable) {
  efi_init(SystemTable);
  ST->ConOut->ClearScreen(ST->ConOut);
  puts(L"Hello, UEFI!\r\n\n");
  puts(L"EFI_GRAPHICS_PIXEL_FORMAT: ");
  puth(GOP->Mode->Info->PixelFormat, 1);
  puts(L"\r\n\n");
  shell();
}
