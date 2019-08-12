#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool adj[50][50];
bool visitado[40];
int caminho[40];

int xi,yi,xf,yf;

bool paredeHorizontal(int x1,int y1,int x2,int y2)
{
	return x1 == x2;
}

bool paredeVertical(int x1,int y1,int x2,int y2)
{
	return y1 == y2;
}

void bfs(int inicio,int fim)
{
	memset(visitado, false, sizeof(visitado));

	queue <int> fila;

	fila.push(inicio);

	while(!fila.empty())
	{
		int v = fila.front();
		visitado[v] = true;

		if(v == fim) return;

		for(int i=1;i<=36;i++)
		{
			if(adj[v][i] && !visitado[i])
			{
				fila.push(i);
				caminho[i] = v;	
			}
		}

		fila.pop();
	}
}

void printaCoord(int id,int filho)
{
	if(filho == id - 6) printf("N");
	if(filho == id + 1) printf("E");
	if(filho == id - 1) printf("W");
	if(filho == id + 6) printf("S");
}

void printCaminho(int id,int filho)
{
	if(caminho[id] == 0) 
	{
		printaCoord(id,filho);
		return;
	}
	
	printCaminho(caminho[id],id);

	printaCoord(id,filho);
}

int main()
{
	while(scanf("%d %d",&yi, &xi) == 2 && xi && yi)
	{
		memset(caminho,0,sizeof caminho);

		scanf("%d %d",&yf,&xf);

		for(int i=1;i<=36;i++)
			for(int j=1;j<=36;j++)
				adj[i][j] = false;

		for(int i=1;i<=36;i++)
		{
				adj[i][i+6] = true;

				if(i-6 > 0) adj[i][i-6] = true;

				if(i%6 == 1) adj[i][i+1] = true;
				else if(i%6 == 0) adj[i][i-1] = true;
				else
				{
					adj[i][i+1] = true;
					adj[i][i-1] = true;
				}
		}

		int x1,y1,x2,y2;

		for(int i=0;i<3;i++)
		{
			scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

			if(paredeVertical(x1,y1,x2,y2))
			{
				x1++;
				for(int l=x1;l<=x2;l++)
				{
					adj[(6*l + y1) - 6][(6*l + y1)-6+1] = false;
					adj[(6*l + y1)-6+1][(6*l + y1) - 6] = false;
				}
						
			}else if(paredeHorizontal(x1,y1,x2,y2))
			{
				y1++;

				for(int c=y1;c<=y2;c++)
				{
					int idx = (6*x1 + c) - 6;
					if(idx > 0)
					{
						adj[idx][idx+6] = false;
						adj[idx+6][idx] = false;
					}
				}
			}
			
		}

		
		int inicio = (6*xi + yi) - 6;
		int fim = (6*xf + yf) - 6;

		bfs(inicio,fim);

		printCaminho(fim,fim);
		printf("\n");
	}


	return 0;
}
