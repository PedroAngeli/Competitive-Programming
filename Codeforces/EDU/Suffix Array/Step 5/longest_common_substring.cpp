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

void couting_sort(vi &p,vi &c){
  int n = p.size();
  vi cnt(n,0);

  for(int x:c)
    cnt[x]++;

  vi posBucket(n,0);

  for(int i=1;i<n;i++)
    posBucket[i] = posBucket[i-1]+cnt[i-1];

  vi newP(n);

  for(int x:p)
    newP[posBucket[c[x]]++] = x;

  p = newP;
}

void suffix_array(string& str,vi &p,vi &c){
  int n = str.size();

  vector <pair <char,int> > a(n);

  for(int i=0;i<n;i++)
    a[i] = {str[i],i};

  sort(a.begin(),a.end());
  
  for(int i=0;i<n;i++)
    p[i] = a[i].second;

  c[p[0]] = 0;
  for(int i=1;i<n;i++)
    c[p[i]] = c[p[i-1]] + (a[i].first != a[i-1].first);
  
  int k = 0;

  while((1 << k) < n){
    for(int i=0;i<n;i++)
      p[i] = (p[i] - (1 << k) + n)%n;

      couting_sort(p,c);

      vi newC(n);
      newC[p[0]] = 0;

      for(int i=1;i<n;i++){
        pii cur = {c[p[i]],c[(p[i] + (1 << k))%n]};
        pii prev = {c[p[i-1]],c[(p[i-1] + (1 << k))%n]};
        newC[p[i]] = newC[p[i-1]] + (cur != prev);
      }

      c = newC;
    k++;
  }
}

void findLcp(vi& lcp,vi& p,vi& c,string& str){
  int n = lcp.size();
  int k = 0;
  for(int i=0;i<n-1;i++){
    int pi = c[i];
    int j = p[pi-1];
    while(str[i+k] == str[j+k])
      k++;
    lcp[pi] = k;
    k = max(k-1,0);
  }
}
  
int main(){
  fastio;

  string s1,s2;
  cin >> s1 >> s2;
  string str = s1 + "$" + s2 + "#";

  int n = str.size();
  vi p(n);
  vi c(n);

  suffix_array(str,p,c);

  vi lcp(n);
  findLcp(lcp,p,c,str);

  int len = s1.size();
  string ans = "";
  int mx = 0;

  for(int i=1;i<n;i++){
    int c1 = p[i] < len;
    int c2 = p[i-1] < len;
    if(c1 != c2 && lcp[i] >= mx){
      string temp = str.substr(p[i],lcp[i]);
      if(lcp[i] > mx){
        ans = temp;
      }else if(lcp[i] == mx && ans > temp){
        ans = temp;
      }
      mx = lcp[i];
    }
  }
  cout << ans << endl;

  return 0;
}