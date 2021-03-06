// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

#define STACK_SIZE_MAX 100000

typedef struct
{
    char data;
    int count;
} Entry_t;

char * removeDuplicates(char * s, int k){
    Entry_t stack[STACK_SIZE_MAX];
    int stackSize = 0;
    
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (stackSize == 0 || s[i] != stack[stackSize-1].data)
        {
            stack[stackSize].data = s[i];
            stack[stackSize++].count = 1;
        }
        else // stackSize != 0 && s[i] == stack[stackSize-1]
        {
            if (stack[stackSize-1].count == k-1)
            {
                stackSize -= k-1;
            }
            else
            {
                stack[stackSize].data = s[i];
                stack[stackSize].count = stack[stackSize-1].count + 1;
                stackSize++;
            }
        }
    }
    
    char* ans = malloc(sizeof(char) * (stackSize + 1));
    for (int i = 0; i < stackSize; i++)
    {
        // printf("%c", stack[i].data);
        ans[i] = stack[i].data;
    }
    // printf("\nEnd\n");
    
    ans[stackSize] = '\0';
    return ans;
}