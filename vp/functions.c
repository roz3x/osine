
void f_mov( RAM* r ) {
	u8 src,val;
	src = r->ins[++r->ip];
	val = r->ins[++r->ip];
	printf("mov command REGS[%d]:%d\n",src,val);
	r->regs[src] = val;
	return;
}

void f_exit(RAM* r ) {
	printf("exit command");
	exit(EXIT_SUCCESS);
}

void f_set(RAM* r ) {
	u8 src,val;
	src = r->ins[++r->ip];
	val = r->ins[++r->ip];
	printf("set command DATA[%d]:%d\n",src,val);
	r->storage[src] = val;
	return;
}

void f_print(RAM* r) {
	int i = 0;
	printf("print command first %d\n",r->regs[7]);
	for (;i<=r->regs[7];i++) printf("storage[%d]:%d regs[%d]:%d\n",i,r->storage[i],i,r->regs[i]);
	return;
	
}

void f_xcmp(RAM* r){
	printf("xcmp command regs[1]:%d regs[2]:%d\n",r->regs[1],r->regs[2]);
	if (r->regs[1]<r->regs[2])
		r->regs[4] = 0;
	else if (r->storage[(r->regs[1]+r->regs[2])/2] == r->regs[3]) 
		r->regs[4] = 1;
	else if (r->storage[(r->regs[1]+r->regs[2])/2]  > r->regs[3])  {
		r->regs[4] = 2;
		printf("stack[%d]:%d\n",r->sp,r->ip);
		r->stack[r->sp++] = r->ip;
	} else  {
		printf("stack[%d]:%d\n",r->sp,r->ip);
		r->stack[r->sp++] = r->ip;
		r->regs[4] = 3;
	}
	return;

}

void f_jmp(RAM* r) {
	u8 res  = r->regs[4];
	u8 val ;
	switch (res) {
		case 1:
			printf("found @%d\n",(r->regs[1]+r->regs[2])/2);
			return;
		case 2:
			r->regs[1] = (r->regs[1]+r->regs[2])/ 2 - 1;
			val = r->stack[--r->sp];
			printf("jmp back %d\n",val);
			r->ip = val-1;
			break;
		case 3:
			r->regs[2] = (r->regs[1]+r->regs[2])/ 2 + 1;
			val = r->stack[--r->sp];
			printf("jmp back %d\n",val);
			r->ip = val-1;
			break;
		case 0:
			printf("not found\n");
			break;
	}
	return;
}

static void (*F[0xff])(RAM* r ) =  {
	[FUNC_SET]    = f_set,
	[FUNC_EXIT]   = f_exit,
	[FUNC_PRINT]  = f_print,
	[FUNC_XCMP]   = f_xcmp,
	[FUNC_JMP]    = f_jmp,
	[FUNC_MOV]    = f_mov,
};
