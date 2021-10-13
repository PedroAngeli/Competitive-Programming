#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n,f;

  cin >> n >> f;

  vector <pair <long long, long long> > vet;
  long long ans = 0;

  for(int i=0;i<n;i++){
    long long a,b;
    cin >> a >> b;
    ans += min(a,b);
    vet.push_back({a,b});
  }

  vector <long long> aux;


  for(int i=0;i<n;i++){
    long long k = vet[i].first;
    long long c = vet[i].second;

    aux.push_back(min(2*k,c) - min(k,c));
  }

  sort(aux.begin(),aux.end());
  reverse(aux.begin(),aux.end());

  for(int i=0;i<f;i++)
    ans += aux[i];

  cout << ans << endl;
  
  return 0;
}