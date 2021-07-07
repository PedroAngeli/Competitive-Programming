#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int dist[25][25];
int dp[(1 << 24)];
int parent[(1 << 24)];
int x[25],y[25];

int squared(int x){
  return x*x;
}

int main(){
 
  int xi,yi;
  scanf("%d %d",&x[0],&y[0]);

  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d %d",&x[i],&y[i]);
    for(int j=i-1;j>=0;j--)
      dist[i][j] = dist[j][i] = squared(x[i]-x[j])+squared(y[i]-y[j]);
  }

  memset(dp,0x3f,sizeof dp);
  dp[0] = 0;

  for(int mask=0;mask<(1 << n)-1;mask++){
    for(int i=0;i<n;i++){
      if(!(mask & (1 << i))){
        for(int j=i;j<n;j++){
          if(!(mask & (1 << j))){
            int nextMask = mask | (1 << i) | (1 << j);
            int val = dp[mask] + dist[0][i+1] + dist[i+1][j+1] + dist[j+1][0];
            if(dp[nextMask] > val){
              dp[nextMask] = val;
              parent[nextMask] = mask;
            }
          }
        }
        break;
      }
    }
  }

  printf("%d\n0",dp[(1 << n)-1]);
  int u = (1 << n)-1;

  while(u){
    int v = parent[u] ^ u;
    while(v){
      int lsb = v & (-v);
      printf(" %d",int(log2(lsb)+1));
      v -= lsb;
    }
    printf(" 0");
    u = parent[u];
  }

  printf("\n");
  return 0;
}