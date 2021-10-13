#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

void solve(int n){
  int div = 2;
  vector <pair<int,int> > ans;
  
  while(div*div<=n){
    int cnt = 0;
    while(n % div == 0){
      n/=div;
      cnt++;
    }
    if(cnt)
      ans.push_back({div,cnt});
    div++;
  }

  if(n!=1)
    ans.push_back({n,1});

  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());

  int len = ans.size();

  for(int i=0;i<len;i++){
    if(i == len-1)
      cout << ans[i].first << " " << ans[i].second << endl;
    else
      cout << ans[i].first << " " << ans[i].second << " ";
  }
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int e;
  char c;

  while(true){
    int number = 1;
  
    while(scanf("%d%*c%d%c",&n,&e,&c)){
      if(n == 0)
        return 0;

      number *= pow(n,e);

      if(c == '\n'){
        solve(number-1);
        break;
      }
    }
  }

  return 0;
}