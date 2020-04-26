#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n;

  cin >> n;
  long long pa = ((1+n)*n)/2;

  if(pa%2 == 0){
    cout << "YES" << endl;
    long long sum = ((1+n)*n)/4;
    long long resp[n+1] = {0};
    long long num = n;
    long long count = 0;

    while(sum){
      if(sum - num >= 0){
        sum -= num;
        resp[num] = 1;
        count++;
      }
      num--;
    }

    cout << count << endl;

    for(int i=1;i<=n;i++){
      if(resp[i] == 1){
        cout << i << " ";
      }
    }

    cout << endl;
    cout << n-count << endl;

    
    for(int i=1;i<=n;i++){
      if(resp[i] == 0){
        cout << i << " ";
      }
    }

     cout << endl;
    

  }else{
    cout << "NO" << endl;
  }
  
  return 0;
}