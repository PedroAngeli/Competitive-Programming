#include <cstdio>


int device[30];
bool estado[30];

int main()
{
	int teste = 0;
	int n,m,c;
	
	while(scanf("%d %d %d",&n,&m,&c) == 3 && n && m && c)
	{
		for(int i=1;i<=n;i++)
			estado[i] = false;

		int count = 0,maior = 0;
		teste++;

		for(int i=1;i<=n;i++)
			scanf("%d",&device[i]);

		int acao;
		bool blow = false;

		for(int i=0;i<m;i++)
		{
			scanf("%d",&acao);
			if(estado[acao] == false) 
			{
				count+=device[acao];
				estado[acao] = true;
			}
			else 
			{
				estado[acao] = false;
				count-=device[acao];
			}
			if(count > maior) maior = count;

			if(maior > c) blow = true;
		}

		printf("Sequence %d\n",teste);

		if(blow) printf("Fuse was blown.\n\n");
		else 
		printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",maior);
		
	}




	return 0;
}
