
#history:
#2019 - Created by Fred Nora.

#todo:
#fazer um makefile pra compilar o shell
#obs: #bugbug tem que arrumas as coisas aqui.



VERSION = 0
PATCHLEVEL = 0
SUBLEVEL = 0
EXTRAVERSION =
#NAME = tascii

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


LIBC    = ../../../lib/gdelibs/libc01/include/
LIBCOBJ = ../../../lib/gdelibs/libc01/obj

API01   = ../../../lib/gdelibs/api01/include/
APIOBJ  = ../../../lib/gdelibs/api01/obj


	##
	## Objects
	##

myObjects = main.o \
ctype.o \
stdio.o \
stdlib.o \
string.o \
time.o \
api.o \
unistd.o  



.PHONY: all all-c tascii-link finalize clean

all: main.o all-c tascii-link finalize clean
	@echo "Ok?"

main.o:
	gcc  -c  main.c  $(CFLAGS) -I $(LIBC) -I $(API01) -o main.o

all-c:
	cp $(APIOBJ)/api.o      .
	
	cp $(LIBCOBJ)/ctype.o   .
	cp $(LIBCOBJ)/stdio.o .
	cp $(LIBCOBJ)/stdlib.o .
	cp $(LIBCOBJ)/string.o .
	cp $(LIBCOBJ)/time.o    .
	cp $(LIBCOBJ)/unistd.o  .


tascii-link:
	ld -m elf_i386 -T link.ld -o TASCII.BIN $(myObjects) -Map app_map.s

finalize:
	cp TASCII.BIN ../../../bin

clean:
	-rm *.o
	-rm TASCII.BIN 
	
	
