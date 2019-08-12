#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1000000000

int x;
int dp[10][100];
int wind[10][100];

int solve(int i,int j)
{
	if(i > 9 || j > x || i < 0) return INF;

	if(j == x) 
	{
		if(i == 9) return 0;
		else return INF;
	}

	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = min(20 - wind[i][j] + solve(i+1,j+1),min(30 - wind[i][j] + solve(i,j+1),60 - wind[i][j] + solve(i-1,j+1)));
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d",&x);
		x/=100;

		for(int i=0;i<10;i++)
			for(int j=0;j<x;j++)
				scanf("%d",&wind[i][j]);

		memset(dp,-1,sizeof dp);

		printf("%d\n\n",solve(9,0));
	}

	return 0;
}
