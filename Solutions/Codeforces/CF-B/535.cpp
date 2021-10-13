#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

string s;
int cnt;

bool solve(int i,int n,string cur){
  if(i == n){
    cnt++;
    if(cur == s)
      return true;
    return false;
  }

  bool a = solve(i+1,n,cur + "4");

  if(a)
    return a;

  bool b = solve(i+1,n,cur + "7");

  return b;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> s;

  int n = s.size();

  int ans = 0;

  for(int i=1;i<n;i++)
    ans += pow(2,i);

  string cur = "";
  solve(0,n,cur);

  ans += cnt;

  cout << ans << endl;

  
  return 0;
}