#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  string s;
  cin >> n >> s;

  int inv = 0;

  int i = 0;
  bool plus2 = false;
  bool plus1 = false;

  int cnt = 0;

  while(i < n){
    char cur = s[i];
    cnt = 0;
    while(i < n && s[i] == cur)
      i++,cnt++;

    inv++;

    if(cnt >= 2)
      plus2 = true;
    

    if(i == n)
      break;

    cnt = 0;
    cur = s[i];

     while(i < n && s[i] == cur)
      i++,cnt++;
      
     if(cnt >= 2)
      plus2 = true;

    inv++;
  }
 
  if(plus2)
    inv+=2;


  cout << min(inv,n) << endl;
  return 0;
}