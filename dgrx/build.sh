#!/bin/bash
DIMG="dgrx.dsk"
BAS=(demo)
ASM=(dgrx)

build_bas() {
	echo "Building $1.abas..."
	a2kit verify -t atxt < $1.abas
	a2kit delete -d ${DIMG} -f $1
	a2kit tokenize -t atxt -a 2049 < $1.abas | a2kit put -d ${DIMG} -t atok -f $1
}

build_asm() {
	echo "Building $1.s..."
	ca65 -o $1.o -l $1.lst $1.ca65
  ld65 -C a2bin.cfg -o $1 $1.o
  #Merlin32 -V "" $1.s
	a2kit delete -d ${DIMG} -f $1
	a2kit put -d ${DIMG} -f $1 -t bin -a 6000 < $1
}

for f in "${BAS[@]}"; do
	build_bas ${f}
done

for f in "${ASM[@]}"; do
	build_asm ${f}
done

a2kit catalog -d $DIMG
#sa2 --d1 $DIMG
