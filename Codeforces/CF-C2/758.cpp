#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

long long cnt[100][100];

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n,m,x,y;
  long long k;
  cin >> n >> m >> k >> x >> y;
  
  int total = m*n;

  if(n == 1){
    for(int j=0;j<m;j++){
      cnt[0][j] = (k/total);
    }

    int rest = k%total;
    for(int j=0;j<m && rest;j++,rest--)
      cnt[0][j]++;
  }
  else if(k <= total){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(k == 0){
          i = n;
          break;
        }
        cnt[i][j]++;
        k--;
      }
    }
  }else{
    long long newK = k - total;
    long long T = newK/(m*(n-1));
    long long rest = newK%(m*(n-1));

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(i == 0){
          cnt[i][j] = 1 + ((T+1)/2);
        }else if(i == n-1){
          cnt[i][j] = 1 + (T/2);
        }else{
          cnt[i][j] = 1 + T;
        }
      }
    }
    if(T % 2 == 1){
      for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
          if(rest == 0){
            i = n;
            break;
          }
          rest--;
          cnt[i][j]++;
        }
      }
    }else{
      for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
          if(rest == 0){
            i = 0;
            break;
          }
          rest--;
          cnt[i][j]++;
        }
      }
    }
  }

  long long mx = 0;
  long long mn = LLONG_MAX;
  long long sergei = cnt[x-1][y-1];

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      mx = max(mx,cnt[i][j]);
      mn = min(mn,cnt[i][j]);
    }
  }

  cout << mx << " " << mn << " " << sergei << endl;

  return 0;
}