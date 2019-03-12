#ifndef __htable_ptr_h__
#define __htable_ptr_h__

typedef struct _htable* htable_ptr;

extern int create_htable(int hsize, int bsize, htable_ptr* tbl);
extern int delete_htable(htable_ptr* tbl);
extern int insert(const char* key, int val, htable_ptr tbl);
extern int delete_val(const char* key, int val, htable_ptr tbl);
extern int delete_key(const char* key, htable_ptr tbl);
extern int get_size(htable_ptr tbl);

extern int* search(const char* key, int* bsize, htable_ptr tbl);
extern void print_htable(htable_ptr tbl);

#endif
