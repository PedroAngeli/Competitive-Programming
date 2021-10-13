#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
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


bool valid(vector <vi>& mat,int L,int C){
  bool can = true;

    for(int i=0;i<L;i++){
      vi tmp = mat[i];
      sort(all(tmp));
      for(int j=1;j<C;j++)
        if(tmp[j]-tmp[j-1]>1){
          can = false;
          i = L;
          break;
        }
    }

    for(int j=0;j<C;j++){
      for(int i=1;i<L;i++){
        if(abs(mat[i][j]-mat[i-1][j]) % C != 0){
          can = false;
          j = C;
          break;
        }
      }
    }

    return can;
}

int solve(vi& vet){
    int len = vet.size();
    int ret = 0;
    vi original = vet;

    sort(all(vet));

    for(int i=0;i<len;i++){
      int cur = vet[i];
      if(cur == original[i])
        continue;
      ret++;
      int j = i;
      while(j < len && original[j] != cur)
        j++;
      swap(original[i],original[j]);
    }

    return ret;
}

int main(){
  fastio;

  int L,C;
  while(cin >> L >> C){
     vector <vi> mat(L,vi(C));

    for(int i=0;i<L;i++)
      for(int j=0;j<C;j++)
        cin >> mat[i][j];
    
    bool can = valid(mat,L,C);

    if(!can){
      cout << "*" << endl;
      continue;
    }


    vi aux = mat[0];
    vi aux2;
    for(int i=0;i<L;i++)
      aux2.pb(mat[i][0]);

    int ans = solve(aux) + solve(aux2);

    cout << ans << endl;
  }


  return 0;
}