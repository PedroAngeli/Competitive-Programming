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
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(2*n-1);
    vi o(2*n-1);
    vi idx(2*n-1);

    for(int i=0;i<2*n-1;i++){
      cin >> a[i] >> o[i];
      idx[i] = i;
    }
    
    sort(idx.begin(),idx.end(),[&](int i,int j){
      return a[i] > a[j];
    });

    cout << "YES" << endl;
    cout << idx[0] + 1;

    for(int i=1;i<2*n-2;i+=2){
      if(o[idx[i]] > o[idx[i+1]])
        cout << " " << idx[i]+1;
      else
        cout << " " << idx[i+1]+1;
    }
    cout << endl;
  }
 
  return 0;
}