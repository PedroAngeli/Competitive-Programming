#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int n;

	while(scanf("%d",&n) == 1 && n)
	{	
		long long unsigned int soma = 0;
		int k,bill;
		multiset <int> conj;
		set <int> :: iterator beg,end;

		while(n--)
		{
			scanf("%d",&k);

			while(k--)
			{
				scanf("%d",&bill);
				conj.insert(bill);
			}

			if(conj.size() > 1)
			{
				beg = conj.begin();
				end = conj.end();
				end--;
				soma+=(*end-*beg);

				conj.erase(beg);
				conj.erase(end);
			}
		}

		printf("%llu\n",soma);
		
	}

	return 0;
}
