#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define INF 10004000
int c,v;
vector<pair<int,int>> adj[10004];
vector <int> distImpar;
vector <int> distPar;

void Dijkstra()
{
	priority_queue<pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > filaP; 
	distImpar.assign(c+1,INF);
	distPar.assign(c+1,INF);

	distPar[1] = 0;
	distImpar[1] = INF;

	filaP.push({0,1});

	while(!filaP.empty())
	{
		int u = filaP.top().second;
		filaP.pop();

		 for(auto &c : adj[u])
		 {
			int v = c.first;
			int w = c.second;
			
			if(distImpar[v] > distPar[u] + w)
			{
				distImpar[v] = distPar[u] + w;
				filaP.push({distImpar[v],v});
			}

			if(distPar[v] > distImpar[u] + w)
			{
				distPar[v] = distImpar[u] + w;
				filaP.push({distPar[v],v});
			}
		 }
	}
}

int main()
{
	scanf("%d %d",&c,&v);

	
	for(int i=0;i<v;i++)
	{
		int c1,c2,g;
		scanf("%d %d %d",&c1,&c2,&g);
		adj[c1].push_back({c2,g});
		adj[c2].push_back({c1,g});
	}

	Dijkstra();


	if(distPar[c] == INF)
		printf("-1\n");
	else 
		printf("%d\n",distPar[c]);
	return 0;
}
