#include <bits/stdc++.h>

using namespace std;

const int nax = 5*1e5 + 5;
int n;
long long vet[nax];
set <long long> ant;
set <long long> atu;
set <long long> ans;

long long gcd(long long a,long long b){
  if(b==0)
    return a;

  return gcd(b,a%b);
}

int main(){

  cin >> n;

  for(int i=0;i<n;i++)
    cin >> vet[i];

  ans.insert(vet[0]);
  ant.insert(vet[0]);

  for(int i=1;i<n;i++){
    for(auto it = ant.begin();it!=ant.end();it++){
      long long mdc = gcd(*it,vet[i]);
      atu.insert(mdc);
      ans.insert(mdc);
    }
    atu.insert(vet[i]);
    ans.insert(vet[i]);
    ant = atu;
    atu.clear();
  }

  cout << ans.size() << endl;
  
  return 0;
}