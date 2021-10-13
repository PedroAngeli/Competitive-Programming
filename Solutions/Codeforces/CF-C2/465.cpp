#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  int n,p;
  string s;

  cin >> n >> p;
  cin >> s;

  char limit = 'a'+p;
  bool can = false;
  s[n-1]++;
  int i;
  
  for(i=n-1;i>=0 && i<n;){
    if(s[i] == limit){
      s[i] = 'a';
      i--;
      s[i]++;
    }else if((i>0 && s[i] == s[i-1]) || (i>1 && s[i] == s[i-2])){
      s[i]++;
    }else{
      i++;
    }
  }

  if(i == -1)
    cout << "NO" << endl;
  else
    cout << s << endl;
  

  return 0;
}