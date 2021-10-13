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


int main(){
  fastio;

  int t = 1;
  // cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++)
      cin >> a[i];
    sort(all(a));
    if(n <= 2){
      cout << 0 << endl;
      for(int x:a)
        cout << x << " ";
      cout << endl;
      return 0;
    }

    vi ans1(n);
    int i = 0;
    int j = n-1;
    int pos = 0;

    while(i < j){
      if(pos%2 == 0){
        ans1[pos] = a[j];
        ans1[n-pos-1] = a[j-1];
        pos++;
        j-=2;
      }else{
        ans1[pos] = a[i];
        ans1[n-pos-1] = a[i+1];
        pos++;
        i+=2;
      }
    }

    if(i == j)
      ans1[pos] = a[i];

    int cnt1 = 0;
    for(int i=1;i<n-1;i++){
      if(ans1[i-1] > ans1[i] && ans1[i] < ans1[i+1])
        cnt1++;
    }
    

    vi an2;
    an2.pb(a.back());
    an2.pb(a[0]);
    an2.pb(a[n-2]);
     j = n-3;
     i = 1;
 
    while(i < j){
      an2.pb(a[i]);
      an2.pb(a[j]);
      i++,j--;
    }
 
    if(i == j)
      an2.pb(a[i]);
 
    int cnt2 = 0;
    for(int i=1;i<n-1;i++){
      if(an2[i-1] > an2[i] && an2[i] < an2[i+1])
        cnt2++;
    }
    if(cnt1 > cnt2){
      cout << cnt1 <<endl;
    for(int x:ans1)
      cout << x << " ";
    cout << endl;
    }else{
       cout << cnt2 <<endl;
    for(int x:an2)
      cout << x << " ";
    cout << endl;
    }
    
   
  }

  return 0;
}