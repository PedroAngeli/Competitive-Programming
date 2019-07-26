#include <cstdio>

int pai[120];

void init(int n)
{
	for(int i=1;i<=n;i++)
		pai[i]=i;
		
}


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
	int t;
	scanf("%d",&t);

	int caso = 1;

	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		
		init(n);
		
		int estradas = n-1;

		while(m--)
		{
			int x,y;
			scanf("%d %d",&x,&y);

			if(find(x) != find(y))
				estradas--;

			join(x,y);
		}

		printf("Caso #%d: ",caso++);

		if(estradas == 0)
			printf("a promessa foi cumprida\n");
		else 
			printf("ainda falta(m) %d estrada(s)\n",estradas);
		
	}

	return 0;
}
