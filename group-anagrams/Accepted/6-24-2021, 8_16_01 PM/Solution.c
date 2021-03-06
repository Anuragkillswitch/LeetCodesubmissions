// https://leetcode.com/problems/group-anagrams

#define TABLE_SIZE 24593

typedef struct Node
{
    char *val;
    struct Node *next;
} Node;

typedef struct Entry
{
    char *key;
    int listSize;
    struct Node *wordList;
    struct Entry *next;
} Entry;

typedef struct HashTable
{
    int tableSize;
    struct Entry **buckets;
} HashTable;

HashTable *createTable()
{
    HashTable *ht = calloc(1, sizeof(HashTable));
    ht->buckets = calloc(TABLE_SIZE, sizeof(Entry));
    
    return ht;
}

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

Entry *search(HashTable *ht, char *key)
{
    int index = hash(key);
    
    if (ht->buckets[index] == NULL)
        return NULL;
    
    Entry *bucket = ht->buckets[index];
    while (bucket)
    {
        if (!strcmp(bucket->key, key))
            return bucket;
        
        bucket = bucket->next;
    }
    
    return NULL;
}

void insert(HashTable *ht, char *key, char *val)
{
    Entry *bucket = search(ht, key);
        
    if (bucket == NULL)
    {
        bucket = calloc(1, sizeof(Entry));
        bucket->key = malloc(sizeof(char) * (strlen(key) + 1));
        strcpy(bucket->key, key);
        bucket->listSize = 1;
        
        int index = hash(key);
        bucket->next = ht->buckets[index];
        ht->buckets[index] = bucket;
        ht->tableSize++;
    }
    
    Node *newNode = calloc(1, sizeof(Node));
    newNode->val = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(newNode->val, val);
    
    if (bucket->wordList == NULL)
    {
        bucket->wordList = newNode;
        return;
    }
    
    newNode->next = bucket->wordList;
    bucket->wordList = newNode;
    bucket->listSize++;
}

int comp(const void *a, const void *b) 
{ 
    return *(char *)a - *(char *)b; 
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    char ***res = NULL;
    HashTable *ht = createTable();
    char buf[128];
   
    for (int i = 0; i < strsSize; i++)
    {
        int len = strlen(strs[i]);
        strncpy(buf, strs[i], len + 1);
        qsort(buf, len, sizeof(char), comp);
        
        insert(ht, buf, strs[i]);
    }
    
    *returnSize = ht->tableSize;
    res = malloc(sizeof(char **) * (*returnSize));
    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    int listCounter = 0, wordCounter = 0;
    
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Entry *bucket = ht->buckets[i];
        
        if (bucket == NULL)
            continue;

        while (bucket)
        {
            (*returnColumnSizes)[listCounter] = bucket->listSize;
            res[listCounter] = malloc(sizeof(char *) * bucket->listSize);
            
            for (Node *cur = bucket->wordList; cur; cur = cur->next)
            {
                res[listCounter][wordCounter] = calloc(strlen(cur->val) + 1, sizeof(char));
                strcpy((res)[listCounter][wordCounter++], cur->val);
            }
            
            listCounter++;
            wordCounter = 0;
            
            bucket = bucket->next;
        }
    }
    
    return res;
}