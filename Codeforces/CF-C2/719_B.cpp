#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;
 
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  string a;
  cin >> n >> a;
  
  int a1 = 0, b1 = 0, a2 = 0,b2 = 0;
  for(int i=0;i<n;i++){
    if(a[i] == 'r'){
      if(i%2 == 0)
        a1++;
      else
        a2++; 
    }else{
      if(i%2 == 0)
        b1++;
      else
        b2++; 
    }
  }
  cout << min(max(a1,b2),max(a2,b1)) << endl;
  return 0;
}