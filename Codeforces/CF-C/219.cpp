#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;
  long long d;

  cin >> n >> d;
  long long mn = n-d;

  string s  = to_string(n);
  string t = to_string(mn);

  while(t.size() < s.size()){
    auto it = t.begin();
    t.insert(it,'0');
  }

  int i = t.size() - 1;
  string ans = "";
  ans += t;

  while(i >= 0){
    char l = '0';
    char r = '9';
    char mx = 0;

    string temp = ans;
   
    while(l <= r){
      char m = (l+r)/2;
      temp[i] = m;
      if(temp >= t && temp <= s)
        l = m+1, mx = max(mx, m);
      else if(temp < t)
        l = m+1;
      else
        r = m-1;
    }
    ans[i] = mx;
    i--;
  }

  i = 0;
  while(ans[i] == '0')
   i++;

  while(i < ans.size())
    cout << ans[i++];

  cout << endl;

  return 0;
}