#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "list.h"

#define HASH_MAP_DEFAULT_SIZE 16
#define HASH_MAP_INT 0
#define HASH_MAP_STRING 1
#define HASH_MAP_UINT 2


typedef struct HashMap
{
	LinkedList* buckets[HASH_MAP_DEFAULT_SIZE];
	int size;
	short type;
}HashMap;


HashMap* newHashMap(short type);
unsigned long hash_int(int x);
void HashMap_add(short type, void* key, void* data, HashMap* hashMap);
int getBucket(unsigned long hash);
void* HashMap_getItem( short type, int key, HashMap* hashMap);
unsigned long hash_string(unsigned char *str);

#endif