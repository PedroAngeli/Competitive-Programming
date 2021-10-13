#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isGood(int a,int k){
  set <int> s;
    
  while(a > 0){
    int dig = a%10;
    a = a/10;

    if(dig <= k)
      s.insert(dig);
  }

  return s.size() == (k + 1);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  int ans = 0;

  while(n--){
    int a;
    cin >> a;

    if(isGood(a,k))
      ans++;
  }

  cout << ans << endl;

  return 0;
}