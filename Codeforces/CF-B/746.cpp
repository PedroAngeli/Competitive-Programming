#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  string s;
  cin >> s;
  string ans;
  ans.resize(n);

  vector <int> idx;
  vector <int> aux;

  for(int i=0;i<n;i++)
    aux.push_back(i);

  while(aux.size()){
    int l = 0;
    int r = aux.size()-1;
    int m = (l+r)/2;
  
    idx.push_back(aux[m]);
    aux.erase(aux.begin()+m);
  }

  for(int i=0;i<n;i++){
    ans[idx[i]] = s[i];
  }
      

  
  cout << ans << endl; 
  return 0;
}