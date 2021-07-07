#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;

  cin >> n >> m >> k;

  vector <long long> prefA(n+1,0);
  vector <long long> prefB(m+1,0);
  
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    prefA[i+1] = prefA[i] + x; 
  }
  
  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    prefB[i+1] = prefB[i] + x; 
  }

  int ans = 0;

  for(int i=0;i<=n;i++){
    if(k < prefA[i])
      continue;
    
    long long rest = k-prefA[i];
    int j = upper_bound(prefB.begin(),prefB.end(),rest) - prefB.begin()-1;

    ans = max(ans,i+j);
  }

  cout << ans << endl;

  return 0;
}