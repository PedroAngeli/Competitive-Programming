#include <bits/stdc++.h>

using namespace std;

int toNum(char c){
  return c-'0';
}

int main(){

  string a,b;

  while(cin >> a >> b){

    string temp;
    temp.resize(510,'0');
    vector <string> ans(255,temp);

    if(a > b)
      swap(a,b);

    for(int i=a.size()-1;i>=0;i--){
      int vai = 0;
      string temp;
      for(int j=b.size()-1;j>=0;j--){
        int mult = toNum(a[i]) * toNum(b[j]);
        int resp = mult%10;
        ans[a.size()-1-i][b.size()-1-j + a.size()-1-i] = ((resp+vai)%10) + '0';
        vai = (mult/10) + (resp+vai)/10;
      }

      if(vai > 0){
        ans[a.size()-1-i][b.size() + a.size()-1-i] = vai + '0';
      }
    }

    int vai = 0;
    string resp;

    for(int j = 0;j<510;j++){
      int sum = vai;
      
      for(int i = 0;i<250;i++){
        sum += toNum(ans[i][j]);
      }
     
      vai = sum/10;
      resp.push_back((sum%10) + '0');
    }

   
    reverse(resp.begin(),resp.end());

    int ult = 509;

    for(int i=509;i>=0;i--) 
      if(resp[i] > '0')
        ult = i;

    for(int i=ult;i<=509;i++)
      cout << resp[i];

      cout << endl;

  }

  return 0;
}