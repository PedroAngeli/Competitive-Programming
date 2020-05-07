#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e6 + 5;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int order[nax];
  int ans[n+1];
  multiset <int> conj;
  vector <int> aux;
  int N = n;
  while(N--){
    int a,b;
    cin >> a >> b;
    order[a] = b;
    aux.push_back(a);
    conj.insert(b);
  }

  

  int s = 0;
  for(int i=2;i<=n;i+=2){
    ans[i] = order[s];
    s = order[s];
  }

  int f;

  for(int i=0;i<n;i++)
    if(conj.count(aux[i]) == 0){
      f = aux[i];
      break;
    }
    ans[1] = f;
    for(int i=3;i<=n;i+=2){
      ans[i] = order[f];
      f = order[f];
    }
  

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";
  cout << endl;  
  return 0;
}