#include <cstdio>
#include <bitset>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	long int num;

	while(scanf("%ld",&num) == 1)
	{
		bitset <32> bit = num;
		bitset <32> inv;

		for(int i = 0,j = 24;i<=7;i++,j++)
			inv[j]=bit[i];
		
		for(int i = 8,j = 16;i<=15;i++,j++)
			inv[j]=bit[i];

		for(int i = 16,j = 8;i<=23;i++,j++)
			inv[j]=bit[i];
			
		for(int i = 24,j = 0;i<=31;i++,j++)
			inv[j]=bit[i];

		printf("%ld converts to %d\n",num,(int)inv.to_ulong());
	}

	
	return 0;
}
