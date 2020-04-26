#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int maxn = 1e2 + 5;
int paga[maxn];
int recebe[maxn];
int saldo[maxn];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  while(m--){
    int a,b,c;
    cin >> a >> b >> c;

    paga[a] += c;
    recebe[b] += c;
  }

  for(int i=1;i<=n;i++)
    saldo[i] = recebe[i] - paga[i];

  int ans = 0;

  for(int i=1;i<=n;i++)
    if(saldo[i] > 0)
      ans += saldo[i];

    cout << ans << endl;
  
  return 0;
}