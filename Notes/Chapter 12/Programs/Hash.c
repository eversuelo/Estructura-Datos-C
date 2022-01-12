#include "Hash.h"
int ResolverFun(int i)
{
 return i;
}
unsigned int ComputeHash(int key, int tableSize)//division method
{
 unsigned int hashValue = 0;
 hashValue = key;
 return hashValue % tableSize;
}
hashPtr HashInitialize()
{
    hashPtr hash;
    hash = (hashPtr)malloc(sizeof(struct hashash_t));
    hash->tableSize = TABLE_SIZE;
    hash->intArray = (int *)malloc(hash->tableSize * sizeof(int));
    for (int i = 0; i < hash->tableSize; i++)
        hash->intArray[i] = EMPTY_NODE;
    return hash;
}
unsigned int Hash(int key, int tableSize) //division method
{
    unsigned int hashValue = 0;
    hashValue = key;
    return hashValue % tableSize;
}
int HashInsert(hashPtr hash, int value)
{
    int hashValue = ComputeHash(value, hash->tableSize);
    int i = 0;
    for (i = 0; i < hash->tableSize; i++)
    {
        if (hash->intArray[hashValue] == EMPTY_NODE || hash->intArray[hashValue] == LAZY_DELETED)
        {
            hash->intArray[hashValue] = value;
            return 1;
        }
        hashValue = hashValue + ResolverFun(i);
        hashValue = hashValue % hash->tableSize;
    }
    return -1;
}
int HashFind(hashPtr hash, int value)
{
    int hashValue = ComputeHash(value, hash->tableSize);
    for (int i = 0; i < hash->tableSize; i++)
    {
        if (hash->intArray[hashValue] == value || hash->intArray[hashValue] == EMPTY_NODE)
        {
            break;
        }
        hashValue = hashValue + ResolverFun(i);
        hashValue = hashValue % hash->tableSize;
    }
    if (hash->intArray[hashValue] == value)
        return hashValue;
    else
        return -1; //value not found
}
int HashDelete(hashPtr hash, int value)
{
    int hashValue = ComputeHash(value, hash->tableSize);
    for (int i = 0; i < hash->tableSize; i++)
    {
        if (hash->intArray[hashValue] == EMPTY_NODE)
            return -1;
        if (hash->intArray[hashValue] == value)
        {
            hash->intArray[hashValue] = LAZY_DELETED;
            return 1; //deleted properly
        }
        hashValue = hashValue + ResolverFun(i);
        hashValue = hashValue % hash->tableSize;
    }
    return -1; //value not found
}
void PrintHash(hashPtr hash, int tableSize)//print key wise values
{
 for (int i = 0; i< hash->tableSize; i++)
 printf("index %d value :: %d \n", i, hash->intArray[i]);
}