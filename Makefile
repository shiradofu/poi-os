VOLUME=volume

all: hello.efi

%.o: %.c
	clang -target x86_64-pc-win32-coff \
		-mno-red-zone -fno-stack-protector -fshort-wchar -nostdinc -nostdlib -fno-builtin -Wall -o $@ -c $<

main.efi: main.o efi.o common.o shell.o
	lld-link /subsystem:efi_application /entry:efi_main /out:$@ $+
	rm *.o

.PHONY: copy
copy:
	[ -f main.efi ] && cp -f main.efi /Volumes/$(VOLUME)/EFI/BOOT/BOOTX64.EFI
	diskutil unmount /Volumes/volume/

clean:
	rm -f main.efi *.o
