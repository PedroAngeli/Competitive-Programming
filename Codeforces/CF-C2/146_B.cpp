#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int mask(int x){
  string s = to_string(x);
  string ans;
  for(int i=0;i<s.size();i++)
    if(s[i] == '4' || s[i] == '7')
      ans.push_back(s[i]);
  
  if(ans.size() == 0)
    return 0;

  int ret = stoi(ans);
  return ret;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int a,b;
  cin >> a >> b;
  const int nax = 177777;

  for(int i=a+1;i<=nax;i++){
    if(mask(i) == b){
      cout << i << endl;
      return 0;
    }
  }


  return 0;
}