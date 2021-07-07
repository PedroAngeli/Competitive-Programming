#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

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
 
  string s;
  cin >> s;
  s += "$";
  int n = s.size();

  vector <int> p(n);
  vector <int> c(n);
  
  vector <pair <char,int> > a(n);

  for(int i=0;i<n;i++)
    a[i] = {s[i],i};

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

  for(int i=0;i<n;i++)
    cout << p[i] << " ";
  cout << endl;

  vector <int> lcp(n);
  k = 0;
  for(int i=0;i<n-1;i++){
    int pi = c[i];
    int j = p[pi-1];
    while(s[i+k] == s[j+k])
      k++;
    lcp[pi] = k;
    k = max(k-1,0);
  }
    
  for(int i=1;i<n;i++)
    cout << lcp[i] << " ";
  cout << endl;

  return 0;
}