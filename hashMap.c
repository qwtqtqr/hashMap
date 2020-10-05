#include <stdio.h>
#include "hashMap.h"


HashMap* newHashMap()
{
	HashMap* map = malloc(sizeof(HashMap));
	for (int i = 0; i < HASH_MAP_DEFAULT_SIZE; i++)
	{
		map->buckets[i] = newLinkedList();
	}
	return map;
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

void HashMap_add(int key, void* data, HashMap* hashMap)
{
	unsigned long hash = hash_int(key);
	int bucketVal = getBucket(hash);
	LinkedList_add_end(hashMap->buckets[bucketVal], data, hash, key);
}


void* HashMap_getItem(int key, HashMap* hashMap)
{
	unsigned long hash = hash_int(key);
	int bucketVal = getBucket(hash);

	LinkedList* bucket = hashMap->buckets[bucketVal];

	node_t* node = LinkedList_findNodeByKey(bucket, key);
	return node->data;
}
