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

int cross(ii p1, ii p2,ii p3){
  ii v1 = {p2.f-p1.f,p2.s-p1.s};
  ii v2 = {p2.f-p3.f,p2.s-p3.s};

  return v1.f*v2.s - v2.f*v1.s; 
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vii p(n);

  for(int i=0;i<n;i++)
    cin >> p[i].f >> p[i].s;

  int ans = 0;
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      int pos = -1;
      int neg = -1;
      for(int k=0;k<n;k++){
        if(k == i || k == j)
          continue;
        int c = cross(p[i],p[j],p[k]);
        if(c < 0)
          c*=-1, neg = max(neg,c);
        else
          pos = max(pos,c);
      }

      if(pos != -1 && neg != -1)
        ans = max(ans,pos+neg);
    }
      
  cout << fixed << setprecision(9) << (ld)ans/2 << endl;
  return 0;
}