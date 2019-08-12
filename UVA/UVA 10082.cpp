#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

char qwerty[] = "'1234567890-=QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,./";

int main()
{
	string input;

	while (getline(cin,input))
	{
		for(int i=0;i<input.size();i++)
		{
			if(input[i] == ' ') 
			{
				printf(" ");
				continue;
			}
			if(input[i] == '\\')
			{
				printf("]");
				continue;
			}
			if(input[i] == '\'')
			{
				printf(";");
				continue;
			}

			for(int j=0;j<48;j++)
				if(input[i] == qwerty[j]) 
				{
					printf("%c",qwerty[j-1]);
					break;
				}
		}

		printf("\n");
	}		 
	


	return 0;
}
