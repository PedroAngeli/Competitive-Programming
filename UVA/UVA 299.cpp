#include <cstdio>
#include <vector>

using namespace std;

int bubble(vector <int> &vet)
{
	bool verifica = true;
	int count = 0;

	while(verifica)
	{
		verifica = false;

		for(int i=0;i<vet.size()-1;i++)
		{
			if(vet[i] > vet[i+1])
			{
				count++;
				int aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
				verifica = true;
			}
		}
		
	}

	return count;

}

int main()
{
	int n;

	scanf("%d",&n);

	while(n--)
	{
		vector <int> vet;
		int l;
		
		scanf("%d",&l);

		int var;

		for(int i=0;i<l;i++)
		{
			scanf("%d",&var);
			vet.push_back(var);
		}
		
		if(l>0) printf("Optimal train swapping takes %d swaps.\n",bubble(vet));
		else printf("Optimal train swapping takes 0 swaps.\n");
	}

	return 0;
}
