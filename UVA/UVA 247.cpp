#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#define UNVISITED -1
#define VISITED 1

typedef vector<int> vi;

vi dfs_num; 
vi dfs_low;
vi visited;
vi circle;
int n,m,dfsNumberCounter;
bool adj[30][30];
map <int,string> mapa;

void tarjanSCC(int u) 
{
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++; 
	circle.push_back(u); 
	visited[u] = 1;

	for (int j = 0; j < n; j++) 
	{
		if (dfs_num[j] == UNVISITED && adj[u][j])
			tarjanSCC(j);

		if (visited[j] && adj[u][j]) 
			dfs_low[u] = min(dfs_low[u], dfs_low[j]); 
	}

	if (dfs_low[u] == dfs_num[u])
	{
		while (1) 
		{
			int v = circle.back();
			circle.pop_back(); 
			visited[v] = 0;
			
			if(u == v) cout << mapa[v];
			else cout << mapa[v] + ", ";

			if (u == v) break; 
		}

		printf("\n");
	} 
}
int main()
{
	int teste = 0;

	while(scanf("%d %d",&n,&m) == 2 && (n || m))
	{
		if(teste) printf("\n");	
		printf("Calling circles for data set %d:\n",++teste);

		int count = 0;

		dfs_num.assign(n,UNVISITED);
		dfs_low.assign(n, 0); 
		visited.assign(n, 0);
		dfsNumberCounter = 0;
		memset(adj,false,sizeof adj);
		
		mapa.clear();
		map <string,int> aux;

		string a,b;
	
		for(int i=0;i<m;i++)
		{
			cin >> a >> b;

			if(!aux.count(a)) 
				aux[a] = count, mapa[count++] = a; 

			if(!aux.count(b))
				aux[b] = count, mapa[count++] = b;

			adj[aux[a]][aux[b]] = true;

		}

		for(int i=0;i<n;i++)
		{
			if(dfs_num[i] == UNVISITED) 
				tarjanSCC(i);
		}
		
		
	}
	
	return 0;
}





