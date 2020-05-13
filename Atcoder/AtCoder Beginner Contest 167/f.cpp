#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
vector <string> brackets;
int n;
 
bool cmp(string a, string b){
  pair <int,int> cnta = {0,0};
  pair <int,int> cntb = {0,0};
  int n = a.size();
  int m = b.size();

  for(int i=0;i<n;i++)
    if(a[i] == '(')
      cnta.first++;
    else
      cnta.second++;
  for(int i=0;i<m;i++)
    if(b[i] == '(')
      cntb.first++;
    else
      cntb.second++;

  int difa = cnta.first- cnta.second;
  int difb = cntb.first - cntb.second;

  if(difa >= 0 && difb < 0) return true;
  if(difb >= 0 && difa < 0) return false;
  if(difa >= 0 && difb >= 0) return cnta.second < cntb.second;
  return cnta.first > cntb.first;
}
 
bool solve(){
  stack <char> s;
 
  for(int i=0;i<n;i++){
    int m = brackets[i].size();
    for(int j=0;j<m;j++){
      char cur = brackets[i][j];
      if(cur == '(')
        s.push(cur);
      else if(!s.empty())
        s.pop();
      else return false;
    }
  }
 
  return s.size() == 0;
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  brackets.resize(n);
 
  for(int i=0;i<n;i++)
    cin >> brackets[i];
 
  sort(brackets.begin(),brackets.end(),cmp);
 
  if(solve()){
    cout << "Yes" << endl;
  }else
    cout << "No" << endl;
 
 
 
  
  return 0;
}