#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int l,n;
		scanf("%d %d",&l,&n);
		vector <int> ant;

		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			ant.push_back(tmp);
		}


		int menor = 0;
		int maior = 0;
		
		for(int i=0;i<n;i++)
		{
			int dif1 = ant[i] - 0;
			int dif2 = l - ant[i];
		
			int tmp = min(dif1,dif2);
			menor = max(menor,tmp);
			tmp = max(dif1,dif2);
			maior = max(tmp,maior);
		}

		printf("%d %d\n",menor,maior);
	}


	return 0;
}
