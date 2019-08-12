#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	int n;

	while(scanf("%d",&n) == 1 && n)
	{
		vector <int> vet;

		while(n--)
		{
			int aux;
			scanf("%d",&aux);
			vet.push_back(aux);
		}

		sort(vet.begin(),vet.end());

		for(int i=0;i<vet.size();i++)
		{
			if(i == vet.size() - 1) printf("%d\n",vet[i]);
			else printf("%d ",vet[i]);
		}

	}

	return 0;
}
