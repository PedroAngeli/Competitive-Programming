#include <cstdio>
#include <stack>
#include <vector>

using namespace std;


int main()
{
	int n;
	
	while(scanf("%d",&n) == 1 && n)
	{
		int num = 1;
		int aux = 1;

		while(true)
		{
			vector <int> req;
			stack <int> station;

			for(int i = 0; i < n;i++)
			{
				scanf("%d",&num);
				if(num == 0)
				{
					aux=0;
					break;
				}
				req.push_back(num);
			}
			
			if(aux == 0) break;

			int r = 0, o = 1;
	
			while(r < n && o <= n)
			{
				while(station.empty() || (o != req[r] && o <= n && station.top()!=req[r]))
					station.push(o++);

				if(o == req[r]) station.push(o++);
				
				while(!station.empty() && req[r] == station.top())
				{
					station.pop();
					r++;
				}
			}

			//printf("%d\n",r);
			if(r == n) printf("Yes\n");
			else printf("No\n");				
		}

		printf("\n");
	}



}
