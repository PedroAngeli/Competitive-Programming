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


int main(){
  int n,node = 1,response = 1, parent = 1,lastResponse = INT_MAX;

  scanf("%d",&n);
  

  while(true){
    printf("%d\n",node);
    fflush(stdout);
    scanf("%d",&response);

    if(response == 0){
      printf("! %d\n",node);
      fflush(stdout);
      return 0;
    }else if(response > lastResponse){
     
    }else{
      
    }

    lastResponse = response; 
  }
  
  return 0;
}