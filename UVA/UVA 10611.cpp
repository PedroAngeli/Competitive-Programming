#include <set>
#include <cstdio>

using namespace std;


int main()
{
	int n;

	scanf("%d",&n);

	set <int> conj;
	set <int> :: iterator it;
	set <int> :: iterator it1;
	set <int> :: iterator it2;

	int temp;

	while(n--) 
	{
		scanf("%d",&temp);
		conj.insert(temp);
	}

	int q;
	
	scanf("%d",&q);
	
	it = conj.end();
	it--;
	
	while(q--)
	{
		scanf("%d",&temp);
	
		it1 = conj.lower_bound(temp);
		it2 = conj.upper_bound(temp);
		
		
		if(it1 != conj.begin() && *it1 >= temp) 
		{
			it1--;
			printf("%d ",*it1);
		}
		else if(it1 == conj.end()) printf("%d ",*it);
		else printf("X ");


		if(*it2 > temp) printf("%d\n",*it2);
		else printf("X\n");
	}

	return 0;
}
