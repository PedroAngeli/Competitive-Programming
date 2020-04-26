#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  long long x;
  cin >> n >> x;

  vector <long long> temp(n);

  for(int i=0;i<n;i++)
    cin >> temp[i];

  vector <pair <long long, pair <int,int> > >  vet;

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      vet.push_back({temp[i]+temp[j],{i,j}});
    }
  }

  sort(vet.begin(),vet.end());

  int l = 0;
  int r = vet.size()-1;

  while(l < r){
    int id1 = vet[l].second.first;
    int id2 = vet[l].second.second;
    int id3 = vet[r].second.first;
    int id4 = vet[r].second.second;
    long long sum = vet[r].first + vet[l].first;

    if(sum == x && id1 != id3 && id1 != id4 && id2 != id3 && id2 != id4){
      cout << id1 + 1 << " " << id2 + 1 << " " << id3 + 1 << " " << id4 + 1 << endl;
      return 0;
    }else if(sum < x){
      l++;
    }else{
      r--;
    }
  }

  cout << "IMPOSSIBLE\n";

 

  return 0;
}