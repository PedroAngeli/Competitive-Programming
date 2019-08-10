#include <bits/stdc++.h>

using namespace std;

int M,C;
vector <int> prices[25];
int memo[25][205];

int solve(int idx, int m){

    if(idx == C)
        return M-m;

    if(memo[idx][m] != -1)
        return memo[idx][m];

    int resp = -1;

    for(int i=0;i<prices[idx].size();i++){

        if(prices[idx][i] <= m){
            resp = max(resp,solve(idx+1, m-prices[idx][i]));
        }
    }

    return memo[idx][m] = resp;
}


int main()
{
    int N;
    scanf("%d",&N);

    while(N--){
        scanf("%d %d",&M,&C);

        for(int i=0;i<=C;i++){
            for(int j=0;j<=M;j++){
                memo[i][j] = -1;
            }
        }
        
        for(int i=0;i<C;i++)
            prices[i].clear();

        for(int i=0;i<C;i++){

            int k;
            scanf("%d",&k);

            for(int j=0;j<k;j++){

                int p;
                scanf("%d",&p);
                prices[i].push_back(p);
            }
        }

        int resp = solve(0,M);

        if(resp == -1)
            printf("no solution\n");

        else 
            printf("%d\n", resp);
    }
	
	return 0;
} 
