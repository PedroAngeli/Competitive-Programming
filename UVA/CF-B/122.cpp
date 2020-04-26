#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <string> tree;

bool cmp(pair <string,int> p1,pair <string,int> p2){
  return p1.first.size() < p2.first.size() || p1.first.size() == p2.first.size() && p1.first < p2.first;
}

void solve(){
  vector <pair <string, int> > ans;
  set <string> s;
  int n = tree.size();

  for(int i=0;i<n;i++){
    int j=1;
    while(tree[i][j] >= '0' && tree[i][j] <= '9')
      j++;

    string temp(tree[i].begin()+1,tree[i].begin()+j);
    int val = stoi(temp);

    int k = j+1;

    while(tree[i][k] != ')')
      k++;
    
    string temp2(tree[i].begin()+j+1,tree[i].begin()+k);

    if(s.count(temp2)){
       cout << "not complete" << endl;
       return;
    }

    s.insert(temp2);

    ans.push_back({temp2,val});
  }

  for(auto it = s.begin();it != s.end();it++){
    if(*it != ""){
      string cur = *it;
      int len = cur.size();
      string temp = cur.substr(0,len-1);

      if(!s.count(temp)){
        cout << "not complete" << endl;
        return;
      }
    }
  }

  sort(ans.begin(),ans.end(),cmp);

  for(int i=0;i<n;i++){
    if(i == n-1)
    cout << ans[i].second;
    else
    cout << ans[i].second << " ";
  }
  cout << endl;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  string s;

  while(cin >> s){
    if(s == "()"){
      solve();
      tree.clear();
      continue;
    }
    
    tree.push_back(s);
  }

  return 0;
}