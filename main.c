#include <stdio.h>
#include<time.h>
#include "hashMap.h"

#define LOOP_SIZE 10

int main() 
{
	HashMap* hashMap = newHashMap(HASH_MAP_INT);


	for (size_t i = 0; i < LOOP_SIZE ; i++)
	{
		HashMap_add(i, i, hashMap);
	}

	int valBef =(int*) HashMap_getItem(5, hashMap);
	printf("valBef: %d\n", valBef);
	HashMap_clear(hashMap);
	int valAfter = (int*)HashMap_getItem(5, hashMap);
	printf("valAfter: %d\n", valAfter);

	

	return 0;
}
