#include <cstdio>
#include <vector>

using namespace std;

vector < vector <int> > adj;
vector <bool> vis;
int visitados;

void dfs(int v)
{
	vis[v] = true;

	for (int j = 0; j < (int)adj[v].size(); j++) 
	{
		int u = adj[v][j];

		if(!vis[u])
		{
			visitados++;
			dfs(u);
		}
	} 
}

int main()
{
	int n,m;

	while(scanf("%d %d",&n,&m) == 2 && n && m)
	{
		int v,w,p;
		vector <int> aux;
		adj.assign(n+1,aux);

		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&v,&w,&p);
			
			if(p==2)
			{
				adj[v].push_back(w);
				adj[w].push_back(v);
			}
			else
				adj[v].push_back(w);
		}

		int resp = 1;

		for(int i=1;i<=n;i++)
		{
			visitados = 1;
			vis.assign(n+1,false);

			dfs(i);

			if(visitados != n)
			{
				resp = 0;
				break;
			}
		}

		printf("%d\n",resp);
	}

	

	return 0;
}
