#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


typedef struct{
  int ti,tf,o,stage;
}Show;

const int INF = 1e9 + 7;
vector <int> to;
vector <vector <int>> dp;
int n;
int qtdShows;
vector <Show> shows;

int solve(int i,int mask){
  if(i == qtdShows && mask == ((1 << n)-1))
    return 0;
  
  if(i == qtdShows)
    return -INF;

  int& state = dp[i][mask];
  if(state != -1)
    return state;

  int a = solve(i+1,mask);
  int b = shows[i].o + solve(to[i], mask | (1 << shows[i].stage));

  state = max(a,b);

  return state;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    qtdShows += m;
    while(m--){
      Show s;
      cin >> s.ti >> s.tf >> s.o;
      s.stage = i;
      shows.push_back(s);
    }
  }
  dp.assign(qtdShows,vector <int>(1 << n,-1));

  sort(shows.begin(),shows.end(),[&](Show s1,Show s2){
    return s1.ti < s2.ti || (s1.ti == s2.ti && s1.tf < s2.tf);
  });

  int len = shows.size();
  to.assign(len+1,len);

  for(int i=0;i<len;i++){
    for(int j=i;j<len;j++){
      if(shows[i].tf <= shows[j].ti){
        to[i] = j;
        break;
      }
    }
  }
  
  int ans = solve(0,0);

  if(ans < 0)
    ans = -1;

  cout << ans << endl;
  

  return 0;
}