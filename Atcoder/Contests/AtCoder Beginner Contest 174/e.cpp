#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

vector <int> a;
int n,k;

bool can(int m){
  int cnt = 0;
  for(int i=0;i<n;i++){
    cnt += (a[i]+m-1)/m - 1;
  }


  return cnt <= k; 
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> k;
  a.resize(n);
  for(int i=0;i<n;i++)
    cin >> a[i];

  int l = 1;
  int r = 1e9;

  int ans = r;

  while(l <= r){
    int m = (l+r)/2;
    if(can(m)){
      ans = m;
      r = m-1;
    }else{
      l = m+1;
    }
  }

  cout << ans << endl;

  return 0;
}