#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

string s1,s2;
int cnt;
int expected;

int finalPosition(){
  int pos = 0;

  for(int i=0;i<s1.size();i++){
    if(s1[i] == '+')
      pos++;
    else
      pos--;
  }

  return pos;
}

void possibilities(int idx,int pos){
  if(idx == s2.size()){
    if(pos == expected)
      cnt++;
    
    return;
  }

  if(s2[idx] == '+')
    possibilities(idx+1,pos+1);
  else if(s2[idx] == '-')
    possibilities(idx+1,pos-1);
  else{
    possibilities(idx+1,pos+1);
    possibilities(idx+1,pos-1);
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin >> s1 >> s2;

  expected = finalPosition();
  int question = 0;

  for(int i=0;i<s2.size();i++)
    if(s2[i] == '?')
      question++;

  possibilities(0,0);

  cout << fixed << setprecision(15) << (double)cnt/pow(2,question) << endl;



  return 0;
}