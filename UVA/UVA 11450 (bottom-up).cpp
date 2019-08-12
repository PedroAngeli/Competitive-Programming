#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector <vector <int> > price;
bool dp[20][201];
int m,c,k;

int solve()
{
	for(int i=0;i<price[0].size();i++)
	{
		int pos = m - price[0][i];
		if(pos >= 0) dp[0][pos] = true;
	}

	for(int i=1;i<c;i++)
		for(int j=0;j<m;j++)
			if(dp[i-1][j])
				for(int l = 0;l<price[i].size();l++)
				{
					int pos = j - price[i][l];
					//printf("%d\n",pos);
					if(pos >= 0) dp[i][pos] = true;
				}

	int ans = -1;

	for(int i = 0;i<m;i++)
		if(dp[c-1][i])
		{
			ans = m - i;
			break;
		}

	return ans;	
}

int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d",&m,&c);	
		price.clear();
		memset(dp,false,sizeof dp);
		for(int i=0;i<c;i++)
		{
			vector <int> vet;
			scanf("%d",&k);

			for(int j=0;j<k;j++)
			{
				int temp;
				scanf("%d",&temp);
				vet.push_back(temp);
			}
			price.push_back(vet);
		}

		int ans = solve();

		if(ans != -1) printf("%d\n",ans);
		else printf("no solution\n");
		
	}


	return 0;
}
