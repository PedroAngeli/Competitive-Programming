#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  unordered_map <char, int> freq;

  int n = s.size();

  for(int i=0;i<n;i++)
    freq[s[i]]++;

  int cnt = 0;

  for(auto it=freq.begin();it!=freq.end();it++){
    if(it->second % 2 == 1)
      cnt++;
  }

  if(cnt)
  cnt--;

  if(cnt % 2 == 0)
    cout << "First" << endl;
  else
    cout << "Second" << endl;
    
  

  return 0;
}