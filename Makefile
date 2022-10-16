.DEFAULT_GOAL = all

.PHONY: run clean

%.o: %.c
	clang -target x86_64-pc-win32-coff \
		-mno-red-zone -fno-stack-protector -fshort-wchar -nostdinc -nostdlib -fno-builtin -Wall -o $@ -c $<

main.efi: main.o efi.o common.o shell.o graphics.o gui.o
	lld-link /subsystem:efi_application /entry:efi_main /out:$@ $+

run:
	./qemu.sh

all: main.efi run

clean:
	rm -f main.efi *.o
