#include <cstdio>
#include <cstring>


int main()
{
	char palavra[50],c;


	while(scanf("%s",palavra)==1)
	{
		scanf("%c",&c);
		for(int i=strlen(palavra)-1;i>=0;i--)
			printf("%c",palavra[i]);
		
		printf("%c",c);
		
		
	}


	return 0;
}
