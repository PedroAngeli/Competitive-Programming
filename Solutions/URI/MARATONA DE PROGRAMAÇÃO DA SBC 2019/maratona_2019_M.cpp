#include <bits/stdc++.h>

using namespace std;

long long N,C,T;
vector <long long> s;

bool can(long long x){
  long long eat = x * T;
  long long cont = 0;
  long long i;

  for(i=0;i<N;i++){
    if(s[i] <= eat){
      eat -= s[i];
    }else{
      cont++;
      i--;
      eat = x * T;
      if(cont == C)
        break;
    }
  }

  // printf("%d\n",i);

  return i == N;
}

int main(){
  

  cin >> N >> C >> T;

  s = vector <long long> (N);

  long long sum = 0;

  for(long long i=0;i<N;i++){
    cin >> s[i];
    sum += s[i];
  }

  long long e = 1, d = sum;
  long long ans = 1e9 + 5;

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