
l=()
while read  -r line;
do
	l+=($line)
done
i=${#l[@]}
for ((y=0;y<$i;y++)) 
do
	echo $y: ${l[$y]}
done
echo total  ${#l[@]} lines 
