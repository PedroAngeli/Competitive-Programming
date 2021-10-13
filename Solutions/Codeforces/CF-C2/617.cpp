#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef struct ponto{
  long long x,y;
  ponto(long long x=0,long long y=0):x(x),y(y){};
}Ponto;

long long dist(Ponto p1, Ponto p2){
  return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  Ponto c1,c2;
  cin >> c1.x >> c1.y >> c2.x >> c2.y;

  vector <long long> f1;
  vector <long long> f2;

  for(int i=0;i<n;i++){
    Ponto p;
    cin >> p.x >> p.y;
    long long d1 = dist(p,c1);
    long long d2 = dist(p,c2);
    f1.push_back(d1);
    f2.push_back(d2);
  }

  long long ans = LLONG_MAX;

  for(int i=0;i<n;i++){
    long long cur1 = f1[i];
    long long mx2 = 0;
    for(int j=0;j<n;j++){
      if(f1[j] <= cur1)
        continue;
      mx2 = max(mx2,f2[j]);
    }
    
    ans = min(ans,cur1 + mx2);
  }


  for(int i=0;i<n;i++){
    long long cur2 = f2[i];
    long long mx1 = 0;
    for(int j=0;j<n;j++){
      if(f2[j] <= cur2)
        continue;
      mx1 = max(mx1,f1[j]);
    }
    
    ans = min(ans,cur2 + mx1);
  }

  cout << ans << endl;
  return 0;
}