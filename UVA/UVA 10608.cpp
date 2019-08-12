#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 30001

int pai[MAXN];
int qtd[MAXN];

int find(int x)
{	

	if(pai[x]==x) return x;
	
	return pai[x]=find(pai[x]); 
}

void join(int x, int y)
{ 
	pai[find(x)]=find(y);
}


int main()
{
	
	int c;

	scanf("%d",&c);

	while(c--)
	{
		for(int i=1;i<MAXN;i++)
		{
			pai[i]=i;
			qtd[i]=0;
		}

		int n,m;

		scanf("%d %d",&n,&m);

		for(int i=0;i<m;i++)
		{
			int a,b;

			scanf("%d %d",&a,&b);

			if(pai[a]!=pai[b]) join(a,b);
		}

		for(int i=1;i<=n;i++)
			qtd[find(i)]++;
		

		sort(qtd+1,qtd+n+1);

		printf("%d\n",qtd[n]);
		
	}
	

	

	return 0;
}
