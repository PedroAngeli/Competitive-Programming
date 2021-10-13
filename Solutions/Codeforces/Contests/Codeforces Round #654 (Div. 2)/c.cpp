#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    long long a,b,n,m;
    cin >> a >> b >> n >> m;
    if(a+b < n+m){
      cout << "No" << endl;
    }else if(a > b){
      if(b >= m)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }else{
      if(a >= m)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }

  return 0;
}