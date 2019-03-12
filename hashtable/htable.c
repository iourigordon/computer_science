#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "htable.h"

struct _htable {
	int** hkeys;
	int   size;
    int   bucket_size;
};

int create_htable(int hsize, int bsize, htable_ptr* tbl){
    int i,j;
	*tbl = (htable_ptr)malloc(sizeof(struct _htable));
	if (!*tbl)
		return 1;

	(*tbl)->hkeys = (int**)malloc(sizeof(int*)*hsize);
    if (!((*tbl)->hkeys)) {
        free(*tbl);
        return 1;
    } 

    memset((*tbl)->hkeys,0,sizeof(int*)*hsize); 
	for (i=0;i<hsize;i++){
		(*tbl)->hkeys[i] = (int*)malloc(sizeof(int)*bsize);
        memset((*tbl)->hkeys[i],0,sizeof(int)*bsize);
        if (!(*tbl)->hkeys[i]) {
            for (j=i;j>=0;j--) {
                free((*tbl)->hkeys[i]);
            } 
            free(*(*tbl)->hkeys);
            free(*tbl);
            return 1;
        }
	}

    (*tbl)->size = hsize;
    (*tbl)->bucket_size = bsize;
	return 0;
}

int delete_htable(htable_ptr* tbl) {
    int i;

    if (!(*tbl))
        return 1;

    for(i=0;i<(*tbl)->size;i++) {
        free((*tbl)->hkeys[i]);
    }

    free((*tbl)->hkeys);
    free(*tbl);
    *tbl=NULL;
    return 0;
}

static int hash_key(const char* key, int size) {
    int i;
    uint32_t hash_val;

    hash_val=0;
    for (int i=0;i<strlen(key);i++) {
        hash_val+=key[i];
        hash_val<<8;
    }

    return hash_val%size;
}

int insert(const char* key, int val, htable_ptr tbl){
    int i;
    int idx;

    if (!tbl)
        return 1;

    idx = hash_key(key,tbl->size);
    for (i=0;i<tbl->bucket_size;i++) {
        if (tbl->hkeys[idx][i]==0) {
            tbl->hkeys[idx][i]=val; 
            return 0;
        }
    }    

	return 1;
}

int delete_val(const char* key, int val, htable_ptr tbl){
    int i;
    int idx;

    if (!tbl)
        return 1;

    idx = hash_key(key,tbl->size);
    for (i=0;i<tbl->bucket_size;i++) {
        if (tbl->hkeys[idx][i]==val) {
            tbl->hkeys[idx][i]=0; 
            return 0;
        }
    }    

	return 1;
}

int delete_key(const char* key, htable_ptr tbl){
    int i;
    int idx;

    if (!tbl)
        return 1;

    idx = hash_key(key,tbl->size);
    memset(tbl->hkeys[idx],0,sizeof(int)*tbl->bucket_size);

	return 0;
}

int* search(const char* key, int* bsize, htable_ptr tbl) {
    int i;
    int idx;

    if (!tbl)
        return NULL;

    idx = hash_key(key,tbl->size);
    *bsize = tbl->bucket_size;
	return tbl->hkeys[idx];
}

int get_size(htable_ptr tbl){
    if (!tbl)
        return -1;
	return tbl->size;
}

void print_htable(htable_ptr tbl){
    int i,j;

    if (!tbl)
        return;

    for (i=0;i<tbl->size;i++) {
        for (j=0;j<tbl->bucket_size;j++) {
            printf("%d ",tbl->hkeys[i][j]);
        }
        printf("\n");
    }
}
