#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 50
#define EMPTY_NODE -1
#define LAZY_DELETED -2
struct hashash_t{
 int tableSize;
 int* intArray;
};
typedef struct hashash_t *hashPtr;
hashPtr HashInitialize();
unsigned int Hash(int key, int tableSize);
int HashInsert(hashPtr hash, int value);
int HashFind(hashPtr hash, int value);
int HashDelete(hashPtr hash, int value);
void PrintHash(hashPtr hash, int tableSize);
int ResolverFun(int i);
unsigned int ComputeHash(int key, int tableSize);