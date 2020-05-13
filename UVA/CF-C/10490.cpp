#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool prime(int n){
  return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13
  || n == 17 || n == 19 || n == 23 || n == 29 || n == 31;
}

bool solve(long long n){
  set <long long> div;

  for(long long i=1;i*i<=n;i++){
    if(n % i == 0){
      div.insert(i);
      div.insert(n/i);
    }
  }

  return div.size() == 2;
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  while(cin >> n && n){
    long long pot = pow(2,n);
    long long perfect = pot-1;
    bool isPerfect = solve(perfect);
    bool isPrime = prime(n);

    if(isPerfect)
      cout << "Perfect: " << (pot/2)*(pot-1) << "!" << endl;
    else if(isPrime)
      cout << "Given number is prime. But, NO perfect number is available." << endl;
    else
      cout << "Given number is NOT prime! NO perfect number is available." << endl;


  }

  return 0;
}