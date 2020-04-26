#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <int> numbers;
long long ans = 0;
long long n;

long long gcd(long long a, long long b){
  if(b == 0)
    return a;

  return gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return (a*b)/gcd(a,b);
}

void solve(int i,int qtd,long long num){
    if(i == numbers.size()){
      if(qtd == 0)
        return;
      if(qtd % 2 == 0)
        ans -= (n/num);
      else
        ans += (n/num);

      return;
    }

    solve(i+1,qtd+1,lcm(num,numbers[i]));

    solve(i+1,qtd,num);
}



int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int m;

  while(cin >> n >> m){
    ans = 0;
    numbers.resize(m);

    for(int i=0;i<m;i++)
      cin >> numbers[i];

    solve(0,0,1);

    cout << n-ans << endl;
  }
  
  
  return 0;
}