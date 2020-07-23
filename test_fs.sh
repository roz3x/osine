filename="input"
touch $filename
num=50
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
echo "cd ~" >> $filename
echo "find $n" >> $filename
cat ./input | ./bin
rm bin input
