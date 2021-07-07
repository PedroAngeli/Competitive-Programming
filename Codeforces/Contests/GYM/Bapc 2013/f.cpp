#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> ii; 
typedef vector<ii> vii;
typedef vector<int> vi;

vi parent; //diz o pai do i-esimo elemento - deve começar com o elemento sendo pai dele mesmo.
vi qtd; //diz o tamanho do conjunto - o vetor deve começar com 1.
vi peso; //diz a distancia do descendente mais longe (serve para otimizações) - o vetor deve começar com 0.

int E; //quantidade de arestas
int N;
int mst_cost; //custo da MST

vector< pair<int,ii> > EdgeList; //(peso, vertices(i,j)) das arestas

void unionFindInit() //Inicializa os vetores do UnionFind
{
	peso.assign(E+1,0);
	qtd.assign(E+1,1);
	parent.assign(E+1,0);

	for(int i=1;i<=N;i++)
		parent[i] = i;
}

int Find(int x) //Retorna o pai do elemento x
{	
	if(parent[x]==x) return x;
	
	return parent[x]=Find(parent[x]); 
}

int Union(int x,int y) //Union retornando o tamanho do conjunto.
{
	x=Find(x);
	y=Find(y);

	if(x!=y) 
	{
		if(peso[x]<peso[y])
		{
			 parent[x]=y; 
			 qtd[y]+=qtd[x]; 
	
			return qtd[y];
		}
	
		if(peso[x]>peso[y])
		{		
			 parent[y]=x; 
			 qtd[x]+=qtd[y]; 
			return qtd[x];
		}

		if(peso[x]==peso[y])
		{
			parent[x]=y;
			peso[y]++;
			qtd[y]+=qtd[x];
			return qtd[y];
		}
	}

	return qtd[x];

}

int Kruskal() //Kruskal retornando o custo da MST
{

	sort(EdgeList.begin(),EdgeList.end()); //Ordenando as arestas em ordem crescente de peso

	mst_cost = 0;

	for(int i=0;i<E;i++)
	{
		pair<int,ii> e = EdgeList[i];

		int v1 = e.second.first;
		int v2 = e.second.second;
		int p = e.first;

    // printf("%d %d %d\n",v1,v2,p);

		if(Find(v1) != Find(v2)) //Se os vertices forem de conjuntos diferentes
		{ 
			Union(v1,v2); //Junto os dois
			mst_cost += p; //Somo o custo da aresta no custo da MST
		} 
	}

	return mst_cost;

}

int main()
{
	int u,v,w;
  int t;

  cin >> t;

  while(t--){
    int n,m;
    cin >> n >> m;
    E = m;
    N = n;

    unionFindInit();
    EdgeList.clear();

    while(m--){
      scanf("%d %d",&u,&v);
		  EdgeList.push_back(make_pair(1,ii(u,v)));
    }

    printf("%d\n",Kruskal());
  }

}