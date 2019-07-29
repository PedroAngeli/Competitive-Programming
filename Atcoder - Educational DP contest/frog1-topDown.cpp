#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 1e9 + 5;

vector <int> h;
vector <int> dp;
int n;

int solve(int idx){

    if(dp[idx] != INF)
        return dp[idx];

    int a = 0;

    if((idx + 1) < n){
        a = solve(idx+1) + abs(h[idx]-h[idx+1]);
    } 

    int b = INF;

    if((idx + 2) < n){
        b = solve(idx+2) + abs(h[idx]-h[idx+2]);
    }


    return dp[idx] = min(a,b);
}

int main(){

    scanf("%d",&n);
    dp.assign(n,INF);
    
    for(int i=0;i<n;i++){
        int height;
        scanf("%d",&height);
        h.push_back(height);
    }

    printf("%d\n",solve(0));

    return 0;
}