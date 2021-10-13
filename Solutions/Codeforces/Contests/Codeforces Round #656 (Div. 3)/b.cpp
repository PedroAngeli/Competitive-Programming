#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector <int> merge;
    for(int i=0;i<2*n;i++){
      int x;
      cin >> x;
      merge.push_back(x);
    }  
    vector <bool> vis(n+1,false);
    vector <int> ans;
    for(int i=0;i<2*n;i++){
      if(!vis[merge[i]]){
        vis[merge[i]] = true;
        ans.push_back(merge[i]);
      }
    }

    for(int i=0;i<n;i++)
      cout << ans[i] << " ";
    cout << endl;
  }
    
  return 0;
}