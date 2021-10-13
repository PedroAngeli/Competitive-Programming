#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  int sum =0;
  for(int i=0;i<n;i++)
    sum += s[i]-'0';

  if(sum % 3 == 0){
    cout << s << endl;
    return 0;
  }

  while(true){
    n = s.size();
    int pref[n];
    int suf[n];

    pref[0] = s[0]-'0';

    for(int i=1;i<n;i++){
      pref[i] = (s[i]-'0') + pref[i-1];
    }

    suf[n-1] = s[n-1]-'0';

    for(int i=n-2;i>=0;i--){
      suf[i] = (s[i]-'0') + suf[i+1];
    }

    int rightMost = -1;
    int pos = -1;

    for(int i=0;i<n;i++){
      int sum=0,curPref=0,curSuf=0;

      if(i == 0)
        curSuf = suf[i+1];
      else if(i == n-1)
        curPref = pref[i-1];
      else
        curPref = pref[i-1],curSuf = suf[i+1];

      sum = curPref + curSuf;

      if(sum % 3 == 0){
        rightMost = i;
      }else if((s[i]-'0')%3 != 0){
        pos = i;
      } 
    }

    if(rightMost != -1){
      if(rightMost == 0){
        int cnt = 0;
        int i = 1;
        while(s[i++] == '0')
          cnt++;
        if(cnt > 1 && pos!=-1){
          s.erase(s.begin() + pos);
          continue;
        }
      }
      s.erase(s.begin() + rightMost);
      int i = 0;
      while(s[i] == '0')
        i++;
      s.erase(s.begin(),s.begin()+i);
      if(s.size() == 0)
        s = "0";
      cout << s << endl;
      break;
    }else{
      if(s.size() == 0){
        cout << -1 << endl;
        break;
      }
      s.erase(s.begin() + pos);
    }
  }

  

  return 0;
}