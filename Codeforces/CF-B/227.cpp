#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int vet[n+1];

  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    vet[a] = i;
  }

  int m;
  cin >> m;

  long long ans1 = 0;
  long long ans2 = 0;

  while(m--){
    int a;
    cin >> a;

    int idx = vet[a];

    ans1 += idx+1;
    ans2 += n - idx;
  }

  cout << ans1 << " " << ans2 << endl;

  return 0;
}