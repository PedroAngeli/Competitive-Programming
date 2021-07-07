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


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vi vet(n);

  for(int i=0;i<n;i++){
    cin >> vet[i];
  }

  int mx = vet[0];
  int mn = vet[0];
  int ans = 0;
  int idx = 0;

  for(int i=1;i<n;i++){
    if(mx-vet[i] > 1 || vet[i]-mn > 1){
      mn = mx = vet[i];
      ans = max(ans,i-idx);
      int j = i-1;
      while(j >= 0 && abs(vet[j]-vet[i]) <= 1) mx = max(mx,vet[j]),mn = min(mn,vet[j]),j--;
      idx = j+1;
    }
    mx = max(mx,vet[i]);
    mn = min(mn,vet[i]);
  }
  ans = max(ans,n-idx);
  cout << ans << endl;
  return 0;
}