#include <stdio.h>
#include "hashMap.h"


HashMap* newHashMap(short type)
{
	HashMap* map = malloc(sizeof(HashMap));
	for (int i = 0; i < HASH_MAP_DEFAULT_SIZE; i++)
	{
		map->buckets[i] = newLinkedList();
		map->size = 0;
		map->type = type;
	}
	return map;
}

unsigned long hash_string(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}


unsigned long hash_int(int x)
{
	unsigned long x_ = ((x >> 16) ^ x) * 0x45d9f3b;
	x_ = ((x_ >> 16) ^ x_) * 0x45d9f3b;
	x_ = (x_ >> 16) ^ x_;
	return x_;
}

int getBucket(unsigned long hash)
{
	int bucketVal =(int) hash % HASH_MAP_DEFAULT_SIZE;
	return bucketVal;
}

void HashMap_add(short type, void* key, void* data, HashMap* hashMap)
{
	if(type != hashMap->type)
	{
		printf("Error: invalid type in 'HashMap_add()' !");
		exit(1);
	}
	unsigned long hash = 0;
	switch (type)
	{
		case HASH_MAP_INT:  hash = hash_int((int*) key); break;
		case HASH_MAP_STRING: hash = hash_string((unsigned char*) key); break;
	}
	int bucketVal = getBucket(hash);
	LinkedList_add_end(hashMap->buckets[bucketVal], data, hash, key, type);
}


void* HashMap_getItem(short type, int key, HashMap* hashMap)
{
	if(type != hashMap->type)
	{
		printf("Error: invalid type in 'HashMap_getItem()' !");
		exit(1);
	}
	unsigned long hash = 0;
	switch (type)
	{
		case HASH_MAP_INT:  hash = hash_int((int*) key); break;
		case HASH_MAP_STRING: hash = hash_string((unsigned char*) key); break;
	}
	int bucketVal = getBucket(hash);

	LinkedList* bucket = hashMap->buckets[bucketVal];

	node_t* node = LinkedList_findNodeByKey(bucket, key, type);
	return node->data;
}
