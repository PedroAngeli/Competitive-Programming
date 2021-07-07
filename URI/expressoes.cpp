#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool valid(string s){
  stack <char> open;
  int n = s.size();

  for(int i=0;i<n;i++){
    char c = s[i];

    if(c == '(' || c == '{' || c == '[')
      open.push(c);
    else{
      if(open.empty())
        return false;
      
      if(c == ')'){
        if(open.top() == '(')
          open.pop();
        else
          return false;
      }

      if(c == '}'){
          if(open.top() == '{')
          open.pop();
        else
          return false;
      }

      if(c == ']'){
        if(open.top() == '[')
          open.pop();
        else
          return false;
      }
    }
  }

  return !open.size();
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  while(n--){
    string s;
    cin >> s;

    if(valid(s))
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}