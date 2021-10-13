#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  int k;
  cin >> k >> s;

  for(int i=0;i<min((int)s.size(),k);i++)
    cout << s[i];

  if(s.size() > k)
    cout << "...";

  cout << endl;
  

  return 0;
}