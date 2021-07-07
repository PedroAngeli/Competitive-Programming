#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


int main(){
  fastio;

  int n,m,k;
  cin >> n >> m >> k;
  vi days;

  vi stop;
  vi ret;
  int K = k;
  while(K--){
    days.pb(1);
    stop.pb(n);
    ret.pb(-1);
  }

  for(int day=2;day<=1e5;day++){

    int willStop = 0;
    int stillWorking = 0;

    for(int i=0;i<sz(stop);i++){
      if(stop[i] == day)
        willStop++,stillWorking++,ret[i] = day+m+1,stop[i] = -1;
      else if(day < stop[i])
        stillWorking++;
    }

    int hire = max(0,k-stillWorking);

    for(int i=0;i<hire;i++){
      days.pb(day);
      stop.pb(day+n-1);
      ret.pb(-1);
    }

    stillWorking += hire;
    
    int willReturn = 0;

    for(int i=0;i<sz(ret);i++){
      if(ret[i] == day+1)
        willReturn++,ret[i]=-1,stop[i] = day+n;
    }

    if(stillWorking - willStop > 0)
      continue;
    
    days.pb(day);
    stop.pb(day+n-1);
    ret.pb(-1);
  }

  cout << sz(days) << endl;
  for(int x : days)
    cout << x << " ";
  cout << endl;

  return 0;
}