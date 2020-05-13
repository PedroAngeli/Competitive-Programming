#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
vector <string> op;
string ans;

string solve(int i,int a,int b, int c){
  if(a < 0 || b < 0 || c < 0)
    return "No";

  if(i == n){
    return "";
  }

  char op1 = op[i][0];
  char op2 = op[i][1];
  string ret;

  if(op1 == 'A' && op2 == 'B'){
    ret = solve(i+1,a+1,b-1,c);
    if(ret != "No")
      return "A" + ret;
    ret = solve(i+1,a-1,b+1,c);
    if(ret != "No")
      return "B" + ret;

    return ret;
  }

  if(op1 == 'A' && op2 == 'C'){
    ret = solve(i+1,a+1,b,c-1);
    if(ret != "No")
      return "A" + ret;
    ret = solve(i+1,a-1,b,c+1);
    if(ret != "No")
      return "C" + ret;
    
    return ret;
  }

  ret = solve(i+1,a,b+1,c-1);
  if(ret != "No")
    return "B" + ret;
  ret = solve(i+1,a,b-1,c+1);
  if(ret != "No")
    return "C" + ret;

  return ret;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int a,b,c;
  cin >> n >> a >> b >> c; 
  
  op.resize(n);

  for(int i=0;i<n;i++)
    cin >> op[i];

  string ans = solve(0,a,b,c);
  if(ans != "No"){
    cout << "Yes" << endl;
    for(int i=0;i<n;i++)
      cout << ans[i] << endl;
  }
  else
    cout << ans << endl;
  return 0;
}