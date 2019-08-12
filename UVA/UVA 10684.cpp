#include <cstdio>
#include <vector>

using namespace std;

vector <int> seq;
vector <int> sum;
int n;
int maior;

void maximumSum()
{
	sum[0] = seq[0];

	for(int i=1;i<n;i++)
	{
		sum[i] = max(sum[i-1] + seq[i],seq[i]);
		maior = max(maior,sum[i]);
	}

}

int main()
{
	

	while(scanf("%d",&n) == 1 && n)
	{
		sum.assign(n,0);
		maior = 0;
		seq.clear();

		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			seq.push_back(temp);
		}	

		maximumSum();

		if(maior > 0) printf("The maximum winning streak is %d.\n",maior);
		else printf("Losing streak.\n");

	}

	return 0;
} 
