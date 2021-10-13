#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e5 + 5;

int main(){

  int n,k;

  cin >> n >> k;
  
  vector <pair <int,int> > seg[MAXN];
  vector <int> ans;

  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    seg[l].push_back(make_pair(r,i));
  }

  set <pair <int,int> > conj;

  for(int i=1;i<MAXN;i++){
    for(auto &ele:seg[i]){
      conj.insert(ele);
    }

    while(true){
      if(conj.empty() || conj.begin()->first >= i)
        break;
      conj.erase(conj.begin());
    }

    while(conj.size() > k){
      int idx = conj.rbegin()->second;
      ans.push_back(idx);
      conj.erase(*conj.rbegin());
    }  
  }

  cout << ans.size() << endl;

  for(int i=0;i<ans.size();i++)
    cout << ans[i]+1 << " ";

  cout << endl;

  return 0;
}