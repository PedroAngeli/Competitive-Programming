#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int n;
	int caso = 1;

	while(scanf("%d",&n) == 1 && n)
	{
		printf("Case %d:\n",caso++);

		vector <int> vet;

		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			vet.push_back(tmp);
		}

		//sort(vet.begin(),vet.end());

		int m;

		scanf("%d",&m);
	
		for(int k=0;k<m;k++)
		{
			int num;
			scanf("%d",&num);
			int dist = 999999999;
			int soma;

			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(vet[i] != vet[j])
					{
						int a = (vet[i] + vet[j]) - num;
						if(abs(a) < dist)
						{
							soma = vet[i] + vet[j];
							dist = abs(a);
						}
						//else break;
					}
				}
			}

			printf("Closest sum to %d is %d.\n",num,soma);
		}
		
			
	}

	return 0;
}
