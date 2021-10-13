#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n,x;

  cin >> n >> x;

  vector < pair <long long,int> > vet;

  for(int i=0;i<n;i++){
    long long a;
    cin >> a;
    vet.push_back({a,i});
  }

  sort(vet.begin(),vet.end());

  int i=0;
  int j=n-1;

  while(true){

    if(i >= j)
      break;

    long long sum = vet[i].first + vet[j].first;

    if(sum == x){
      cout << vet[i].second+1 << " " << vet[j].second+1 << endl;
      return 0;
    }

    if(sum < x){
      i++;
    }else{
      j--;
    }
  }

  cout << "IMPOSSIBLE\n";
 

  return 0;
}