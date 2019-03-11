#include "htable.h"

typedef struct _htable {
	int** hkeys;
	int   size;
} htable;

int create_hash_table(int hsize, int bsize, htable** tbl){
#if 0
	*tbl = (htable*)malloc(sizeof(struct _htable));
	if (!*tbl)
		return 1;

	*tbl->hkeys = (int*)malloc(sizeof(int)
	for (int i=0;i<hsize;i++){
		*tbl[i] = (
	}
#endif
	return 0;
}

int insert(char* key, int val){
	return 0;
}

int delete_val(char* key, int val){
	return 0;
}

int delete_key(char* key){
	return 0;
}

int search(char* key){
	return 0;
}

int get_size(){
	return 0;
}


