#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int ca,cb,n;
bool vis[1005][1005];

bool solve(int i,int j,vector <string> &ans,int id){
  if(vis[i][j] || i < 0 || j < 0 || i > ca || j > cb)
    return false;

  vis[i][j] = true;

  if(j == n || i == n){
    for(int k=0;k<id;k++)
      cout << ans[k] << endl;
    cout << "success" << endl;
    return true;
  }
  
  bool a = false;

  ans[id] = "empty A"; a = solve(0,j,ans,id+1);

  if(!a){
     ans[id] = "fill A"; a = solve(ca,j,ans,id+1);
  }

  if(!a){
    ans[id] = "pour A B";
    int w = min(i,cb-j);
    a = solve(i-w,j+w,ans,id+1);
  } 
  if(!a){
    ans[id] = "empty B"; a = solve(i,0,ans,id+1);
  } 
  if(!a){
    ans[id] = "fill B"; a = solve(i,cb,ans,id+1);
  } 
  if(!a){
    ans[id] = "pour B A";
    int w = min(j,ca-i); 
    a = solve(i+w,j-w,ans,id+1);
  } 

  return a;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  vector <string> ans(1000005);

  while(cin >> ca >> cb >> n){
    memset(vis,false,sizeof vis);
    solve(0,0,ans,0);
  }
  
  

  return 0;
}