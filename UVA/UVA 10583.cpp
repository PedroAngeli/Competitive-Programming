#include <cstdio>
#include <set>

using namespace std;

#define MAXN 50001

int pai[MAXN];
int peso[MAXN];

int find(int x)
{	

	if(pai[x]==x) return x;
	
	return pai[x]=find(pai[x]); 
}

void join(int x, int y)  //join retornando o tamanho do conjunto.
{ 
		x=find(x);
		y=find(y);

		if(x == y) return;
	
		if(peso[x]<peso[y]) pai[x]=y; 
		
		if(peso[x]>peso[y]) pai[y]=x; 
			  
		if(peso[x]==peso[y])
		{
			pai[x]=y;
			peso[y]++;	
		}
}


int main()
{
	int n,m;
	int teste = 0;

	while(scanf("%d %d",&n,&m) == 2 && (n || m))
	{
		set <int> conj;

		for(int i=1;i<=n;i++)
		{
			pai[i]=i;
			peso[i]=0;
		}
	
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			join(a,b);
		}
		
		for(int i=1;i<=n;i++)
			conj.insert(find(i));
		
		printf("Case %d: %lu\n",++teste,conj.size());
	}
	
	return 0;
}
