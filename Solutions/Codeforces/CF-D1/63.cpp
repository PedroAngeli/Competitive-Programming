#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


int main(){
  fastio;
  
  int a,b,c,d,n;
  cin >> a >> b >> c >> d >> n;
  int m = a+c;
  int h = max(b,d);

  vi vet(n);
  vs ans(h,string(m,'.'));

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int i,j = 0;
  bool down; 

  if(a%2 == 0)
    i = 0,down = true;
  else if(b > d)
    i = h-1,down = false;
  else
    i = b-1,down= false;
  
  for(int k=0;k<n;k++){
    int cnt = vet[k];
    while(cnt){
        if(down){
        while(i < h && cnt){
          if(d > b && j < a && i == b)
            break;
          if(b > d && j >= a && i == d)
            break;
          ans[i][j] = k+'a',cnt--,i++;
        } 
        if(d > b && j < a && i == b)
          i = b-1,down = false,j++;
        else if(i == h)
          i = h-1, down = false,j++;
        else if(b > d && j >= a && i == d)
          i = d-1,down = false,j++;
      }else{
        while(i >= 0 && cnt)
          ans[i][j] = k+'a',cnt--,i--;
        if(i < 0)
          i = 0, down = true,j++;
      }
    }
  }

  cout << "YES" << endl;
  for(auto a:ans)
    cout << a << endl;

  return 0;
}