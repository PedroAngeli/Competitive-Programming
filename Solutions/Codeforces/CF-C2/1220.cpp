#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool cnt[26];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string s;
  cin >> s;
  int n = s.size();
  for(int i=0;i<n;i++){
    bool ann = false;
    for(int j=(s[i]-'a'-1);j>=0;j--){
      if(cnt[j]){
        ann = true;
        break;
      }
    }
    if(ann){
      cout << "Ann" << endl;
    }
    else
      cout << "Mike" << endl;
    cnt[s[i]-'a'] = true;
  }
  return 0;
}