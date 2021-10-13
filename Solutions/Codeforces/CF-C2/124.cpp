#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[26];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int n = s.size();

  for(int i=0;i<n;i++)
    cnt[s[i]-'a']++;

  string ans;
  ans.assign(n+1,'\0');

  vector <int> primes;
  vector <bool> isPrime(n+1,true);

  for(int i=2;i<=n;i++){
    if(isPrime[i]){
      primes.push_back(i);
      for(int j=i*i;j<=n;j+=i){
        isPrime[j] = false;
      }
    }
  }
  int len = primes.size();

  for(int i=0;i<len;i++){
    int p = primes[i];
    vector <int> idx;
    char c = '\0';
    int mult = 1;

    while(true){
      p = primes[i]*mult;
      if(p > n)
        break;
      if(ans[p])
        c = ans[p];
      if(!ans[p])
       idx.push_back(p);
      mult++;
    }

    int mnChar = idx.size();

    if(c){
      for(int j=0;j<mnChar;j++){
        if(cnt[c-'a'] == 0){
          cout << "NO" << endl;
          return 0;
        }
        cnt[c-'a']--;
        ans[idx[j]]=c;
      }
    }else{
      int freq = INT_MAX;
      char chosen = '\0';

      for(int j=0;j<26;j++){
        if(cnt[j] >= mnChar && freq > cnt[j]){
          freq = cnt[j];
          chosen = j+'a';
        }
      }

      if(!chosen){
        cout << "NO" << endl;
        return 0;
      }else{
        for(int j=0;j<mnChar;j++){
          cnt[chosen-'a']--;
          ans[idx[j]]=chosen;
        }
      }
    }
  }

  for(int i=0;i<26;i++)
    if(cnt[i]){
      ans[1] = i+'a';
      break;
    }
  ans.erase(ans.begin());
  
  cout << "YES" << endl;
  cout << ans << endl;

  
  
  return 0;
}