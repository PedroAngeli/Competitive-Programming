#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9 + 5;

vector <int> h;
vector <int> dp;
int n;

int main(){

    scanf("%d",&n);
    dp.assign(n,INF);
    
    for(int i=0;i<n;i++){
        int height;
        scanf("%d",&height);
        h.push_back(height);
    }

    dp[0] = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1; j<=i+2; j++){
            if(j < n){
                dp[j] = min(dp[j],dp[i] + abs(h[i] - h[j]));
            }
        }
    }

    printf("%d\n",dp[n-1]);
    return 0;
}