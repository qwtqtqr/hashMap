#include <stdio.h>
#include "hashMap.h"


int main() {
	HashMap* hashMap = newHashMap();


    HashMap_add(34, "qw", hashMap);
    HashMap_add(23, 435, hashMap);


	int val = (int*)HashMap_getItem(23, hashMap);

    char* str =(char*) HashMap_getItem(34, hashMap);

	printf("value: %d\n", val);


	return 0;
}