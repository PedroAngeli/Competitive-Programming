#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  vector <string> grid(n,string(n,'S'));

  if(k > (n*n+1)/2){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(i % 2 == 0 && j % 2 == 0 && k)
          grid[i][j] = 'L',k--;
        if(i % 2 == 1 && j % 2 == 1 && k)
          grid[i][j] = 'L',k--;
      }
    }

    for(int i=0;i<n;i++)
      cout << grid[i] << endl;
  }
  
  return 0;
}