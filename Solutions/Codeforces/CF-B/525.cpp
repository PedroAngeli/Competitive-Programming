#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2*1e5 + 5;
int freq[nax];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  
  int n = s.size();

  int m;
  cin >> m;

  while(m--){
    int a;
    cin >> a;
    freq[a]++;
  }

  for(int i=2;i<=n/2;i++){
    freq[i] += freq[i-1];
  }

  int i = n/2 - 1;

  string ans;
  ans.resize(n);

  if(n % 2 == 1)
    ans[n/2] = s[n/2];

  while(i >= 0){
    int cur = freq[i+1];
    int l = i;
    int r = n-i-1;

    if(cur % 2 == 0){
      ans[l] = s[l];
      ans[r] = s[r];
    }else{
      ans[l] = s[r];
      ans[r] = s[l];
    }
    
    i--;
  }
    
  cout << ans << endl;

  return 0;
}