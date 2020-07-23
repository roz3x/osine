
char _jeff[0xff];
char _pwd[0xff];
int __i;
enum { FYL , DIR };

#define P(...) fprintf(stdout,__VA_ARGS__);fprintf(stdout,"\n")
#define S(...) fscanf(stdin,__VA_ARGS__);
#define L(...) fprintf(stderr,"[LOG] ");fprintf(stderr,__VA_ARGS__);fprintf(stderr,"\n")

#pragma pack(1)
struct inode {
	int id;
	char name[0x2f];
	union {
		struct {
			uint64_t start;
			uint64_t end;
		};
		struct {
			uint8_t num;	
			struct inode *inodes;
			struct inode *parent;
			uint8_t alloted;
		};
	};
	int type;
}*__r;

struct inode root = {
	.name = "root",
	.id   = 0,
	.type = DIR,
	.num  = 0,
	.parent = &root,
};

struct {
	int   count;
	uint8_t buf[0xffff];
	int   ubound;
} fs =  {0,{},0};
