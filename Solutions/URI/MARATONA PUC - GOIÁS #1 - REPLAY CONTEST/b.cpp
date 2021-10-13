#include <bits/stdc++.h>

using namespace std;


int main(){

  int n,k;

  cin >> n >> k;

  long long temp[n]; 
  long long sum[n][n];

  for(int i=0;i<n;i++)
    cin >> temp[i];

  vector <long long> vet[n];

  int idx = n*n;

  for(int i=0;i<n;i++){
    int count = 0;
    for(int j=idx%n;count<n;count++,j++){
      vet[i].push_back(temp[j%n]);
    }
    idx--;
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j==0)
        sum[i][j] = vet[j][i];
      else
        sum[i][j] = sum[i][j-1] + vet[j][i];
    }
  }

  for(int i=0;i<n;i++){
    if(k <= n){
      if(i == n-1){
        cout << sum[i][k-1] << endl;
      }else{
        cout << sum[i][k-1] << " ";
      }
      
    }else{
      if(k % n == 0){
        if(i == n-1){
          cout << sum[i][n-1]*(k/n) << endl;
        }else{
          cout << sum[i][n-1]*(k/n) << " ";
        }
      }else{
        if(i == n-1){
          cout << sum[i][n-1]*(k/n) + sum[i][(k%n)-1] << endl;
        }else{
          cout << sum[i][n-1]*(k/n) + sum[i][(k%n)-1] << " ";
        }
      }
    }
  }


  return 0;
}