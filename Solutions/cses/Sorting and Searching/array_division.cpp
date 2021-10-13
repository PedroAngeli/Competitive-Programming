#include <bits/stdc++.h>

using namespace std;

long long N,K;
vector <long long> vet;

bool can(long long x){
  long long i;
  long long sum = 0;
  long long count = 0;

  for(i = 0;i<N;i++){
    if(sum + vet[i] <= x){
      sum += vet[i];
    }else{
      i--;
      sum = 0;
      count++;
      if(count == K)
        break;
    }
  }

  return i == N;
}

int main(){
  

  cin >> N >> K;

  vet = vector <long long> (N);

  long long sum = 0;

  for(long long i=0;i<N;i++){
    cin >> vet[i];
    sum += vet[i];
  }

  long long e = 1, d = sum;
  long long ans = 1e18L + 5;

  while(e <= d){
    long long m = (e+d)/2;
    if(can(m)){
      d = m-1;
      ans = min(ans,m);
    }else{
      e = m+1;
    }
  }

  cout << ans << endl;
    
  return 0;
}