#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "list.h"

#define HASH_MAP_DEFAULT_SIZE 16
#define HASH_MAP_INT 0
#define HASH_MAP_STRING 1
#define HASH_MAP HashMap*

typedef struct HashMap
{
	LinkedList* buckets[HASH_MAP_DEFAULT_SIZE];
	int type;
	int size;
}HashMap;


HashMap* newHashMap(int type);
unsigned long hash_int(int x);
void HashMap_add(void* key, void* data, HashMap* hashMap);
int getBucket(unsigned long hash);
void* HashMap_getItem(void* key, HashMap* hashMap);
int HashMap_getSize(HashMap* hashMap);
unsigned long hash_string(char* str);
void HashMap_removeItem(void* key, HashMap* hashMap);
void HashMap_clear(HashMap* hashMap);

#endif
