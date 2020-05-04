#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e4 + 5;
int n,k;
int vet[nax];
const int INF = 1e9 + 7;

int solve(int l,int r,int qtd){
  if(l > r)
    return qtd;

  if(qtd > k)
    return INF;

  if(vet[l] == vet[r])
    return solve(l+1,r-1,qtd);
  else
    return min(solve(l+1,r,qtd+1),solve(l,r-1,qtd+1));
}


int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  int ncase = 1;

  while(t--){
    cin >> n >> k;
  
    for(int i=0;i<n;i++)
      cin >> vet[i];
    int d = solve(0,n-1,0);

    cout << "Case " << ncase++ << ": ";

    if(d == 0)
      cout << "Too easy" << endl;
    else if(d <= k)
      cout << d << endl;
    else
      cout << "Too difficult" << endl;
  }
  
  
  return 0;
}