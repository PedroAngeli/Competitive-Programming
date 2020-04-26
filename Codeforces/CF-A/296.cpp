#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[1001];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  
  int maior = 0;

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    maior = max(maior,++cnt[x]);
  }

  if(maior > n-maior + 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;


  return 0;
}