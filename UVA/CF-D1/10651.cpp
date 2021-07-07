#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
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

vi dp;

bool is_set(int bit,int mask){
  return (mask & (1 << bit));
}

int solve(int mask){
  int& state = dp[mask];
  if(state != -1)
    return state;
  
  state = 0;
  for(int i=0;i<=9;i++){
    if(!is_set(i,mask) && is_set(i+1,mask) && is_set(i+2,mask)){
      int newMask = mask ^ (1 << i) ^ (1 << (i+1)) ^ (1 << (i+2));
      state = max(state, 1 + solve(newMask));
    }

    if(is_set(i,mask) && is_set(i+1,mask) && !is_set(i+2,mask)){
      int newMask = mask ^ (1 << i) ^ (1 << (i+1)) ^ (1 << (i+2));
      state = max(state, 1 + solve(newMask));
    }
  }

  return state;
}

int main(){
  fastio;

  int n;
  cin >> n;
  
  while(n--){
    string a;
    cin >> a;
    int mask = 0;
    int ones = 0;
    for(int i=0;i<12;i++){
      if(a[i] == 'o')
        mask |= (1 << i),ones++;
    }
    dp.assign((1 << 12),-1);
    cout << ones - solve(mask) << endl;
  }


  return 0;
}