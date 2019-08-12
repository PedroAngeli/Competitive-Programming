#include <cstdio>

using namespace std;

#define MAXN 30

int pai[MAXN]; 
int qtd[MAXN]; 
int peso[MAXN]; 

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		pai[i]=i;
		qtd[i]=1;
		peso[i]=0;
	}

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
	scanf("%d%*c%*c",&n);
	int teste = 0;

	while(n--)
	{
		if(teste) printf("\n");
		teste++;

		char up;
		scanf("%c%*c",&up);

		int tam = up-'A'+1;
		init(tam);

		char linha[5];
		
		while(scanf("%[^\n]%*c",linha) == 1)
		{
			char a,b;
			sscanf(linha,"%c%c",&a,&b);
			int n1 = a-'A'+1, n2 = b-'A'+1;
			
			if(find(n1) != find(n2))
			{
				join(n1,n2);
				tam--;
			}
		}

		scanf("%*c");
		printf("%d\n",tam);
	}


	return 0;
}
