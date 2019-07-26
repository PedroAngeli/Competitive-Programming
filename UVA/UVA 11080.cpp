#include <cstdio>
#include <vector> 
#include <queue>

using namespace std;

#define INF -1
typedef vector<int> vi;

vector <vi> AdjList;
vi color;
int p,b;

bool BipartiteGraph(int s)
{
	queue<int> q; 
	q.push(s);
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

				if(color[v] == 0) b++;
				else p++;

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
	int t;

	scanf("%d",&t);

	while(t--)
	{
		int v,e;
		scanf("%d %d",&v,&e);
		
		vi aux;
		AdjList.assign(v,aux);

		for(int i=0;i<e;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);

			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}

		color.assign(v, INF); 

		
		bool check = true;
		int menor = 0;

		for(int i=0;i<v;i++)
		{
			if(color[i] == INF)
			{
				p=0,b=1;

				if(!BipartiteGraph(i))
				{
					printf("-1\n");
					check = false;
					break;
				}

				menor += max(1,min(p,b));
			}
		}

		if(check) printf("%d\n",menor);	
	}

	return 0;
}
