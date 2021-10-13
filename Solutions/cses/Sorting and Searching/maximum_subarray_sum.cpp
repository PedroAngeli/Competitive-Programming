#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main(){

  int n;
  cin >> n;


  vector <long long> vet(n);

  for(int i=0;i<n;i++)
    cin >> vet[i];

  long long sum = 0;
  long long resp = -INF;

  for(int i=0;i<n;i++){
    sum+=vet[i];

    resp = max(resp, sum);

     if(sum < 0)
      sum = 0;
  }

  cout << resp << endl;
 

  return 0;
}