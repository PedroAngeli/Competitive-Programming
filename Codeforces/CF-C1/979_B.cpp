#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int turns[3];
  turns[0] = turns[1] = turns[2] = n;

  string s0,s1,s2;
  cin >> s0 >> s1 >> s2;

  unordered_map <char, int> cnt[3];

  int len = s0.size();
  for(int i=0;i<len;i++){
    cnt[0][s0[i]]++;
    cnt[1][s1[i]]++;
    cnt[2][s2[i]]++;
  }

  int ans[3];

  for(int i=0;i<3;i++){
    int mx = 0;
    for(auto it = cnt[i].begin();it!=cnt[i].end();it++){
      mx = max(mx, it->second);
    }
    int curTurn = turns[i];

   ans[i] = min(mx+curTurn,len);
   if(curTurn == 1 && mx == len)
    ans[i]--;
  }

  int mx = 0;
  int id = -1;
  int draw = -1;

  for(int i=0;i<3;i++){
    if(ans[i] > mx){
      mx = ans[i];
      id = i;
    }else if(ans[i] == mx)
      draw = mx;
  }

  if(mx == draw)
    cout << "Draw" << endl;
  else if(id == 0)
    cout << "Kuro" << endl;
  else if(id == 1)
    cout << "Shiro" << endl;
  else 
    cout << "Katie" << endl;

  
  
  
  return 0;
}