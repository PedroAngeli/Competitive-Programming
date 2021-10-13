#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector <string> inst;
  string exception;
  vector <pair <string,string> > catchs;
  cin.ignore();

  while(n--){
    string line;
    getline(cin,line);

    if(line.find("try") != string :: npos && line.find("catch") == string :: npos && line.find("throw") == string :: npos){
      inst.push_back("try");
    }else if(line.find("throw") != string :: npos){
      int p1 = line.find("(");
      int p2 = line.find(")");
      p1++;
      exception = line.substr(p1,p2-p1);
      exception.erase(remove(exception.begin(), exception.end(), ' '), exception.end());
      inst.push_back("throw");
    }else if(line.find("catch") != string::npos){
      int p1 = line.find("\"");
      int p2 = line.find("\"",p1+1);
      p1++;
      string message = line.substr(p1,p2-p1);
      p1 = line.find("(");
      p2 = line.find(",");
      p1++;
      string type = line.substr(p1,p2-p1);
      type.erase(remove(type.begin(), type.end(), ' '), type.end());
      catchs.push_back({type,message});
      inst.push_back("catch");
    }
  }

  stack <int> idx;
  int mpCatch[100000] = {0};
  int j = 0;
  int m = 0;

  for(int i=0;i<inst.size();i++){
    if(inst[i] == "try"){
      idx.push(j);
      j++;
    }else if(inst[i] == "catch"){
      int t = idx.top();
      idx.pop();
      mpCatch[t] = m;
      m++;
    }
  }

  stack <pair<string,string> > s;
  int t = 0;

  for(int i=0;i<inst.size();i++){
    if(inst[i] == "try"){
      s.push(catchs[mpCatch[t]]);
      t++;
    }else if(inst[i] == "catch"){
      s.pop();
    }else{
      while(!s.empty()){
        string type = s.top().first;
        string message = s.top().second;
        if(type == exception){
          cout << message << endl;
          return 0;
        }
        s.pop();
      }
      break;
    }
  }

  cout << "Unhandled Exception" << endl;

  return 0;
}