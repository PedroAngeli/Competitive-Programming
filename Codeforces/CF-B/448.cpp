#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long mod = 1e9 + 7;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s,t;
  cin >> s >> t;

  int i = 0;
  int j = 0;

  while(i < s.size() && j < t.size()){
    if(s[i] == t[j]){
      j++;
    }
    i++;
  }
  
  if(j == t.size()){
    cout << "automaton" << endl;
  }else{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if(s == t){
      cout << "array" << endl;
    }else{
       int i = 0;
      int j = 0;

      while(i < s.size() && j < t.size()){
        if(s[i] == t[j]){
          j++;
        }
        i++;
      }

      if(j == t.size()){
        cout << "both" << endl;
      }else{
        cout << "need tree" << endl;
      }
    }
  }
    
  
  return 0;
}