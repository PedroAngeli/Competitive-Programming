//Calcula o número de jeitos que se consegue chegar a um valor n centavos.
#include <cstdio>
#include <cstring>

int coin[5] = {1,5,10,25,50};
int ways[7490];

int solve(int n)
{
	ways[0] = 1;

	for(int i=0;i<5;i++)
		for(int j=coin[i];j<=n;j++)
			ways[j] += ways[j-coin[i]];

	return ways[n];
}

int main()
{
	int n;

	while(scanf("%d",&n) == 1)
	{
		memset(ways,0,7490*sizeof(int));

		printf("%d\n",solve(n));
	}


	return 0;
} 
