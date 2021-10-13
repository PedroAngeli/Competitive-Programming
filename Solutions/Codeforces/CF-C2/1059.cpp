#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <int> ans;

void solve(int n,int cur){
  if(n == 1)
    ans.push_back(cur);
  else if(n == 2)
    ans.push_back(cur),ans.push_back(cur*2);
  else if(n == 3)
    ans.push_back(cur),ans.push_back(cur),ans.push_back(cur*3);
  else{
    int o = (n+1)/2;
    for(int i=0;i<o;i++)
      ans.push_back(cur);
    solve(n/2,cur*2);
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  solve(n,1);
  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;  
  return 0;
}