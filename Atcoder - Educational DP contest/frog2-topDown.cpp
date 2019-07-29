#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;

vector <int> h;
vector <int> dp;
int n;
int k;

int solve(int idx){

    if(dp[idx] != INF){
        return dp[idx];
    }
    
    int menor = INF;

    for(int i=1;i<=k;i++){
        
        if(idx + i < n){
            menor = min(menor, solve(idx+i) + abs(h[idx] - h[idx+i]));
        }else{
            if(i==1) return 0;
            else return dp[idx] = min(menor,INF);
        }
    }


    return dp[idx] = menor;


}

int main(){

    scanf("%d",&n);
    scanf("%d",&k);
    dp.assign(n,INF);
    
    for(int i=0;i<n;i++){
        int height;
        scanf("%d",&height);
        h.push_back(height);
    }

    printf("%d\n",solve(0));

    return 0;
}