#
# Makefile for the Hydra/Inferno-kernel.
#
# Note! Dependencies are done automagically by 'make dep', which also 
# removes any old dependencies. DON'T put your own dependencies here
# unless it's something special (ie not a .c file).
#

AR	=gar
AS	=gas
LD	=gld
LDFLAGS	=-s -x
CC	=gcc
CFLAGS	=-Wall -O -fstrength-reduce -fomit-frame-pointer -fcombine-regs \
	-finline-functions -mstring-insns -nostdinc -I../include
CPP	=gcc -E -nostdinc -I../include

.c.s:
	$(CC) $(CFLAGS) \
	-S -o $*.s $<
.s.o:
	$(AS) -c -o $*.o $<
.c.o:
	$(CC) $(CFLAGS) \
	-c -o $*.o $<

OBJS  = sched.o system_call.o traps.o asm.o fork.o \
	panic.o printk.o vsprintf.o tty_io.o console.o \
	keyboard.o rs_io.o hd.o sys.o exit.o serial.o \
	mktime.o

kernel.o: $(OBJS)
	$(LD) -r -o kernel.o $(OBJS)
	sync

clean:
	rm -f core *.o *.a tmp_make
	for i in *.c;do rm -f `basename $$i .c`.s;done
dep:
	sed '/\#\#\# Dependencies/q' < Makefile > tmp_make
	(for i in *.c;do echo -n `echo $$i | sed 's,\.c,\.s,'`" "; \
		$(CPP) -M $$i;done) >> tmp_make
	cp tmp_make Makefile

### Dependencies
console.s console.o : console.c ../include/inferno/sched.h ../include/inferno/head.h \
  ../include/inferno/fs.h ../include/sys/types.h ../include/inferno/mm.h \
  ../include/inferno/tty.h ../include/termios.h ../include/asm/io.h \
  ../include/asm/system.h 
exit.s exit.o : exit.c ../include/errno.h ../include/signal.h \
  ../include/sys/types.h ../include/sys/wait.h ../include/inferno/sched.h \
  ../include/inferno/head.h ../include/inferno/fs.h ../include/inferno/mm.h \
  ../include/inferno/kernel.h ../include/inferno/tty.h ../include/termios.h \
  ../include/asm/segment.h 
fork.s fork.o : fork.c ../include/errno.h ../include/inferno/sched.h \
  ../include/inferno/head.h ../include/inferno/fs.h ../include/sys/types.h \
  ../include/inferno/mm.h ../include/inferno/kernel.h ../include/asm/segment.h \
  ../include/asm/system.h 
hd.s hd.o : hd.c ../include/inferno/config.h ../include/inferno/sched.h \
  ../include/inferno/head.h ../include/inferno/fs.h ../include/sys/types.h \
  ../include/inferno/mm.h ../include/inferno/kernel.h ../include/inferno/hdreg.h \
  ../include/asm/system.h ../include/asm/io.h ../include/asm/segment.h 
mktime.s mktime.o : mktime.c ../include/time.h 
panic.s panic.o : panic.c ../include/inferno/kernel.h 
printk.s printk.o : printk.c ../include/stdarg.h ../include/stddef.h \
  ../include/inferno/kernel.h 
sched.s sched.o : sched.c ../include/inferno/sched.h ../include/inferno/head.h \
  ../include/inferno/fs.h ../include/sys/types.h ../include/inferno/mm.h \
  ../include/inferno/kernel.h ../include/signal.h ../include/inferno/sys.h \
  ../include/asm/system.h ../include/asm/io.h ../include/asm/segment.h 
serial.s serial.o : serial.c ../include/inferno/tty.h ../include/termios.h \
  ../include/inferno/sched.h ../include/inferno/head.h ../include/inferno/fs.h \
  ../include/sys/types.h ../include/inferno/mm.h ../include/asm/system.h \
  ../include/asm/io.h 
sys.s sys.o : sys.c ../include/errno.h ../include/inferno/sched.h \
  ../include/inferno/head.h ../include/inferno/fs.h ../include/sys/types.h \
  ../include/inferno/mm.h ../include/inferno/tty.h ../include/termios.h \
  ../include/inferno/kernel.h ../include/asm/segment.h ../include/sys/times.h \
  ../include/sys/utsname.h 
traps.s traps.o : traps.c ../include/string.h ../include/inferno/head.h \
  ../include/inferno/sched.h ../include/inferno/fs.h ../include/sys/types.h \
  ../include/inferno/mm.h ../include/inferno/kernel.h ../include/asm/system.h \
  ../include/asm/segment.h 
tty_io.s tty_io.o : tty_io.c ../include/ctype.h ../include/errno.h \
  ../include/signal.h ../include/sys/types.h ../include/inferno/sched.h \
  ../include/inferno/head.h ../include/inferno/fs.h ../include/inferno/mm.h \
  ../include/inferno/tty.h ../include/termios.h ../include/asm/segment.h \
  ../include/asm/system.h 
vsprintf.s vsprintf.o : vsprintf.c ../include/stdarg.h ../include/string.h 
