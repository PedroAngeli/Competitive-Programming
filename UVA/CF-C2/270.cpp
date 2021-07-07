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

using Line = pair <ii,pair <int,ii> >;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  string a;
  getline(cin,a);
  getline(cin,a);
  int test = 0;
  while(t--){
    if(test)
      cout << endl;
    test++;
    int x,y;
    map <Line,int> mp;
    vector <ii> points;

    while(getline(cin,a)){
      if(a == "")
        break;
      istringstream str(a);
      str >> x >> y;
      points.push_back({x,y});
    }

    int n = points.size();
    sort(points.begin(),points.end());

    for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
        int x1 = points[i].f;
        int y1 = points[i].s;
        int x2 = points[j].f;
        int y2 = points[j].s;
        ii a,c;
        int b = 1;
        if(x1 == x2)
          b = 0;
        int num = -(y1-y2);
        int den = (x1-x2);
        if(num == 0 && den == 0)
          continue;
        int gcd = __gcd(abs(num),abs(den));
        num /= gcd;
        den /= gcd;
        a.f = num, a.s = den;
        c.f = -num*x1-den*y1, c.s = den;
        mp[{a,{b,c}}]++;
      }
    }

   int ans = 0;
   for(auto el:mp) 
    ans = max(ans,el.second);

    for(int i=2;i<=n;i++)
      if(ans == (i*(i-1))/2){
        ans = i;
        break;
      }
    cout << ans << endl;
  }
  return 0;
}