#include <bits/stdc++.h>

using namespace std;

struct cmp{
  bool operator() (const pair <int,int> &a,const pair <int,int> &b) const{

    if((a.second - a.first) == (b.second - b.first))
      return a.first < b.first;

    return (a.second - a.first) > (b.second - b.first);
  }
};

int main(){

  int n, x;
  cin >> x >> n;
  vector <int> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  set <int> conj;
  conj.insert(x);
  conj.insert(0);

  set <pair <int,int> , cmp> intervalos;
  intervalos.insert({0,x});
 
  for(int i=0;i<n;i++){
    auto it = conj.lower_bound(vet[i]);
    auto it2 = --it;
    it++;

    int l = *it2;
    int r = *it;

    conj.insert(vet[i]);

    auto temp = intervalos.find({l,r});
    intervalos.erase(temp);


    intervalos.insert({l,vet[i]});
    intervalos.insert({vet[i],r});

    auto resp = intervalos.begin();
   
    cout << resp->second - resp->first << " "; 
  }

  cout << endl;
 
  return 0;
}