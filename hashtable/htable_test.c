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

    if (insert(KEY_3,VAL_3,tst_table)) {
        printf("Failed to insert key %s: val %d\n",KEY_3,VAL_3);
    }

    print_htable(tst_table);

    if (delete_htable(&tst_table))
        printf("Failed to delete hash table\n");
    
    printf("Exiting ...\n");
	return 0;
}
