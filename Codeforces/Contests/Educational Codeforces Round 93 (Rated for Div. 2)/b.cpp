#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

  int t=1;
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    int ans = 0;

    int cnt = 0;
    int n = str.size();
    vi vet;

    for(int i=0;i<n;i++){
      if(str[i]=='1')
        cnt++;
      else{
        vet.push_back(cnt);
        cnt = 0;
      }
    }
    if(cnt)
      vet.push_back(cnt);

    sort(vet.begin(),vet.end());
    reverse(vet.begin(),vet.end());

    for(int i=0;i<vet.size();i+=2)
      ans+=vet[i];

    cout << ans << endl;
  }
  
  return 0;
}