#include <cstdio>




int main()
{
	int n;
	
	
	while(scanf("%d",&n)==1)
	{
		int aux = n;
		int soma = n;
	
			while(aux >= 3)
			{
				soma+=aux/3;
				aux = aux/3 + aux%3;
			}
		
			if(aux == 2) printf("%d\n",soma+1);
			else printf("%d\n",soma);
	

	}

	return 0;
}
