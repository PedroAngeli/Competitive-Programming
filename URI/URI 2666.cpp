 #include <cstdio>
#include <vector>
#include <utility>

using namespace std;

vector <vector < pair<int,int> > > adj;
int peso[10005];
int visitado[10005];

int c;

pair<int,int> dfs(int v,int d)
{
	visitado[v] = 1;

	if(adj[v].size() == 0) 
	{
		if(peso[v] % c == 0) return make_pair((peso[v]/c)*d*2,peso[v]);
		else return make_pair(((peso[v]/c)+1)*2*d,peso[v]);
	}

	int tam = adj[v].size();

	int pesoTotal = 0;
	int distTotal = 0;

	for(int i=0;i<tam;i++)
	{
		if(!visitado[adj[v][i].first])
		{
			pair<int,int> par = dfs(adj[v][i].first,adj[v][i].second);
			pesoTotal+=par.second;
			distTotal+=par.first;
		}
	}

	int minhaDist;

	if((pesoTotal + peso[v]) % c == 0) minhaDist = ((pesoTotal+peso[v])/c)*d*2;
	else minhaDist = (((pesoTotal+peso[v])/c)+1)*2*d;

	if(v==1) minhaDist = 0;

	return make_pair(distTotal+minhaDist,pesoTotal+peso[v]);
}

int main()
{

	int n;

	scanf("%d %d",&n,&c);

	for(int i=1;i<=n;i++)
		scanf("%d",&peso[i]);

	vector <pair<int,int> > aux;
	adj.assign(n+1,aux);
	
	for(int i=1;i<=n-1;i++)
	{
		int u,v,p;
		scanf("%d %d %d",&u,&v,&p);
		adj[u].push_back(make_pair(v,p));
		adj[v].push_back(make_pair(u,p));
	}

	printf("%d\n",dfs(1,0).first);

	return 0;
}
