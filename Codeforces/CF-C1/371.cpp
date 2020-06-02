#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

unordered_map <char,long long> ing;
long long nb,ns,nc;
long long pb,ps,pc;
long long r;

bool can(long long m){
  long long totalPrice = max(ing['B']*m - nb,0LL)*pb + max(ing['S']*m - ns,0LL)*ps + 
  max(ing['C']*m - nc,0LL)*pc;

  return totalPrice <= r;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string s;
  cin >> s;
  int n = s.size();

  for(int i=0;i<n;i++)
    ing[s[i]]++;

  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;

  long long l = 0;
  long long r = 1e14;
  long long ans = 0;

  while(l <= r){
    long long m = (l+r)/2;

    if(can(m)){
      ans = max(m,ans);
      l = m+1;
    }else
      r = m-1;
  }

  cout << ans << endl;

  return 0;
}