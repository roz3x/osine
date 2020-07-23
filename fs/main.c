#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "schema.h"
#include "functions.c"

int main(int argc , char* argv[], char* env[]) {
	struct inode* r = &root;
	__r=r;
	int _size = sizeof F / sizeof F[0] ,__i;
	while (1) {
		if (argc > 1) printf("$> ");
		if (scanf("%s",&_jeff)==-1)  return 0;
		for (__i=0;__i<_size;__i++)
			if (!(strcmp(F[__i].name,_jeff))){ 
				F[__i].func(__r);
			       	break; 
			}
	}
	return 0;
}
