#include <cstdio>
#include <map>
#include <string>
#include <iostream>

using namespace std;

map <int,int> pai;


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
	int n;
	scanf("%d",&n);
	int teste = 0;

	while(n--)
	{
		int t;
		scanf("%d%*c",&t);
		int sucess = 0,fail = 0;

		init(t);

		if(teste) printf("\n");
		teste++;

		char c;
		int i,j;
		
		char linha[30];

		while(scanf("%[^\n]%*c",linha) == 1)
		{
			sscanf(linha,"%c %d %d",&c,&i,&j);

			if(c == 'c')	join(i,j);
			else 
			{
				if(find(i) == find(j)) sucess++;
				else fail++;
			}
		}

		printf("%d,%d\n",sucess,fail);	

		//scanf("%*c");
		
	}

	

	return 0;
}
