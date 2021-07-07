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

void couting_sort(vector <int>&p,vector <int>&c){
  int n = p.size();
  vector <int> cnt(n,0);

  for(int x:c)
    cnt[x]++;
  vector <int> posBucket(n);

  posBucket[0] = 0;
  for(int i=1;i<n;i++)
    posBucket[i] = posBucket[i-1]+cnt[i-1];

  vector <int> newP(n);

  for(int x:p)
    newP[posBucket[c[x]]++] = x;

  p = newP;
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  string str;
  cin >> str;
  str += "$";
  int n = str.size();

  vector <int> p(n);
  vector <int> c(n);
  
  vector <pair <char,int> > a(n);

  for(int i=0;i<n;i++)
    a[i] = {str[i],i};

  sort(a.begin(),a.end());
  
  for(int i=0;i<n;i++)
    p[i] = a[i].second;

  c[p[0]] = 0;
  for(int i=1;i<n;i++){
    if(a[i].first == a[i-1].first)
      c[p[i]] = c[p[i-1]];
    else
      c[p[i]] = c[p[i-1]] + 1;
  }

  int k = 0;

  while((1 << k) < n){
    for(int i=0;i<n;i++)
      p[i] = (p[i] - (1 << k) + n)%n;

      couting_sort(p,c);

      vector <int> newC(n);
      newC[p[0]] = 0;

      for(int i=1;i<n;i++){
        pair <int,int> cur = {c[p[i]],c[(p[i] + (1 << k))%n]};
        pair <int,int> prev = {c[p[i-1]],c[(p[i-1] + (1 << k))%n]};

        if(cur == prev){
          newC[p[i]] = newC[p[i-1]];
        }else{
          newC[p[i]] = 1 + newC[p[i-1]];
        }
      }

      c = newC;
    k++;
  }

  int q;
  cin >> q;
  while(q--){
    string t;
    cin >> t;
    
    int len = t.size();

    int l = 0;
    int r = n-1;

    int lower = -1;

    while(l <= r){
      int m = (l+r)/2;
      int pos = p[m];
      int i = 0;
      
      while(str[pos%n] == t[i] && i < len)
        pos++,i++;

      if(i == len)
        lower = m,r = m-1;
      else if(str[pos] < t[i])
        l = m+1;
      else
        r = m-1;
    }

    if(lower == -1){
      cout << 0 << endl;
      continue;
    }

    int upper = -1;
    l = 0;
    r = n-1;

     while(l <= r){
      int m = (l+r)/2;
      int pos = p[m];
      int i = 0;
      
      while(str[pos%n] == t[i] && i < len)
        pos++,i++;

      if(i == len)
        upper = m,l = m+1;
      else if(str[pos] < t[i])
        l = m+1;
      else
        r = m-1;
    }
    cout << upper - lower + 1 << endl;
  }
 
  return 0;
}