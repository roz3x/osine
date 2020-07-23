num=500
for  ((i=0;i<$num;i++))
do
	echo -ne "$(cat /dev/random | head -c5 | xxd -p -l 50 ) \n"
done

