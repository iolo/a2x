#!/bin/sh
set -e
n=$(basename $1 .s)
ca65 --debug-info --listing $n.lst --target apple2 -o $n.o $n.s
ld65 -C apple2-asm.cfg -u __EXEHDR__ apple2.lib --start-addr 0x6000 -o $n.apple2 $n.o
test -f a2x.po || ac.sh -pro140 a2x.po a2x
ac.sh -d a2x.po $n
ac.sh -l a2x.po
ac.sh -as a2x.po $n < $n.apple2
ac.sh -l a2x.po
mii_emu_gl -d 6:2:a2x.po
