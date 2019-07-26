#include <stdio.h>

bool adj[6][6] = {{0,0,0,0,0,0},
				  {0,0,1,1,0,1},
				  {0,1,0,1,0,1},
				  {0,1,1,0,1,1},
				  {0,0,0,1,0,1},
				  {0,1,1,1,1,0}};	

int ans[9];

void dfs(int u,int c)
{
	ans[c] = u;

	if(c == 8)
	{
		for(int i=0;i<9;i++)
			printf("%d",ans[i]);

		printf("\n");
	}

	for(int i=1;i<=5;i++)
	{
		if(adj[u][i] == true)
		{
			adj[u][i] = false;
			adj[i][u] = false;
			dfs(i,c+1);
			adj[u][i] = true;
			adj[i][u] = true;
		}
	}
}

int main()
{
	dfs(1,0);

	return 0;
}
