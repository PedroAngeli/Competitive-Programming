#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  string s;
  long long a,b;
  cin >> s;
  cin >> a >> b;

  int n = s.size();
  long long sum = 0;
  bool nozero = false;

  long long pref[n];
  pref[0] = 0;
  
  for(int i=1;i<n;i++){
    int dig = s[i-1]-'0';
    pref[i] = (pref[i-1]*10 + dig)%a;
  }

  int p = 1;

  for(int i=n-1;i>=0;i--){
    int dig = s[i]-'0';

    if(dig > 0)
      nozero = true;

    sum += (dig * p)%b;
    p = (p * 10)%b;

    if(i > 0 && nozero && sum % b == 0 && pref[i] == 0){
      cout << "YES" << endl;
      for(int j=0;j<i;j++)
        cout << s[j];
        cout << endl;
      for(int j=i;j<n;j++)
        cout << s[j];
      
      cout << endl;

      return 0;
    }
  }

  cout << "NO" << endl;

  

  return 0;
}