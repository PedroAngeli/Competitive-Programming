#include <cstdio>
#include <cstring>

long long unsigned int pd[105][105];

long long unsigned int solve(int n,int k)
{
	if(k == 1) return 1;

	long long unsigned int soma = 0;

	if(pd[n][k] != -1) return pd[n][k];

	for(int i=0;i<=n;i++)
	{
		soma += solve(n-i,k-1) %1000000;
	}

	return pd[n][k] = soma;
}

int main()
{
	int n,k;

	while(scanf("%d %d",&n,&k) == 2 && n && k)
	{
		memset(pd,-1,sizeof pd);

		printf("%llu\n",solve(n,k)%1000000);
	}


	return 0;
}
