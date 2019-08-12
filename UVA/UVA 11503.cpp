#include <cstdio>
#include <map>
#include <iostream>
#include <string>

using namespace std;

#define MAXN 100001

int pai[MAXN];
int qtd[MAXN];
int peso[MAXN];


int find(int x)
{	

	if(pai[x]==x) return x;
	
	return pai[x]=find(pai[x]); 
}

int join(int x, int y)
{ 
	x=find(x);
	y=find(y);

	if(x!=y) 
	{
		if(peso[x]<peso[y])
		{
			 pai[x]=y; 
			 qtd[y]+=qtd[x]; 
	
			return qtd[y];
		}
	
		if(peso[x]>peso[y])
		{		
			 pai[y]=x; 
			 qtd[x]+=qtd[y]; 
			return qtd[x];
		}

		if(peso[x]==peso[y])
		{
			pai[x]=y;
			peso[y]++;
			qtd[y]+=qtd[x];
			return qtd[y];
		}
	}

	return qtd[x];

}

int main()
{
	int c;

	scanf("%d",&c);
	scanf("%*c");

	while(c--)
	{
		map <string,int> nomes;

		int n;
		
		scanf("%d",&n);
		scanf("%*c");

		for(int i=1;i<=MAXN;i++)
		{
			pai[i]=i;
			qtd[i]=1;
			peso[i]=0;
		}

		int count = 1;

		for(int i=0;i<n;i++)
		{
			string a,b;
			char x[30],y[30];

			scanf("%s %s",x,y);
			a = x;
			b = y;

			if(nomes.find(a) == nomes.end()) nomes[a] = count++;
			if(nomes.find(b) == nomes.end()) nomes[b] = count++;

			int res = join(nomes[a],nomes[b]);
			
			printf("%d\n",res);
		}
	}

	
	return 0;
}
