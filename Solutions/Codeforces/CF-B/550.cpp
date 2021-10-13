#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <int> a;
int n,l,r,x;
int ans;
const int INF = 1e6 + 5;

void solve(int i, int total, int menor, int maior){
  
  if(i == n){
    if(total >= l && total <= r && (maior - menor) >= x)
      ans++;

    return;
  }

  solve(i+1,total,menor,maior);

  if(menor > a[i])
    menor = a[i];
  if(maior < a[i])
    maior = a[i];

  solve(i+1,total+a[i],menor,maior);
}

int main(){
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> n >> l >> r >> x;

  a.resize(n);

  for(int i=0;i<n;i++)
    cin >> a[i];

  solve(0, 0, INF,-1);

  cout << ans << endl;
  
  return 0;
}