#include <cstdio>
#include <algorithm>
#include <cstring>

#define INF 1000000000

using namespace std;

int matriz[11][1005];
int dp[11][1005];
int caminho[10005];
int m,n;

void printaCaminho(int id)
{
	if(caminho[id] == -1)
	{
		printf("%d",id/n + 1);
		return;
	}
	else printf("%d ",id/n + 1);
	printaCaminho(caminho[id]);
	
}

int IdMatriz(int i,int j)
{
	return n*i + j;
}

int solve(int i,int j)
{
	int min_value = INF;

	if(i < 0 || i >= m || j > n) return INF;

	if(j == n - 1) return matriz[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	//printf("%d %d\n",i,j);

	if(i == 0)
	{
		int costUp = matriz[i][j] + solve(m-1,j+1);
		int costFront = matriz[i][j] + solve(i,j+1);
		int costDown = matriz[i][j] + solve(i+1,j+1);

		if(costFront < min_value)
		{
				min_value = costFront;
				caminho[IdMatriz(i,j)] = IdMatriz(i,j+1);
		}

		if(costDown < min_value)
		{
				min_value = costDown;
				caminho[IdMatriz(i,j)] = IdMatriz(i+1,j+1);
		}
		if(costUp < min_value)
		{
			min_value = costUp;
			caminho[IdMatriz(i,j)] = IdMatriz(m-1,j+1);
		}
		
		return dp[i][j] = min_value;
	} 
	else if(i == m - 1)
	{
		int costUp = matriz[i][j] + solve(i-1,j+1);
		int costFront = matriz[i][j] + solve(i,j+1);
		int costDown = matriz[i][j] + solve(0,j+1);

		if(costDown < min_value)
		{
				min_value = costDown;
				caminho[IdMatriz(i,j)] = IdMatriz(0,j+1);
		}
		if(costUp < min_value)
		{
			min_value = costUp;
			caminho[IdMatriz(i,j)] = IdMatriz(i-1,j+1);
		}
		if(costFront < min_value)
		{
				min_value = costFront;
				caminho[IdMatriz(i,j)] = IdMatriz(i,j+1);
		}
		

		return dp[i][j] = min_value;
	}
	else 
	{
		int costUp = matriz[i][j] + solve(i-1,j+1);
		int costFront = matriz[i][j] + solve(i,j+1);
		int costDown = matriz[i][j] + solve(i+1,j+1);

		if(costUp < min_value)
		{
			min_value = costUp;
			caminho[IdMatriz(i,j)] = IdMatriz(i-1,j+1);
		}
		if(costFront < min_value)
		{
				min_value = costFront;
				caminho[IdMatriz(i,j)] = IdMatriz(i,j+1);
		}
		if(costDown < min_value)
		{
				min_value = costDown;
				caminho[IdMatriz(i,j)] = IdMatriz(i+1,j+1);
		}

		return dp[i][j] = min_value;
	}
}

int main()
{

	while(scanf("%d %d",&m,&n) == 2)
	{
		memset(dp,-1,sizeof dp);
		memset(caminho,-1,sizeof caminho);

		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&matriz[i][j]);

		int resp = INF;
		int id;

		for(int i=0;i<m;i++)
		{
			if(solve(i,0) < resp)
			{
				resp = solve(i,0);
				id = IdMatriz(i,0);
			}
		}

		printaCaminho(id);
		printf("\n");
		printf("%d\n",resp); //tamanho do menor caminho
		
	}

	return 0;
}
