// https://leetcode.com/problems/convert-to-base-2

void swap(char *p,char *q){
    *p=*p+*q;
    *q=*p-*q;
    *p=*p-*q;
}
void reverse(char str[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        swap(&str[i],&str[j]);
        i++;
        j--;
    }
}
char * baseNeg2(int N){
    if(N==0)
        return "0";
    char*str=(char*)malloc(sizeof(char)*33);
    int k=0;
    while(N!=0){
        
        str[k]=(abs(N)%2)+'0';
        if(N>=0)
            N=-N/2;
        else
            N=(1-N)/2;
        k++;
    }
    str[k]=0;
    reverse(str,strlen(str));
    return str;
}