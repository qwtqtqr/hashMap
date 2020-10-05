#ifndef HASH_MAP_H
#define HASH_MAP_H
#include "list.h"

#define HASH_MAP_DEFAULT_SIZE 16

typedef struct HashMap
{
	LinkedList* buckets[HASH_MAP_DEFAULT_SIZE];
}HashMap;


HashMap* newHashMap();
unsigned long hash_int(int x);
void HashMap_add(int key, void* data, HashMap* hashMap);
int getBucket(unsigned long hash);
void* HashMap_getItem(int key, HashMap* hashMap);

#endif