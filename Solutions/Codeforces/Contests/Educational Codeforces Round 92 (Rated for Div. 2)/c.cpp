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

int sub(string a,string b){
  int cnt = 0;
  int n = a.size();
  int m = b.size();
  int i = 0;
  int j = 0;

  while(i < n){
    if(a[i] == b[j])
      i++,j++;
    else
      i++;
    if(j == m)
      j = 0,cnt++;
  }

  return cnt;
}
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    string a;
    cin >> a;
    int n = a.size();
    vi cnt(10,0);

    for(char c:a)
      cnt[c-'0']++;

    int ans = 0;
    for(int i=0;i<=9;i++)
      ans = max(ans,cnt[i]);

    ans = max(2,ans);
    vector<vi> grid(10,vi(10,0));

    int mx = 0;
    for(int i=0;i<=9;i++){
      for(int j=0;j<=9;j++){
        if(i == j)
          continue;
        string str;
        str.resize(2);
        str[0] = i+'0';
        str[1] = j+'0';
        mx = max(mx,sub(a,str));
      }
    }
    mx *= 2;
    ans = max(ans,mx);
    cout << n-ans << endl;
  }
 
  return 0;
}