#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
#define MAXN 600


int pai[MAXN];
int peso[MAXN];

typedef struct 
{
	int x,y;
}Ponto;

typedef struct 
{
	int a,b;
	double peso;
}Aresta;

int find(int x)
{	
	if(pai[x]==x) return x;
	
	return pai[x]=find(pai[x]); 
}

void join(int x, int y)
{ 
	x=find(x);
	y=find(y);
	
	if(x==y) return;
	
	if(peso[x]<peso[y]) pai[x]=y;
	if(peso[x]>peso[y]) pai[y]=x;
	
	if(peso[x]==peso[y]){
		
		pai[x]=y;
		peso[y]++;
	}
}

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		pai[i]=i;
		peso[i]=0;
	}
}

bool compara(Aresta a, Aresta b)
{
	return a.peso < b.peso;
}

void Kruskal(vector <Aresta> &arvore,vector<Aresta> arestas,int s)
{
	sort(arestas.begin(),arestas.end(),compara);

	for(int i=0;i<arestas.size();i++)
	{
		int v1=find(arestas[i].a);
		int v2=find(arestas[i].b);

		if(v1!=v2)
		{
			join(v1,v2);
			arvore.push_back(arestas[i]);
		}
	}
}

int main()
{
	int n;

	scanf("%d",&n);
	
	while(n--)
	{
		vector <Aresta> arestas;
		vector <Ponto> pontos;
		vector <Aresta> arvore;
		int p,s;

		scanf("%d %d",&s,&p);

		init(p);
		
		while(p--)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			Ponto a;
			a.x=x,a.y=y;
			pontos.push_back(a);
		} 
		
		for(int i=0;i<pontos.size();i++)
			for(int j=i+1;j<pontos.size();j++)
			{
				double distancia = sqrt(((pontos[i].x-pontos[j].x)*(pontos[i].x-pontos[j].x)) +
							((pontos[i].y-pontos[j].y)*(pontos[i].y-pontos[j].y)));
				Aresta a;
				a.peso = distancia;
				a.a = i,a.b = j;
				arestas.push_back(a);
			}

		Kruskal(arvore,arestas,s);
		
		//printf("%d\n",arvore.size());
		printf("%.2lf\n",arvore[arvore.size()-s].peso);
	}


	return 0;
}
