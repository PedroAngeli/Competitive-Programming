#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <pair<int,int>> func(long long n){
  long long div = 2;
  vector <pair <int,int> > factors;

  while(div*div <= n){
    int cnt = 0;
    while(n % div == 0){
      n/=div;
      cnt++;
    }
    if(cnt)
      factors.push_back({div,cnt});
    div++;
  }

  if(n != 1){
    factors.push_back({n,1});
  }

  return factors;
} 

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,m;

  while(cin >> n >> m){
    vector <pair<int,int>> factors = func(m);

    int len = factors.size();

    bool can = true;

    for(int i=0;i<len;i++){
      int curF = factors[i].first;
      int curExp = factors[i].second;

      int qtd = 0;
      int exp = 1;

      while(true){
        long long cur = (long long)pow(curF,exp);
        if(cur > n)
          break;
        qtd += (n/cur);
        exp++;
      }
      if(qtd < curExp){
        can = false;
        break;
      }
    }

    if(can){
      cout << m << " divides " << n << "!" << endl;
    }else
      cout << m << " does not divide " << n << "!" << endl;

  }

  
  
  return 0;
}