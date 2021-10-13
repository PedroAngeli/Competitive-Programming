#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  while(n--){
    string a,b;
    cin >> a >> b;

    vector <int> n1,n2,ans;

    for(int i=a.size()-1;i>=0;i--)
      n1.push_back(a[i]-'0');
    
    for(int i=b.size()-1;i>=0;i--)
      n2.push_back(b[i]-'0');

    if(n1.size() < n2.size())
      swap(n1,n2);

    int n = n1.size();
    int m = n2.size();

    int i = n-1;
    int j = m-1;
    int vaium = 0;

    while(i >= 0 || j >= 0){
      
      if(j < 0){
        int sum = n1[i] + vaium;
        ans.push_back(sum%10);
        vaium = sum/10;
      }else{
        int sum = n1[i] + n2[j] + vaium;
        ans.push_back(sum%10);
        vaium = sum/10;
      }

      i--;
      j--;
    }

    if(vaium)
      ans.push_back(vaium);

    bool zero = false;
    int idx;

    for(int i=0;i<ans.size();i++){
      if(ans[i] != 0){
        idx = i;
        break;
      }
    }

    for(int i=idx;i<ans.size();i++){
      cout << ans[i];
    }
      

    cout << endl;
  }
  
  return 0;
}