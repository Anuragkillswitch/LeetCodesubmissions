// https://leetcode.com/problems/longest-common-prefix



char * longestCommonPrefix(char ** strs, int strsSize){
if(strsSize==0)	return "";
	int i,j,len = strlen(strs[0]);
	
	for(i=0;i<len;i++)
	{
		for(j=1;j<strsSize;j++)
		{
			if(strs[0][i] == strs[j][i])
				continue;
			strs[0][i] = '\0';
		}
	}
	return strs[0];
}