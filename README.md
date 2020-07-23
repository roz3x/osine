### project work of os

submitted by:
```
* ishant kumar     ( 185501 )
* vishal guleria   ( 185511 )
* shivang upadhyay ( 185515 ) 
```

#### task 1 
shell script for counting the number lines  from file and analysis . 
 
```sh
source ./gen_random_lines.sh | source ./line_count.sh
```

the  gen_random script generated random 5 character strings in hex using 
```sh
  echo -ne "$(cat /dev/random | head -c5 | xxd -p -l 50 ) \n"
```
and line_count script accepts input from stdin until EOF and stores them in array like 
```sh
while read  -r line;
do
        l+=($line)
done
```
and shows the output as 
```sh
echo total  ${#l[@]} lines
```

#### task 2 
analysis of 2 different programs 

program 1 : virtual processor which takes the assembly as input and executes it. 
```sh
cd vp && source ./run.sh
```
run script uses search and replace tool ro make make the source.asm into binary file. assembly code -> machine code
```sh
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
```
and compile the other files to use the machine code as input . 

program 2 : filesystem that takes general os commands like cd , mkdir , cat and executes them . 
```sh
source run.sh
```
for fs program it generates random files and directories , and eventually switches into them by 
```sh
for ((i=0;i<$num;i++))
do
	if (( $RANDOM > $RANDOM)) ; then
		n=$(cat /dev/random | head -c5 | xxd -p -l 50 )
		echo  -ne "mkdir $n \n"  >> $filename
		if (($RANDOM > 3 * $RANDOM)); then
			echo  -ne "cd $n \n"	  >> $filename
		fi
	else
		n=$(($RANDOM % 30))
		echo  -ne "cat $(cat /dev/random | head -c5 | xxd -p -l 50 ) $(cat /dev/random | head -c$( echo $n ) | xxd -p -l 50 )\n"  >> $filename
	fi
done
```

#### task 3 
simulating on linux machine 
```sh
source ./make.sh
```
this runs all the above code and prints out the log .
here is log of the above mentioned scripts [rickroll](https://github.com/roz3x/osine/runs/902234194?check_suite_focus=true)
