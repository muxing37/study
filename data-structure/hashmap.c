#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    size_t count;
} HashMap;

unsigned long hash(const char *str)
{
    unsigned long h=5381;
    int c;
    while((c=*str++)) {
        h=((h<<5)+h)+c;
    }
    return h;
}

HashMap *create(size_t count)
{
    HashMap *map=malloc(sizeof(HashMap));
    if(!map) return NULL;

    map->count=count;
    map->buckets=calloc(count,sizeof(HashNode *));
    if(!map->buckets) {
        free(map);
        return NULL;
    }
    return map;
}

int put(HashMap *map,const char *key,int value)
{
    unsigned long h=hash(key)%map->count;
    HashNode *node=map->buckets[h];

    while(node) {
        if(strcmp(node->key,key)==0) {
            node->value=value;
            return 0;
        }
        node=node->next;
    }

    HashNode *newnode=malloc(sizeof(HashNode));
    newnode->key=strdup(key);
    newnode->value=value;
    newnode->next=map->buckets[h];
    map->buckets[h]=newnode;

    return 0;
}

int get(HashMap *map,const char *key,int *out)
{
    unsigned long h=hash(key)%map->count;
    HashNode *node=map->buckets[h];

    while(node) {
        if(strcmp(node->key,key)==0) {
            *out=node->value;
            return 0;
        }
        node=node->next;
    }
    return -1;
}

int hremove(HashMap *map,const char *key)
{
    unsigned long h=hash(key)%map->count;
    HashNode *cur=map->buckets[h];
    HashNode *prev=NULL;

    while(cur) {
        if(strcmp(cur->key,key)==0) {
            if(prev) {
                prev->next=cur->next;
            } else {
                map->buckets[h]=cur->next;
            }
            free(cur->key);
            free(cur);
            return 0;
        }
        prev=cur;
        cur=cur->next;
    }
    return -1;
}

void destroy(HashMap *map)
{
    int i;
    for (i=0;i<map->count;i++) {
        HashNode *node=map->buckets[i];
        while(node) {
            HashNode *tmp=node;
            node=node->next;
            free(tmp->key);
            free(tmp);
        }
    }
    free(map->buckets);
    free(map);
}

int main(void)
{
    HashMap *map=create(8);

    put(map,"apple",10);
    put(map,"banana",20);
    put(map,"apple",30);

    int v;
    if(get(map,"apple",&v)==0) {
        printf("apple = %d\n",v);
    }
    hremove(map,"banana");

    destroy(map);
    return 0;
}
