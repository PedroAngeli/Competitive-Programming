#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

char forb[26];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  int k;
  cin >> k;
  vector <pair <char,char> > p(k);

  for(int i=0;i<k;i++){
    char c1,c2;
    cin >> c1 >> c2;
    if(c1 > c2)
      swap(c1,c2);
     forb[c1-'a']=c2;
  }

  vector <pair <int,char> > t;

  for(int i=0;i<n;i++){
    int cnt = 1;
    while(i < n-1 && s[i] == s[i+1])
      i++,cnt++;
    t.push_back({cnt,s[i]});
  }

  int len = t.size();
  int ans = 0;

  for(int i=0;i<len-1;i++){
    char c1 = t[i].second;
    char c2 = t[i+1].second;

    if(c1 > c2)
      swap(c1,c2);

    bool isForbidden = forb[c1-'a'] == c2;

    if(isForbidden){
       c1 = t[i].second;
     c2 = t[i+1].second;
      int cnt1 = t[i].first;
      int cnt2 = t[i+1].first;
      i+=2;

      while(i < len && (t[i].second == c1 || t[i].second == c2)){
        if(t[i].second == c1)
          cnt1 += t[i].first;
        else
          cnt2 += t[i].first;
        i++;
      }
      i--;
      ans += min(cnt1,cnt2);
    }
  }

  cout << ans << endl;

  
 
  return 0;
}