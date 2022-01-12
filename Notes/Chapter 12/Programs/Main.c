#include "Hash.h"
int main()
{
 hashPtr myHash = HashInitialize();
 for (int i = 65; i < 80; i++)
    HashInsert(myHash, i);
 printf("search 100 :: %d \n", HashFind(myHash, 100));
 printf("remove 100 :: %d \n", HashDelete(myHash, 100));
 printf("search 100 :: %d \n", HashFind(myHash, 100));
 printf("remove 100 :: %d \n", HashDelete(myHash, 100));
 PrintHash(myHash, TABLE_SIZE);
}