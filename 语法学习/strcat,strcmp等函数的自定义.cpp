size_t mystrlen(const char*str)
{
	if(str==NULL)
		return 0;
	size_t cnt = 0;
	while(str[cnt])
		++cnt;
	return cnt;
}

int mystrcmp(const char*s1,const char*s2)
{
	if(!s1&&s2)
		return-1;
	if(s1&&!s2)
		return 1;
	if(!s1&&!s2)
		return 0;
	int i = 0;
	while(s1[i]&&s2[i]&&s1[i]==s2[i])
		++i;
	return(s1[i]-s2[i]);
	
	
}

char*mystrcat(char*dest,const char*src)
{
	if(dest==NULL||src==NULL)
		return NULL;
	//  abcd\0 
	//       cd\0
	size_t dest_len = mystrlen(dest);
	if(src<dest+dest_len)
	{
		size_t src_len = mystrlen(src);
	
		// 如果目标空间和原空间有重叠  需要从后往前追加
		//  abcd\0   
		//      cd\0;
		dest[dest_len+src_len] = '\0';
		while(src_len--)
			dest[dest_len+src_len] = src[src_len];
	}
	else
	{
		//  正常情况下的追加
		int i = 0;
		while(dest[i])
			++i;
		int j = 0;
		while(src[j])
		{
			dest[i+j] = src[j];
			++j;
		}
		dest[i+j] = '\0';
	}
	return dest;
}


char*mystrcpy(char*dest,const char*src)
{
	if(src==dest)
		return dest;
	char*ret_dest = dest;
	//  src: abcdef\0
	// dest:        abcdef\0
	size_t src_len = strlen(src);
	if(dest<=src+src_len)
	{
		while(src_len)
		{
			dest[src_len] = src[src_len];
			src_len--;
		}
		dest[src_len] = src[src_len];
	}
	else{
		while(*src)
			//abc\0
		*dest++ = *src++;
		*dest = '\0';
	}
	return ret_dest;
}

