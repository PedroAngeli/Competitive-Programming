#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int n;

  cin >> n;

  int x;
   
  cin >> x;

  bool ans = true;

  while(n--){
    int l,r;
    cin >> l >> r;
    int temp = 7-x;
    if(x == l || x == r || x == 7-l || x == 7-r || temp == l || temp == r || temp == 7-l || temp == 7-r)
      ans = false;

    x = 7-x;
  }

  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}