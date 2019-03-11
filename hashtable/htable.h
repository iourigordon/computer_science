#ifndef __htable_h__
#define __htable_h__

typedef struct _htable* htable_ptr;

extern int create_htable(int hsize, int bsize);
extern int insert(char* key, int val);
extern int delete_val(char* key, int val);
extern int delete_key(char* key);
extern int search(char* key);
extern int get_size();

#endif
