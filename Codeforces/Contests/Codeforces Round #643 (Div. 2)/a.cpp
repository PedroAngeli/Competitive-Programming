#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

pair <int,int> digs(long long n){
  int mx = 0;
  int mn = 10;

  while(n){
    int dig = n%10;
    mx = max(dig,mx);
    mn = min(dig,mn);
    n /=10;
  }

  return {mx,mn};
}
int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    long long n,k;
    cin >> n >> k;
    
    bool printed = false;

    for(int i=0;i<k-1;i++){
      pair <int,int> dig = digs(n);
      n += (dig.first * dig.second);
      if(dig.second == 0){
        cout << n << endl;
        printed = true;
        break;
      }
    }

    if(!printed)
      cout << n << endl;

  }

  return 0;
}