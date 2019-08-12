#include <cstdio>
#include <map>
#include <queue>
#include <set>

using namespace std;


void bfs(set <int> &visitados,int inicio,int ttl,map <int,vector<int> > mapa,map <int,int> verifica,set <int> nodes)
{
	queue < pair<int,int> > fila;
	fila.push(make_pair(inicio,0));

	
	while(!fila.empty())
	{
		int v = fila.front().first;
		int dAtual = fila.front().second;
		if(nodes.count(v)) visitados.insert(v);

		for(int i=0;i<mapa[v].size();i++)
		{
			//printf("%d\n",verifica[v]);
			if(dAtual + 1 <= ttl && verifica[mapa[v][i]] == 0) 
			{
				fila.push(make_pair(mapa[v][i],dAtual+1));
				verifica[mapa[v][i]]=1;
			}
		}
				
		fila.pop();
	}

}

int main()
{
	int nc;
	int caso = 0;

	while(scanf("%d",&nc) == 1 && nc)
	{
		map <int, vector<int> > mapa;
		int x,y;
		set <int> nodes;

		while(nc--)
		{
			scanf("%d %d",&x,&y);
			nodes.insert(x);
			nodes.insert(y);
			mapa[x].push_back(y);
			mapa[y].push_back(x);
		}

		int node,ttl;
		
		while(scanf("%d %d",&node,&ttl) == 2 && (node || ttl))
		{	
			set <int> visitados;
			map <int,int> verifica;

			bfs(visitados, node,ttl,mapa,verifica,nodes);
			int nr = nodes.size() - visitados.size();

			//printf("%d\n",visitados.begin());
			
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++caso,nr,node,ttl);
		}
		
	}
	
	return 0;
}
