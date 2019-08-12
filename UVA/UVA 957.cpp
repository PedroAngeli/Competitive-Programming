#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;



int main()
{
	int y;

	while(scanf("%d",&y) == 1)
	{
		int p,temp;
		vector <int> years;

		scanf("%d",&p);

		while(p--) 
			scanf("%d",&temp) , years.push_back(temp);

		vector <int> :: iterator it = years.begin();
		
		int maior = 0;
		int f,l;
		int dist;

		for(;it!=years.end();it++)
		{
			int ano = *it + y - 1;
			
			vector <int> :: iterator up = upper_bound(it,years.end(),ano);

			dist = up - it;
			
			--up; 

			if(dist > maior) 
				maior = dist, f = *it, l = *up;
			
		}
		
		printf("%d %d %d\n",maior,f,l);
	}
	

	return 0;
}
