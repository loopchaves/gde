# gramcode - text editor for gde

#history:
#2019 - Created by Fred Nora.



VERSION = 0
PATCHLEVEL = 0
SUBLEVEL = 0
EXTRAVERSION =
#NAME = gramcode

#todo:
#We need to simplify these flags

CFLAGS = -m32 \
	--std=gnu89 \
	-nodefaultlibs \
	-nostdinc \
	-nostdlib \
	-static \
	-fgnu89-inline \
	-ffreestanding \
	-fno-builtin \
	-fno-pie \
	-no-pie \
	-fno-stack-protector \
	-s

#	-fleading-underscore \
#	-fno-stack-protector \
#	-s



LIBC    = ../../lib/gdelibs/libc02/include/
LIBCOBJ = ../../lib/gdelibs/libc02/obj

API01   = ../../lib/gdelibs/api01/include/
APIOBJ  = ../../lib/gdelibs/api01/obj

	##
	## Objects
	##

myObjects = crt0.o\
main.o \
ctype.o \
stdlib.o \
stdio.o \
string.o \
unistd.o \
api.o \
status.o \
stubs.o    




.PHONY: all all-c gramcode-link finalize clean

all: main.o all-c gramcode-link finalize clean
	@echo "Ok?"

main.o:
	gcc  -c  crt0.c    $(CFLAGS) -I $(LIBC) -I $(API01) -o crt0.o
	gcc  -c  main.c    $(CFLAGS) -I $(LIBC) -I $(API01) -o main.o
	gcc  -c  status.c  $(CFLAGS) -I $(LIBC) -I $(API01) -o status.o
	
all-c:

	cp $(APIOBJ)/api.o      .
	
	cp $(LIBCOBJ)/ctype.o   .
	cp $(LIBCOBJ)/stdio.o   .
	cp $(LIBCOBJ)/stdlib.o  .	
	cp $(LIBCOBJ)/string.o  .
	cp $(LIBCOBJ)/time.o    .
	cp $(LIBCOBJ)/unistd.o  .
	
	cp $(LIBCOBJ)/stubs.o   .
	


gramcode-link:
	ld -m elf_i386 -T link.ld -o GRAMCODE.BIN $(myObjects) -Map app_map.s

finalize:
	cp GRAMCODE.BIN  ../../bin

clean:
	-rm *.o
	-rm GRAMCODE.BIN 
	
	
