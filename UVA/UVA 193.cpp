#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

bitset <101> pintado;
vector <int> pintados;
int n;
int maior;


void dfs(int v,vector <int> adj[])
{

	if(v == n + 1)
	{
		int count = 0;

		for(int i=1;i<=n;i++)
			if(pintado[i]) count++;

		if(count > maior)
		{
			maior = count;
			pintados.clear();
			
			for(int i=1;i<=n;i++)
				if(pintado[i]) pintados.push_back(i);
		}

		return;
	}

	bool color = true;

	for(int i = 0; i < adj[v].size();i++)
	{
		int k = adj[v][i];

		if(pintado[k]) 
		{
			color = false;
			break;
		}
	}

	if(color)
	{
		pintado[v] = true;
		dfs(v+1,adj);
	}

	pintado[v] = false;

	dfs(v+1,adj);

	pintado.reset(v);
	
}

int main()
{
	int m;

	scanf("%d",&m);

	while(m--)
	{
		int k;
		scanf("%d %d",&n,&k);	

		vector <int> adj[n+1];
		pintado.reset();
		maior = 0;

		for(int i=0;i<k;i++)
		{
			int v1,v2;
			scanf("%d %d",&v1,&v2);
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}

		dfs(1,adj);

		printf("%lu\n",pintados.size());

		for(int i=0;i<pintados.size();i++)
		{
			if(i!=pintados.size() - 1) printf("%d ",pintados[i]);
			else printf("%d\n",pintados[i]);
		}
		
		
	}

	return 0;
}
