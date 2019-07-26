#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

#define UNVISITED -1
#define VISITED 1

vector <vi> adj;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vii edges;

int dfsNumberCounter;

void Bridge(int u)
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	int tam = (int)adj[u].size();

	for(int i=0;i<tam;i++)
	{
		int v = adj[u][i];
		
		if(dfs_num[v] == UNVISITED)
		{
			dfs_parent[v] = u;
			
			Bridge(v);

			if(dfs_low[v] > dfs_num[u])
			{
				if(u < v) edges.push_back(make_pair(u,v));
				else edges.push_back(make_pair(v,u));
			}
				

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);	
		}
		else if(v != dfs_parent[u])
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);	
	}

}

int main()
{
	int n;
	int teste = 0;

	while(scanf("%d",&n) == 1)
	{
		vi aux;
	
		adj.assign(n,aux);
		dfs_num.assign(n, UNVISITED); 
		dfs_low.assign(n, 0);
		dfs_parent.assign(n, 0);
		dfsNumberCounter = 0;
		edges.clear();

		for(int i=0;i<n;i++)
		{
			int u,k;
			scanf("%d (%d)",&u,&k);

			for(int j=0;j<k;j++)
			{
				int v;
				scanf("%d",&v);
				adj[u].push_back(v);
			}
		}

		for(int i=0;i<n;i++)
			if(dfs_num[i] == UNVISITED)
					Bridge(i);


		int tam = edges.size();

		printf("%d critical links\n",tam);

		sort(edges.begin(),edges.end());

		for(int i=0;i<tam;i++)
			printf("%d - %d\n",edges[i].first,edges[i].second);

		printf("\n");
	}

	return 0;
}
