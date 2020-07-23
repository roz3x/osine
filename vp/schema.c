
#define FUNC_EXIT   0
#define FUNC_SET    1
#define FUNC_PRINT  2
#define FUNC_XCMP   3
#define FUNC_JMP    4
#define FUNC_MOV    5

typedef unsigned char u8 ;

struct RAM  {
	u8 storage[0x100];
	u8 ins[0x100];
	int ip;
	u8 regs[10];
	u8 stack[0x100];
	u8 sp;
};

typedef struct RAM RAM;
