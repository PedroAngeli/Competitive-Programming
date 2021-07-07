#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
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
  
  int t = 1;
  cin >> t;

  while(t--){
    int n,k,z;
    cin >> n >> k >> z;
    vi vet(n);

    for(int i=0;i<n;i++)
      cin >> vet[i];
    
    int ans = 0;

    vi pref(n);
    pref[0]=vet[0];

    for(int i=1;i<n;i++)
      pref[i] = vet[i] + pref[i-1];

    for(int i=1;i<=k;i++){
      int sum = pref[i-1];
      int K = k-i+1;
      int j = 0;
      int Z = z;

      while(Z && K){
        if(j % 2 == 0)
          sum += vet[i],K--;
        else
          sum += vet[i-1],Z--,K--;
        j++;
      }

      if(j % 2 == 1){
          sum += pref[i+K]-pref[i];
        }else{
          sum += pref[i-1+K]-pref[i-1];
        }

      ans = max(ans,sum);
    }

    cout << ans << endl;
  }
 
  return 0;
}