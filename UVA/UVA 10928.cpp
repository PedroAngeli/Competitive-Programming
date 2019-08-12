#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

int main()
{	
	
	int n;
		
	scanf("%d",&n);

	while(n--)
	{
		vector < pair <int,int> > vet;
		int p;
		scanf("%d%*c",&p);	
		char linha[10000];

		for(int i=1;i<=p;i++)
		{
			scanf("%[^\n]%*c",linha);

			int tam = strlen(linha);
			int espacos = 0;

			for(int j = 0;j<tam;j++)
					if(linha[j] == ' ') espacos++;

			int count = espacos*2 + 1;
			tam = count - espacos;
			vet.push_back(make_pair(tam,i));
		}

		stable_sort(vet.begin(),vet.end());

		int primeiro = vet[0].first;
				
		for(int i=0;i<vet.size();i++)
		{
			//printf("%d %d\n",vet[i].first,vet[i].second);
			if(vet[i].first == primeiro) 
			{
				printf("%d",vet[i].second);
			}
			else break;

			if(vet[i+1].first == primeiro) printf(" ");
			
		}

		printf("\n");
	}	

	
	return 0;
}
