#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
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
    vector <pair <pair <int,int>,int> > b(n);
    for(int i=0;i<n;i++)
      b[i] = {{c[i],c[(i + (1<<k))%n]}, i};
    
  sort(b.begin(),b.end());
  
  for(int i=0;i<n;i++)
    p[i] = b[i].second;
    
  c[p[0]] = 0;
  for(int i=1;i<n;i++){
    if(b[i].first == b[i-1].first)
      c[p[i]] = c[p[i-1]];
    else
      c[p[i]] = c[p[i-1]] + 1;
  }

    k++;
  }

  for(int i=0;i<n;i++)
    cout << p[i] << " ";
  cout << endl;
    
  return 0;
}