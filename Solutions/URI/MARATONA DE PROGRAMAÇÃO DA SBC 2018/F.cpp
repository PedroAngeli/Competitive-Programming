#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef struct{
  int ti,tf,o,stage;
}Show;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector <Show> shows;

  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    while(m--){
      Show s;
      cin >> s.ti >> s.tf >> s.o;
      s.stage = i;
      shows.push_back(s);
    }
  }

  sort(shows.begin(),shows.end(),[&](auto s1,auto s2){
    return s1.ti < s2.ti || (s1.ti == s2.ti && s1.tf < s2.tf);
  });

  int len = shows.size();
  vector <int> to(len+1,len);

  for(int i=0;i<len;i++){
    for(int j=i;j<len;j++){
      if(shows[i].tf <= shows[j].ti){
        to[i] = j;
        break;
      }
    }
  }
  const int INF = 1e9; + 7;
  vector <vector <int> > dp(len+1,vector <int>(1 << n,-INF));
  dp[0][0] = 0;

  for(int i=0;i<len;i++){
    int stage = shows[i].stage;
    int o = shows[i].o;

    for(int mask=0;mask<(1 << n);mask++){
      dp[i+1][mask] = max(dp[i+1][mask],dp[i][mask]);
      dp[to[i]][mask | (1 << stage)] = max(dp[to[i]][mask | (1 << stage)],dp[i][mask]+o);
    }
  }

  int ans = dp[len][(1 << n)-1];


  if(ans < 0)
    ans = -1;
  cout << ans << endl;
  

  return 0;
}