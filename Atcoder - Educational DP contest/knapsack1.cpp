#include <bits/stdc++.h>

using namespace std;

#define INF 99999999

int N,W;
vector < pair <int,int> > item;
long long int memo[105][100005];

long long int solve(int idx,int w)
{
	if(idx == N || w == 0)
        return 0;

    if(memo[idx][w] != -1){
        return memo[idx][w];
    }

    int peso = item[idx].first;
    int valor = item[idx].second;

    if(peso > w) //não posso pegar o item
        return memo[idx][w] = solve(idx+1,w); 
    else{
       long long int a = valor + solve(idx+1,w - peso); //pego o item
       long long int b = solve(idx+1,w); //não pego o item

        return memo[idx][w] = max(a,b);
    }
}

int main()
{

		scanf("%d %d",&N,&W);

		for(int i=0;i<=N;i++)
			for(int j=0;j<=W;j++)
				memo[i][j] = -1;

		for(int i=0;i<N;i++){
            int v,w;
			scanf("%d %d",&w,&v);
			item.push_back({w,v});
        }
       
		printf("%lld\n",solve(0,W));
	
	return 0;
} 