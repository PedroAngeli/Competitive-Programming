#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2*1e5 + 5;
int to[nax];
bool vis[nax];
int order[nax];
long long cycleSize;
int beginCycle;
long long n, k;


void solve(int u, int o){
  while(to[u]){
    if(order[u]){
      cycleSize = o-order[u];
      beginCycle = u;
      break;
    }
    order[u] = o++;
    u = to[u];
  }

  u = 1;
  long long cnt = 0;

  if(beginCycle){
     while(u != beginCycle && k){
       u = to[u];
       k--;
     }
     k = k%cycleSize;
  }
  
  while(cnt < k){
      u = to[u];
      cnt++;
  }

  cout << u << endl;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;

  for(int i=1;i<=n;i++){
    int a;
    cin >> a;
    to[i] = a;
  }

  solve(1,1);


 
  
  return 0;
}