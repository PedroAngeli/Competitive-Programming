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
  fastio;

  int n;
  scanf("%d",&n);

  vi ans(n);

  for(int i=0;i<n-1;i++){
    if(ans[i])
      continue;
    bool encontrou = false;

    for(int j=0;j<n;j++){
      if(i == j || ans[j])
        continue;
      printf("? %d %d\n",i+1,j+1);
      fflush(stdout);

      int r1;
      scanf("%d",&r1);

      printf("? %d %d\n",j+1,i+1);
      fflush(stdout);

      int r2;
      scanf("%d",&r2);

      if(r1 > r2){
        ans[i] = r1;
        encontrou = true;
        break;
      }else
        ans[j] = r2;
    }

    if(!encontrou)
      ans[i] = n;
  }

  if(ans[n-1] == 0)
    ans[n-1] = n;
  
  printf("! ");
  for(int x : ans)
    printf("%d ",x);
  printf("\n");
  fflush(stdout);


  return 0;
}