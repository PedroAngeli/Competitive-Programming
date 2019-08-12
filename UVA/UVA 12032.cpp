#include <cstdio>
#include <vector>

using namespace std;

vector <int> rung;
int n;

bool can(int p)
{
	int i;

	for(i=0;i<n;i++)
	{
		if((rung[i] - rung[i-1]) == p) p--;
		else if((rung[i] - rung[i-1]) > p) return false;
	}

	return true;
}

int solve()
{
	int l=1,r=10000000;
	int ans;
	int m;

	while(l<=r)
	{
		m=(l+r)/2;
		if(can(m))
		{
			r = m - 1;
			ans = m;
		}
		else l = m + 1;	
	}
		
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	int caso = 1;
	while(t--)
	{
		printf("Case %d: ",caso++);
		scanf("%d",&n);
		rung.clear();
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			rung.push_back(tmp);
		}

		printf("%d\n",solve());
	}

	return 0;
} 
