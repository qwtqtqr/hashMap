#include <stdio.h>
#include "hashMap.h"



int main() {


	HashMap* map = newhashMap(HASH_MAP_STRING);

	HashMap_add(HASH_MAP_STRING, "qw", "hello world", map);
	HashMap_add(HASH_MAP_STRING, "le", "lew", map);
	HashMap_add(HASH_MAP_STRING, "rx", "qwtqtqr", map);

	char* item =(char*) HashMap_getItem(HASH_MAP_STRING, "le", map);
	printf("%s\n", item);


	return 0;
}