.PHONY: run clean

%.o: %.c
	clang -target x86_64-pc-win32-coff \
		-mno-red-zone -fno-stack-protector -fshort-wchar -nostdinc -nostdlib -fno-builtin -Wall -o $@ -c $<

main.efi: main.o efi.o common.o shell.o
	lld-link /subsystem:efi_application /entry:efi_main /out:$@ $+
	rm *.o

run:
	./qemu.sh

clean:
	rm -f main.efi *.o
