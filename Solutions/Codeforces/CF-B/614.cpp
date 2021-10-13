#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int isBeautiful(string s){
  int cntOne = 0;
  int cntZero = 0;

  int n = s.size();

  for(int i=0;i<n;i++){
    if(s[i] == '1')
      cntOne++;
    else if(s[i] == '0')
      cntZero++;
    else
      return -1;

    if(cntOne > 1)
      return -1;
  }
  
  return cntZero;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string ans = "";
  string noBeatiful = "";
  int cntZero = 0;

  while(n--){
    string s;
    cin >> s;

    if(s == "0"){
      cout << 0 << endl;
      return 0;
    }

    int ret = isBeautiful(s);
    if(ret == -1)
      noBeatiful = s;
    else
      cntZero += ret;
  }

  if(noBeatiful == ""){
    ans += "1";
  }else{
    ans += noBeatiful;
  }

  while(cntZero--)
      ans+="0";

    cout << ans << endl;
  

  return 0;
}