#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector <int> vet;
int pd[55][55];

int solve(int l,int r)
{
	if(l+1 == r) return 0;

	int menor = 999999999;
	
	if(pd[l][r] != -1) return pd[l][r];

	for(int i=l+1;i<=r-1;i++)
	 	menor = min(menor,solve(l,i) + solve(i,r) + (vet[r]-vet[l]));

	
	return pd[l][r] = menor;
}

int main()
{
	int l;

	while(scanf("%d",&l) == 1 && l)
	{
		int n;
		scanf("%d",&n);
	
		vet.clear();
		memset(pd,-1,sizeof pd);

		vet.push_back(0);

		for(int i=0;i<n;i++)
		{
			int tmp;	
			scanf("%d",&tmp);
			vet.push_back(tmp);
		}

		vet.push_back(l);
		
		printf("The minimum cutting is %d.\n",solve(0,n+1));
	}

	return 0;
}
