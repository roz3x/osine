echo -ne "running test for file count\n"
source ./gen_random_lines.sh | source ./line_count.sh 
gcc -o bin  --std=c99 fs/main.c 
echo  $PWD
echo running test for fs
source ./test_fs.sh
echo running test for vp
cd vp
source ./run.sh
cd ..

