#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

bool visitado[10][10];

bool valid(int i,int j){
  return i>=1 && i <=8 && j>=1 && j <=8 && !visitado[i][j];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 
  string s1,s2;

  while(cin >> s1 >> s2){
    int x1 = s1[1]-'0';
    int y1 = s1[0]-'a'+1;
    int x2 = s2[1]-'0';
    int y2 = s2[0]-'a'+1;

    if(x1 == x2 && y1 == y2){
            cout << "To get from " << s1 << " to " << s2 << " takes " << 0 << " knight moves." << endl;
        continue;
    }

    memset(visitado,false,sizeof visitado);

    queue <pair <pair <int,int> ,int> > q;
    visitado[x1][y1] = true;
    q.push({{x1,y1},0});
    bool flag = true;
    while(!q.empty() && flag){
      auto p = q.front();
      q.pop();
      vector <pair <int,int> > mov = {{-1,2},{1,2},{-2,1},{2,1},{1,-2},{-1,-2},{-2,-1},{2,-1}};

      for(int i=0;i<8;i++){
        int dx = p.first.first + mov[i].first;
        int dy = p.first.second + mov[i].second;
        int dist = p.second;

        if(valid(dx,dy)){
          visitado[dx][dy] = true;
          if(dx == x2 && dy == y2){
            cout << "To get from " << s1 << " to " << s2 << " takes " << dist+1 << " knight moves." << endl;
            flag = false;
            break;
          }
          q.push({{dx,dy},dist+1});
        }
      }
    }
  }
  
  return 0;
}