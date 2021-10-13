#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool check(string s){
  set <char> conj;
  for(int i=0;i<4;i++)
    conj.insert(s[i]);
  
  return conj.size() == 4;
}

bool solve(string num, string s, int a, int b){
  int cntA = 0;
  int cntB = 0;
  for(int i=0;i<4;i++)
    if(num[i] == s[i])
      cntA++;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      if(i != j && num[i] == s[j])
        cntB++;
    }

  return a == cntA && b == cntB;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector <pair <string,pair <int,int> > > vet;

  for(int i=0;i<n;i++){
    string s;
    int a,b;
    cin >> s >> a >> b;
    vet.push_back({s,{a,b}});
  }

  vector <string> ans;

  for(char i='0';i<='9';i++){
    for(char j='0';j<='9';j++){
      for(char k='0';k<='9';k++){
        for(char l='0';l<='9';l++){
          char temp[5];
          temp[0] = i,temp[1] = j,temp[2] = k, temp[3] = l, temp[4] = '\0';
          string num = temp;
          if(!check(num))
            continue;
          bool can = true;
          for(int idx=0;idx<n;idx++){
            string s = vet[idx].first;
            int a = vet[idx].second.first;
            int b = vet[idx].second.second;
            if(!solve(num,s,a,b)){
              can = false;
              break;
            }
          }

          if(can){
            ans.push_back(num);
          }
        }
      }
    }
  }
  
  if(ans.size() == 0)
    cout << "Incorrect data" << endl;
  else if(ans.size() > 1)
    cout << "Need more data" << endl;
  else
    cout << ans[0] << endl;
  


  return 0;
}