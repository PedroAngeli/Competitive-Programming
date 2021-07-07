#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

string s;

int solve(int l,int r,char c){
  if(l == r){
    return s[l] != c;
  }

  int m = l + (r-l+1)/2;

  int cnt1 = 0;
  for(int i=l;i<m;i++)
    cnt1 += s[i]!=c;

  int a = cnt1 + solve(m,r,c+1);

  int cnt2 = 0;
  for(int i=m;i<=r;i++)
    cnt2 += s[i]!=c;
  
  int b = cnt2 + solve(l,m-1,c+1);

  return min(a,b);
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cin >> s;
    int ans = solve(0,n-1,'a');
    cout << ans << endl;
  }
    
  return 0;
}