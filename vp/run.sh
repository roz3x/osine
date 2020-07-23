echo -ne 'uint8_t arr[] = { ' > ._a.c ; cat 'source.asm' | sed  -e 's/^#.*//g' \
	-e 's/MOV/5/g' \
	-e 's/SET/1/g' \
	-e 's/EXIT/0/g' \
	-e 's/PRINT/2/g' \
	-e 's/JMP/4/g' \
	-e 's/XCMP/3/g' \
	-e 's/\s/,/g' \
	-e '/^$/d' \
	-e 's/$/,/'  >> ._a.c
echo -ne '0 } ;'  >> ._a.c

gcc --std=c99 -o _b writer.c 
./_b asm.o
gcc --std=c99 -o bin main.c
./bin asm.o
rm _b ._a.c  asm.o bin
