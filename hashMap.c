#include <stdio.h>
#include "hashMap.h"


HashMap* newHashMap(int type)
{
	HashMap* map = malloc(sizeof(HashMap));
	for (int i = 0; i < HASH_MAP_DEFAULT_SIZE; i++)
	{
		map->buckets[i] = newLinkedList();
	}
	map->size = 0;
	map->type = type;
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
	int bucketVal = (int)hash % HASH_MAP_DEFAULT_SIZE;
	if (bucketVal < 0)
	{
		bucketVal *= -1;
	}
	return bucketVal;
}

void HashMap_add(void* key, void* data, HashMap* hashMap)
{
	if (hashMap->type == HASH_MAP_INT)
	{
		int key_int = (int*)key;
		unsigned long hash = hash_int(key_int);
		int bucketVal = getBucket(hash);
		LinkedList_add_end(hashMap->buckets[bucketVal], data, hash, key_int);
		hashMap->size++;
	}
	else if (hashMap->type == HASH_MAP_STRING)
	{
		char* key_string = (char*)key;
		unsigned long hash = hash_string(key_string);
		int bucketVal = getBucket(hash);
		LinkedList_add_end(hashMap->buckets[bucketVal], data, hash, key_string);
		hashMap->size++;
	}
}

int HashMap_getSize(HashMap* hashMap)
{
	return hashMap->size;
}


void* HashMap_getItem(void* key, HashMap* hashMap)
{
	if (hashMap->type == HASH_MAP_INT)
	{
		int key_int = (int*)key;
		unsigned long hash = hash_int(key_int);
		int bucketVal = getBucket(hash);
		LinkedList* bucket = hashMap->buckets[bucketVal];
		node_t* node = LinkedList_findNodeByKey(bucket, key_int, HASH_MAP_INT);
		if (node == NULL)
		{
			return NULL;
		}
		return node->data;
	}
	if (hashMap->type == HASH_MAP_STRING)
	{
		char* key_string = (char*)key;
		unsigned long hash = hash_string(key_string);
		int bucketVal = getBucket(hash);
		LinkedList* bucket = hashMap->buckets[bucketVal];
		node_t* node = LinkedList_findNodeByKey(bucket, key_string, HASH_MAP_STRING);
		if (node == NULL)
		{
			return NULL;
		}
		return node->data;
	}
	return NULL;
}


unsigned long hash_string(char* s)
{
	unsigned long hashval;

	for (hashval = 0; *s != '\0'; s++)
	{
		hashval = *s + 31 * hashval;
	}
	return hashval;
}


void HashMap_removeItem(void* key, HashMap* hashMap)
{
	if (hashMap->type == HASH_MAP_INT)
	{
		int key_int = (int*)key;
		unsigned long hash = hash_int(key_int);
		int bucketVal = getBucket(hash);
		LinkedList* curList = hashMap->buckets[bucketVal];
		node_t* curNode = LinkedList_findNodeByKey(curList, key_int, hashMap->type);
		node_t* lastNode = curNode->last;
		node_t* nextNode = curNode->next;


		if (lastNode == NULL)
		{
			curList->head = curList->head->next;
			curList->size--;
			return;
		}
		if (nextNode == NULL)
		{
			curList->tail = curList->tail->last;;
			curList->size--;
			return;
		}

		lastNode->next = nextNode;
		nextNode->last = lastNode;
		curList->size--;
		hashMap->size--;
		return;
	}
}


void HashMap_clear(HashMap* hashMap)
{
	for (size_t i = 0; i < HASH_MAP_DEFAULT_SIZE; i++)
	{
		LinkedList_clear(hashMap->buckets[i]);
	}
}