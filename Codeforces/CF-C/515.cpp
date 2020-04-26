#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[10];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long a;

  cin >> a;

  while(a){
    int dig = a%10;
    if(dig == 2) cnt[2]++;
    if(dig == 3) cnt[3]++,cnt[2]++;
    if(dig == 4) cnt[2]+=3,cnt[3]++;
    if(dig == 5) cnt[5]++;
    if(dig == 6) cnt[5]++,cnt[3]++,cnt[2]++;
    if(dig == 7) cnt[7]++;
    if(dig == 8) cnt[7]++,cnt[2]+=3;
    if(dig == 9) cnt[7]++,cnt[2]+=3,cnt[3]+=2;
    a /= 10;
  }

  vector <int> ans;

  for(int i=0;i<cnt[7];i++)
    ans.push_back(7);

  for(int i=0;i<cnt[5];i++)
    ans.push_back(5);

  for(int i=0;i<cnt[3];i++)
    ans.push_back(3);

  for(int i=0;i<cnt[2]-cnt[3];i++)
    ans.push_back(2);


  for(int i=0;i<ans.size();i++)
    cout << ans[i];

  cout << endl;
  

  return 0;
}