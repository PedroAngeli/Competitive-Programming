#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,r;
double p[20];
double sum[20];
double den;

void solve(int i,int taked){
  if(i == n){
    int cnt = 0;
    for(int i=0;i<n;i++){
      if(taked & (1 << i))
        cnt++;
    }

    if(cnt != r)
      return;
    
    double prob = 1.0;
    for(int i=0;i<n;i++){
      if(taked & (1 << i))
        prob*=p[i];
      else
        prob*=(1-p[i]);
    }

    den += prob;

    for(int i=0;i<n;i++){
      if(taked & (1 << i))
          sum[i]+=prob;
    }

    return;
  }

  solve(i+1,taked);
  solve(i+1,taked | (1 << i));
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int ncase = 1;

  while(cin >> n >> r && n){
    for(int i=0;i<n;i++)
      cin >> p[i],sum[i]=0;
      den = 0;
      solve(0,0);

      cout << "Case " << ncase++ << ":" << endl;
      for(int i=0;i<n;i++)
        cout << fixed << setprecision(6) << sum[i]/den << endl;
  }
  return 0;
}