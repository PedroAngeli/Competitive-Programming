#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int ans;
int v1,v2;
int t,d;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v1 >> v2;
  cin >> t >> d;

  for(int i=0;i<t;i++){
    ans += min(v1 + d*i, v2 + d *(t-i-1));
  }

  cout << ans << endl;
  


  return 0;
}