#include <cstdio>
#include <set>
#include <vector>

using namespace std;

#define MAXN 20020

int amigos[MAXN]; 
int peso[MAXN]; 

void init(int n)
{
	for(int i=0;i<2*n;i++)
	{
		amigos[i]=i;
		peso[i]=0;
	}
}

int find(int x)
{	
	if(amigos[x]==x) return x;
	
	return amigos[x]=find(amigos[x]); 
}

void join(int x, int y)  
{ 
	x=find(x);
	y=find(y);

	if(x!=y) 
	{
		if(peso[x]<peso[y]) amigos[x]=y; 
		
		if(peso[x]>peso[y]) amigos[y]=x; 
	
		if(peso[x]==peso[y])
		{
			amigos[x]=y;
			peso[y]++;
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	init(n);

	int c,x,y;

	while(scanf("%d %d %d",&c,&x,&y) == 3 && (c || x || y))
	{
		if(c == 1)
		{
			if( find(x+n) == find(y) )
				printf("-1\n");
			else 
			{
				join(x,y);
				join(x+n,y+n);
			}
		}
		else if(c == 2)
		{
				if( find(x) == find(y))
					printf("-1\n");
				else
				{
					join(x,y+n);
					join(y,x+n);
				}
		}
			else if(c == 3)
			{
				if( find(x) == find(y) )
					printf("1\n");
				else printf("0\n");
			}
			else
			{
				if( find(x+n) == find(y) )
					printf("1\n");
				else printf("0\n");
			}
			
				
	}

	return 0;
}
