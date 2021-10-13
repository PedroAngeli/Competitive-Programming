#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  string s1 = "";
  string s2 = "";

  cin >> s;

  bool barra = false;
  for(int i=0;i<s.size();i++){
    if(s[i] == '|'){
      barra = true;
      continue;
    }

    if(barra)
      s2+=s[i];
    else
      s1+=s[i];
  }
  

  string s3;

  cin >> s3;

  int t1 = s1.size();
  int t2 = s2.size();
  int t3 = s3.size();


  if(t1 > t2){
    for(int i=0;i<min(t1-t2,t3);i++)
      s2+=s3[i];

    for(int i=t1-t2;i<t3;i++){
      if(i%2==0)
        s1 += s3[i];
      else
        s2 += s3[i];
    }

    if(s1.size() == s2.size())
      cout << s1 << "|" << s2 << endl;
    else 
      cout << "Impossible" << endl;
  }else if(t2 > t1){
    for(int i=0;i<min(t2-t1,t3);i++)
      s1+=s3[i];

    for(int i=t2-t1;i<t3;i++){
      if(i%2==0)
        s1 += s3[i];
      else
        s2 += s3[i];
    }

    if(s1.size() == s2.size())
      cout << s1 << "|" << s2 << endl;
    else 
      cout << "Impossible" << endl;
  }else{
    for(int i=0;i<t3;i++){
      if(i%2==0)
        s1 += s3[i];
      else
        s2 += s3[i];
    }

    if(s1.size() == s2.size())
      cout << s1 << "|" << s2 << endl;
    else 
      cout << "Impossible" << endl;
  }
  return 0;
}