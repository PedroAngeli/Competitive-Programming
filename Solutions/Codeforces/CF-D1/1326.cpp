#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

bool palindrome(string str){
  int n = str.size();

  for(int i=0;i<n/2;i++)
    if(str[i] != str[n-i-1])
      return false;

  return true;
}

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    string str;
    cin >> str;
    
    int n = str.size();

    string a = "";
    string b = "";

    int i = 0;
    int j = n-1;

    while(i < j && str[i] == str[j]){
      a += str[i];
      b += str[j];
      i++;
      j--;
    }

    reverse(all(b));
    string pref = "";

    for(int len = (j-i+1);len >= 1 ;len--){
      pref = str.substr(i,len);
      if(palindrome(pref))
        break;
    }

    string suf = "";

    for(int len = (j-i+1);len >= 1 ;len--){
      suf = str.substr(j-len+1,len);
      if(palindrome(suf))
        break;
    }

    string add;
    if(sz(suf) > sz(pref))
      add = suf;
    else
      add = pref;

    cout << a + add + b << endl;
  
  }

  return 0;
}