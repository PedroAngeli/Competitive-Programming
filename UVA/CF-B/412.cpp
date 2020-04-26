#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int gcd(int a,int b){
  if(b == 0)
    return a;
  
  return gcd(b,a%b);
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  while(cin >> n && n){
    int vet[n];

    for(int i=0;i<n;i++)
      cin >> vet[i];

    int cnt = 0;
    int total = (n*(n-1))/2;

    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        if(gcd(vet[i],vet[j]) == 1)
          cnt++;

    
    if(cnt == 0){
      cout << "No estimate for this data set." << endl;
    }else{
      cout << fixed << setprecision(6) << sqrt((6.0*total)/(cnt)) << endl;
    }
  }
  
  return 0;
}