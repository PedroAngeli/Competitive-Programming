#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

string s;
pair <int,string> dp[1005][1005];

pair <int,string> solve(int i,int j){
  if(i == j)
    return {1,string(1,s[i])};
  if(i > j)
    return {0,""};

  if(dp[i][j].first != -1)
    return dp[i][j];
  
  if(s[i] == s[j]){
    pair <int,string> ret = solve(i+1,j-1);
    return dp[i][j] = {2 + ret.first,s[i] + ret.second + s[j]};
  }

  pair <int,string> a = solve(i+1,j);
  pair <int,string> b = solve(i,j-1);
  
  if(a.first > b.first)
    return dp[i][j] = a;
  if(b.first > a.first)
    return dp[i][j] = b;

  return dp[i][j] = a.second < b.second ? a : b;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  while(cin >> s){
    int len = s.size();
    for(int i=0;i<len;i++){
      for(int j=0;j<len;j++)
        dp[i][j].first = -1;
    }
    pair <int,string> ans = solve(0,len-1);
    cout << ans.second << endl;
  }
  
  return 0;
}