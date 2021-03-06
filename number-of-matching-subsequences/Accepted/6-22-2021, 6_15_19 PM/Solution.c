// https://leetcode.com/problems/number-of-matching-subsequences

int cmpfun(char** A,char** B)
{
    return strcmp(*A,*B);
}
bool compare(char* words,char* cmpword)
{
    int len1=strlen(words);
    int len2=strlen(cmpword);
    int i=0,j=0;
    for(;i<len1&&j<len2;i++)
    {
        if(words[i]==cmpword[j])
            j++;
    }
    return j==len2;
}

int numMatchingSubseq(char * S, char ** words, int wordsSize){
    int count=0;
    bool flag=0;
    qsort(words,wordsSize,sizeof(char*),cmpfun);

    for(int i=0;i<wordsSize;i++)
    {
        flag=false;
        if(compare(S,words[i]))
        {
            flag=true;
            count++;
        }
        while((i+1<wordsSize)&&strcmp(words[i],words[i+1])==0)
        {
            i++;
            if(flag)
                count++;
        }
    }
    return count;
}