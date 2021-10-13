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

    bool can = true;
    sort(vet.begin(),vet.end());
    for(int i=0;i<n-1;i++)
      if(abs(vet[i]-vet[i+1]) > 1)
        can = false;

    if(can)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

  }

  return 0;
}