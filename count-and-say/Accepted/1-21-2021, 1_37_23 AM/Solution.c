// https://leetcode.com/problems/count-and-say



char * countAndSay(int n){
int j = 0 ,c = 1;
	char* ans = malloc(1024*20*sizeof(char));
    char* temp = malloc(1024*20*sizeof(char));
	ans[0] = '1';
	ans[1] = '\0';
	for (int i = 1; i < n; i++)
	{
		int k = 0;
		while (ans[j] != '\0')
		{
			if (ans[j] == ans[j + 1])
			{
				c++;
			}
			else
			{
				temp[k] = c + '0';
				temp[k+1] = ans[j];
                k = k + 2;
				c = 1;
			}
			j++;
		}
		temp[k] = '\0';
		strcpy(ans,temp);
		j = 0;
	}
	return(ans);
}