#include <bits/stdc++.h>

using namespace std;

vector <int> r;
vector <int> b;
int N;

bool can(long long m){
  long long sumr = 0;
  long long sumb = 0;

  for(int i = 0;i<N;i++){
    if(r[i] && !b[i]){
      sumr += m;
    }else if(r[i] && b[i]){
      sumr++;
      sumb++;
    }else if(b[i]){
      sumb++;
    }
  }

  // cout << sumr << " " << sumb << endl;
  return sumr > sumb;
}

int main(){

  cin >> N;

  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    r.push_back(a);
  }

   for(int i=0;i<N;i++){
    int a;
    cin >> a;
    b.push_back(a);
  }

  //  cout << can(3) << endl;

  // return 0;

  long long e = 0;
  long long d = 1e9;

  long long ans = 1e9 + 5;

  while(e <= d){
    long long m = (e+d)/2;

    if(can(m)){
      ans = min(ans,m);
      d = m-1;
    }else{
      e = m+1;
    }
  }

  if(ans == 1e9 + 5){
    ans = -1;
  }

  cout << ans << endl;

  return 0;
}