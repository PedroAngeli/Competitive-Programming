#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

string s;
vector <int> idx;
vector <vector <int> > dp;

int solve(int i,int j){
  if(i >= j)
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  if(s[i] == s[j])
    return dp[i][j] = solve(i+1,j-1);
  else
    return dp[i][j] = 1 + min(solve(i+1,j),solve(i,j-1));
}

void constructPal(int i,int j){
  if(i == j){
    idx.push_back(i);
    return;
  }
  if(i > j)
    return;

  if(s[i] == s[j]){
    idx.push_back(i);
    constructPal(i+1,j-1);
  }else if(dp[i][j] == 1 + dp[i+1][j]){
    idx.push_back(i);
    constructPal(i+1,j);
  }else{
    idx.push_back(j);
    constructPal(i,j-1);
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 

  while(cin >> s){
    int n = s.size();
    dp.assign(n,vector <int>(n,-1));
    idx.clear();
    int ans = solve(0,n-1);
    cout << ans << " ";

    constructPal(0,n-1);

    for(int i=0;i<idx.size();i++)
      cout << s[idx[i]];
    int d = (n+ans)%2 == 1 ? 1 : 0;
    for(int i=idx.size()-1-d;i>=0;i--)
      cout << s[idx[i]];
    cout << endl;
  } 
  
  return 0;
}