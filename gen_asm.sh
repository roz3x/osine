num=10
filename="input.asm"
touch $filename
idx=0
for ((i=0;i<$num;i++ )) 
do
	idx=$(($idx+ $RANDOM%15 ))
	echo -ne "SET $i  $idx\n" >> $filename
done
echo -ne "MOV 1 $num\n" >> $filename
echo -ne "MOV 7 $num\n" >> $filename
echo -ne "MOV 2 0\n" >> $filename
echo -ne "MOV 3 $RANDOM\n" >> $filename
echo -ne "PRINT\nXCMP\nJMP\nEXIT\n" >> $filename



