#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

string getS1(string line){
  int i = 0;
  while(line[i] != ' ')
    i++;
  
  string ans = line.substr(0,i);

  return ans;
}

string getS2(string line){
  int n = line.size();
  int r = n-1;

  while(line[r] != '\'')
    r--;
  int l = r;
  while(line[l] != ' ')
    l--;
  l++;
  string ans = line.substr(l,r-l);

  return ans;
}

string getOp(string line){
  int l = 0;
  while(line[l] != ' ')
    l++;
  l++;
  int r = l;
  while(line[r] != ' ')
    r++;

  string ans = line.substr(l,r-l);

  return ans;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string myName;
  cin >> myName;

  int m;
  cin >> m;
  cin.ignore();
  unordered_map <string,int> p;

  while(m--){
    string line;
    getline(cin, line);
     string s1 = getS1(line);
     string s2 = getS2(line);
     string op = getOp(line);

    if(op == "posted"){
      if(s1 == myName)
        p[s2]+=15;
      else if(s2 == myName)
        p[s1]+=15;
      else{
        p[s1] += 0;
        p[s2] += 0;
      }
    }else if(op == "commented"){
       if(s1 == myName)
        p[s2]+=10;
      else if(s2 == myName)
        p[s1]+=10;
      else{
        p[s1] += 0;
        p[s2] += 0;
      }
    }else{
      if(s1 == myName)
        p[s2]+=5;
      else if(s2 == myName)
        p[s1]+=5;
      else{
        p[s1] += 0;
        p[s2] += 0;
      }
    }
  }
  
  vector <pair<int,string> > ans;

  for(auto it = p.begin();it!=p.end();it++){
    ans.push_back({it->second,it->first});
  }

  sort(ans.begin(),ans.end(), [&](auto p1,auto p2){
      int f1 = p1.first;
      int f2 = p2.first;
      string s1 = p1.second;
      string s2 = p2.second;

      return (f1 > f2) || (f1 == f2 && s1 < s2);
  });

  for(int i=0;i<ans.size();i++)
    cout << ans[i].second << endl;

  return 0;
}