#include <bits/stdc++.h>

using namespace std;

string find(int n){

  long long x = (n-1)*2;
  string ans;

  if(x % 3 == 0){
    for(int i=0;i<n-2;i++)
      ans+="2";

    ans+="3";
    ans+="3";

  }else{
    for(int i=0;i<n-1;i++)
      ans += "2";

    ans += "3";
  }

  return ans;
}

int main(){

  int t,n;

  cin >> t;

  while(t--){
    cin >> n;

    string resp;

    if(n == 1){
      resp = "-1";
    }
    else{
      resp = find(n);
    }

    cout << resp << endl;
  }


  return 0;
}