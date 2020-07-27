#include <stdio.h>

char buff[0xff];
size_t len;
int main() {
	int line_count  = 0;
	while (getline(&buff,&len,stdin)>=1) line_count++;
	printf("lines :%d \n",line_count);
	
}
