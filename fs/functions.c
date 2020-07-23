

uint8_t f_cd( struct inode* i){ int __i;
	scanf("%s",&_jeff);
	__i=0; 
	if (!(strncmp(_jeff,"..",2))) {
		__r=i->parent;
		return 0;
	} else if (!(strncmp(_jeff,"~",1))){
		__r=&root;
		return 0;
	} else {
		while(__i<i->num)  {
			if (!(strcmp(_jeff,i->inodes[__i].name))) {
				P("changed to %s",_jeff);
				__r=&(i->inodes[__i]);
				return 0;
			}
			__i++;
		}
	}
	P("%s not found",_jeff);
	return -1;
};

uint8_t f_mkdir( struct inode* i){
	int __i;
	scanf("%s",&_jeff);
	__i=0;
	while(__i<i->num)  {
		if (!(strcmp(_jeff,i->inodes[__i].name))) {
			P("%s already exists sorry",_jeff);
			return 0;
		}
		__i++;
	}

	if (!i->alloted) {
	       	i->inodes = (struct inode*) malloc(sizeof(struct inode)); i->alloted=1; 
	} else 	i->inodes = (struct inode*)realloc(i->inodes,sizeof(struct inode) * (i->num+1));
	struct inode* new = &i->inodes[i->num];
	strcpy(i->inodes[i->num].name,_jeff);
	new->type   =DIR;
	new->num    =0;
	new->parent =i;
	P("%s:%d/%s directory made",i->name,i->num,i->inodes[i->num].name);	
	i->num++;
	return 0;
};

uint8_t f_cat( struct inode* i){
	int __i;
	scanf("%s",&_jeff);
	__i=0;
	while(__i<i->num)  {
		if (!(strcmp(_jeff,i->inodes[__i].name))) {
			if (i->inodes[__i].type == FYL) {
				P("%.*s",i->inodes[__i].end-i->inodes[__i].start,fs.buf+i->inodes[__i].start);
			} else {
	  			P("%s is a directory LOL ",_jeff);
			}
			return 0;
		}
		__i++;
	}

	if (!i->alloted) {
	       	i->inodes = (struct inode*) malloc(sizeof(struct inode)); i->alloted=1; 
	} else 	i->inodes = (struct inode*)realloc(i->inodes,sizeof(struct inode) * (i->num+1));
	struct inode* new = &i->inodes[i->num];
	strcpy(new->name,_jeff);
	new->type   =FYL;
	new->parent =i;
	new->start  = fs.ubound;
	scanf("%[^\n]",&_jeff);
	strcpy(fs.buf+fs.ubound, _jeff);
	fs.ubound += strlen(_jeff);
	new->end   = fs.ubound;
	i->num++;
	P("%s:%d/%s file made",i->name,i->num,new->name);
	return 0;
};

uint8_t f_exit( struct inode* i){
	if (root.alloted) free(root.inodes);
	exit(EXIT_SUCCESS);
	return 0;
}

uint8_t f_all( struct inode* i){
	int __i=-1;
	while(++__i<i->num)   {
		P("%s",i->inodes[__i].name);
		if (i->inodes[__i].type==DIR) 
			f_all(&(i->inodes[__i])); 
	}

	return 0;
}

uint8_t f_ls(struct inode* i){
	int __i=-1;
	P("in %s:%d",i->name,i->num);
	while(++__i<i->num)  {
		P("%s\t%c",i->inodes[__i].name,"fd"[i->inodes[__i].type]);
	}

}

uint8_t t_find( struct inode* i, char* cur) {
	int __i;
	__i=0;
	while(__i<i->num)  {
		if (!(strcmp(_jeff,i->inodes[__i].name))) {
			sprintf(_pwd,"%s/%s",_pwd,_jeff);
			P("%s\33[1000C%c",_pwd,"fd"[i->inodes[__i].type]);
		}  
		if (i->inodes[__i].type==DIR){
			sprintf(_pwd,"%s/%s",cur,i->inodes[__i].name);
			t_find(&(i->inodes[__i]),_pwd);
		}
		__i++;
	}
	return 0;
}

uint8_t f_find(struct inode* i){
	scanf("%s",&_jeff);
	t_find(i,".");
}

struct {
	char* name;
	uint8_t ( *func)( struct inode*);
}F[]={
	{ "cd" ,    f_cd     },
	{ "mkdir" , f_mkdir  },
	{ "cat" ,   f_cat    },
	{ "exit" ,  f_exit   },
	{ "find" ,  f_find   },
	{ "ls"   ,  f_ls     },
	{ "all"  ,  f_all    },
};
