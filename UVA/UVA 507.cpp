#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> sum;
vector <long long> vet;
long long maior;
int finalIdx;
int initialIdx;

void maximumSum()
{
	int initialatual;

	sum[1] = vet[1];
	initialatual = 1;
	initialIdx = 1;
	finalIdx = 999999999;

	if(sum[1] > maior)
	{
		maior = sum[1];
		finalIdx = 1;
		initialIdx = initialatual;
	}

	if(sum[1] < 0) 
	{
		initialatual = 2;
		initialIdx = 2;
	}


	for(int i=2;i<vet.size();i++)
	{
		sum[i] = max(sum[i-1] + vet[i],vet[i]);

		if(sum[i] > maior || ((finalIdx - initialIdx < i - initialatual) && sum[i] == maior))
		{
			maior = sum[i];
			finalIdx = i;
			initialIdx = initialatual;
		}

		if(sum[i] < 0) initialatual = i + 1;
	}
}

int main()
{
	int b;
	scanf("%d",&b);
	int route = 1;

	while(b--)
	{
		int s;
		scanf("%d",&s);
		sum.assign(s+1,0);
		vet.clear();
		vet.push_back(1);
		maior = 0;
		
		int temp;
		
		for(int i=0;i<s-1;i++)
			scanf("%d",&temp),vet.push_back(temp);

		maximumSum();

		if(maior) printf("The nicest part of route %d is between stops %d and %d\n",route++,initialIdx,finalIdx+1);
		else printf("Route %d has no nice parts\n",route++);
			
	}

	return 0;
} 
