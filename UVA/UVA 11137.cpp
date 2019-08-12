#include <cstdio>
#include <cstring>

int coin[] = {0,1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long unsigned int ways[10001];

long long unsigned int solve(int n)
{
	ways[0] = 1;

	for(int i=1;i<=21;i++)
		for(int j=coin[i];j<=n;j++)
			ways[j] += ways[j-coin[i]];

	return ways[n];
}
int main()
{

	int n;

	while(scanf("%d",&n) == 1)
	{
		memset(ways,0,10001*sizeof(long long unsigned int));

		printf("%llu\n",solve(n));
	}


	return 0;
} 
