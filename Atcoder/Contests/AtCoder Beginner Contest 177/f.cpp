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

  int h,w;
  cin >> h >> w;

  int curI = 1;
  ll moves = 0;

  for(int i=0;i<h;i++){
    int a,b;
    cin >> a >> b;
    
    if(moves == -1){
      cout << moves << endl;
      continue;
    }

    if(curI < a){
      moves++;
    }else if(curI >= a && curI <= b){
      if(b+1 <= w){
        moves += (b+1)-curI+1;
        curI = b+1;
      }else{
        moves = -1;
      }
    }else if(curI > b){
      moves++;
    }

    cout << moves << endl;
  }

  return 0;
}