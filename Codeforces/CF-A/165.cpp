#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,k;

bool can(int v){
  int tam = log2(v)/log2(k);
  int sum = 0;

  for(int i=0;i<=tam;i++)
    sum += (v/pow(k,i));

  return sum >= n;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  int l = 0;
  int r = n;
  int ans = 1e9 + 7;

  while(l <= r){
    int m = (l+r)/2;

    if(can(m)){
      ans = min(ans,m);
      r = m-1;
    }else{
      l = m+1;
    }
  }

  cout << ans << endl;

  return 0;
}