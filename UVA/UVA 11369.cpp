#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(int i,int j)
{
	return i>j;
}
int main()
{
	int t;

	scanf("%d",&t);


	while(t--)
	{
		int desconto = 0;
		int n,temp;
		vector <int> vet;

		scanf("%d",&n);	

		for(int i=0;i<n;i++) 
			scanf("%d",&temp), vet.push_back(temp);	
		
		sort(vet.begin(),vet.end(),cmp);

		int k = 2;

		if(n >=3)
			while(k<n)
				desconto+=vet[k], k+=3;
		
		printf("%d\n",desconto);
	}

	return 0;
}
