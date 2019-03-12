#include <stdio.h>
#include "htable.h"

#define HASH_KEYS_SIZE 10
#define BUCKET_SIZE 10

#define KEY_1 "hello"
#define KEY_2 "test"
#define KEY_3 "bugz"

#define VAL_1 2
#define VAL_2 5
#define VAL_3 7

int main(int argc, char* argv[]) {
    int  bucket_size,i;
    int* bucket;
    htable_ptr tst_table;

    if (create_htable(HASH_KEYS_SIZE,BUCKET_SIZE,&tst_table)) {
        printf("Failed to create hash table\n");
        return 0;
    }
	printf("Hash Table Created\n");

    if (insert(KEY_1,VAL_1,tst_table)) {
        printf("Failed to insert key %s: val %d\n",KEY_1,VAL_1);
    }

    if (insert(KEY_2,VAL_2,tst_table)) {
        printf("Failed to insert key %s: val %d\n",KEY_2,VAL_2);
    }

    if (insert(KEY_2,VAL_2+1,tst_table)) {
        printf("Failed to insert key %s: val %d\n",KEY_2,VAL_2);
    }


    if (insert(KEY_3,VAL_3,tst_table)) {
        printf("Failed to insert key %s: val %d\n",KEY_3,VAL_3);
    }

    printf("hash_table size = %d\n",get_size(tst_table));

    print_htable(tst_table);

    bucket = search(KEY_2,&bucket_size,tst_table);
    printf("Bucket for %s\n",KEY_2);
    for (i=0;i<bucket_size;i++){
        printf("%d ",bucket[i]);
    }
    printf("\n");

    if(delete_val(KEY_2,VAL_2,tst_table))
        printf("Failed to delete val %d of key %s\n",VAL_2,KEY_2); 

    printf("After deletion of val %d of key %s\n",VAL_2,KEY_2);
    print_htable(tst_table);

    printf("Deleting Bucket of key %s\n",KEY_3);
    if (delete_key(KEY_3,tst_table))
        printf("Failed to delete key %s\n",KEY_3);

    printf("After deletion of %s key\n",KEY_3);
    print_htable(tst_table);

    if (delete_htable(&tst_table))
        printf("Failed to delete hash table\n");
    
    printf("Exiting ...\n");
	return 0;
}
