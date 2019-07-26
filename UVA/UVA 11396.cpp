#include <cstdio>
#include <vector> 
#include <queue>

using namespace std;

#define INF -1
typedef vector<int> vi;

vector <vi> AdjList;
vi color;
int v;

bool BipartiteGraph(int s)
{
	queue<int> q; 
	q.push(s);
	color.assign(v+1, INF); 
	color[s] = 0;
	bool isBipartite = true; 

	while (!q.empty()) 
	{ 
		int u = q.front(); 
		q.pop();

		for (int j = 0; j < (int)AdjList[u].size(); j++) 
		{
			int v = AdjList[u][j];

			if (color[v] == INF) 
			{								
				color[v] = 1 - color[u]; 
				q.push(v); 
			}
			else if (color[v] == color[u]) 
				{  						
					isBipartite = false; 
					break; 
				}
		} 

	}
	

	return isBipartite;
}


int main()
{

	while(scanf("%d",&v) == 1 && v)
	{
		int a,b;
		vi aux;
		AdjList.assign(v+1,aux);

		while(scanf("%d %d",&a,&b) == 2 && a && b)
		{
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}

		if(BipartiteGraph(1)) printf("YES\n");
		else printf("NO\n");
		
	}


	return 0;
}
