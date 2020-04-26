#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool isNice(string temp,string &s){
  set <char> c;

  for(int j=0;j<26;j++){
    if(temp[j] >= 'A' && temp[j] <= 'Z')
      c.insert(temp[j]);
  }

  if(c.size() == 26){
    for(int i=0;i<s.size();i++)
      if(s[i] == '?')
        s[i] = 'A';
    
    return true;
  }

  return false;
}

bool canBeNice(string temp,int l,int r,string &s){
  set <char> c;
  int cnt = 0;

  for(int j=0;j<26;j++){
    if(temp[j] >= 'A' && temp[j] <= 'Z')
      c.insert(temp[j]);
    else{
      cnt++;
    }
  }

  if(cnt + c.size() == 26){
    for(int i = l;i<=r;i++){
      if(s[i] == '?'){
        for(int j = 0;j<26;j++){
          if(!c.count('A'+j)){
            s[i] = 'A' + j;
            c.insert(s[i]);
            break;
          }
        }
      }
    }

    for(int i=0;i<s.size();i++)
      if(s[i] == '?')
        s[i] = 'A';
    return true;

  }

  return false;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();

  for(int i=0;i<n-25;i++){
    string temp(s.begin()+i,s.begin()+i+26);
    if(isNice(temp,s)){
      cout << s << endl;
      return 0;
    }else if(canBeNice(temp,i,i+25,s)){
      cout << s << endl;
      return 0;
    }
  }

  cout << -1 << endl;
  
  return 0;
}