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
  
  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi vet(n);
    for(int i=0;i<n;i++)
      cin >> vet[i];
    sort(vet.begin(),vet.end());
    int ans = 0;

    for(int s=1;s<=2*n;s++){
      int l = 0;
      int r = n-1;
      int teams = 0;
      while(l < r){
        if(vet[l]+vet[r] == s)
          teams++,l++,r--;
        else if(vet[l]+vet[r] < s)
          l++;
        else
          r--;
      }
      ans = max(ans,teams);
    }


    cout << ans << endl;
  }

  return 0;
}