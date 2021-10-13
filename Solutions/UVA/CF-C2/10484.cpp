#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

vector <pair <int,int> > findFactores(long long n){
  vector <pair <int,int> > ret;
  long long div = 2;

  while(div*div <= n){
    int cnt = 0;
    while(n%div == 0){
      cnt++;
      n/=div;
    }
    if(cnt)
      ret.push_back({div,cnt});
    div++;
  }

  if(n!=1)
    ret.push_back({n,1});

  return ret;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  long long n,d;
  while(cin >> n >> d){
    long long ans = 1;
   d = abs(d);
    if(!n && !d)
      break;

    long long ff[105] = {0};

    for(int i=2;i<=n;i++){
      vector <pair <int,int> > f = findFactores(i);
      for(int j=0;j<f.size();j++)
        ff[f[j].first] += f[j].second;
    }

    vector <pair <int,int> > fd = findFactores(d);
    long long mult = 1;

    for(int i=0;i<fd.size();i++){
      long long curF = fd[i].first;
      long long curExp = fd[i].second;

      if(curF > 100){
        ans = 0;
        break;
      }

      ff[curF] = ff[curF] - curExp;

      if(ff[curF] < 0){
        ans = 0;
        break;
      }
    }

    for(int i=0;i<=100;i++){
      if(ff[i])
        ans *= (ff[i] + 1);
    }
    
    cout << ans << endl;
  }
  
  return 0;
}