#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[4];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;

  for(int j=0;j<n;j++){
    for(int i=0;i<k;i++){
      if(i + j == n)
        break;
      cout << (char)('a'+i);
    }
    j+=(k-1);
  }

  cout << endl;
  return 0;
}