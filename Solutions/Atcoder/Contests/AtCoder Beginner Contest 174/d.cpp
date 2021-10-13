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
  
  map <char,int> cnt;
  int n;
  string a;
  cin >> n >> a;
  for(char c:a)
    cnt[c]++;
  string ref = "";
  while(cnt['R']--)
    ref+="R";
  while(cnt['W']--)
    ref+="W";
  
  int cw = 0;
  int cr = 0;

  for(int i=0;i<n;i++){
    if(a[i] != ref[i]){
      if(a[i] == 'W')
        cw++;
      else
        cr++;
    }
  }

  cout << max(cw,cr) << endl;
  return 0;
}