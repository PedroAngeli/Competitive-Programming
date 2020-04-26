#include <bits/stdc++.h>

using namespace std;

long long n,x;
vector <pair<long long,int> > values;


int main(){

  
  cin >> n >> x;
  values = vector <pair<long long,int> >(n);
  

  for(int i=0;i<n;i++){
    int v;
    cin >> v;
    values[i] = {v,i};
  }

  sort(values.begin(),values.end());

  for(int i=0;i<n-2;i++){
    long long v = values[i].first;
    long long y = x - v;

    int l = i + 1;
    int r = n-1;

    while(l < r){
      if(values[l].first + values[r].first == y){
        cout << values[i].second + 1 << " "  << values[l].second + 1 << " " << values[r].second + 1 << endl;
        return 0;
      }else if(values[l].first + values[r].first < y){
        l++;
      }else{
        r--;
      }
    }
  }

  cout << "IMPOSSIBLE\n";

 

  return 0;
}