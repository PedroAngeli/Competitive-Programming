#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <int> fst;
vector <int> sec;

bool valid(vector <int> b, vector <int> s){
  for(int i=0;i<s.size();i++){
    if(abs(s[i]) != b[i])
      return false;
  }

  return true;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  int cntF = 0;
  int cntS = 0;
  long long sumF = 0;
  long long sumS = 0;
  int last;
  

  while(n--){
    long long a;
    cin >> a;

    if(a > 0){
      sumF += a;
      fst.push_back(a);
    }else{
      sumS +=a;
      sec.push_back(a);
    }

    last = a;
  }

  sumS*=-1;

  if(sumS > sumF){
    cout << "second" << endl;
  }else if(sumF > sumS){
    cout << "first" << endl;
  }else{
    int tamF = fst.size();
    int tamS = sec.size();

    if(tamF > tamS && valid(fst,sec)){
      cout << "first" << endl;
    }else if(tamS > tamF && valid(sec,fst)){
      cout << "second" << endl;
    }else{
      int i = 0;
      while(i < min(tamF,tamS)){
        if(fst[i] > abs(sec[i])){
          cout << "first" << endl;
          return 0;
        }

        if(abs(sec[i]) > fst[i]){
          cout << "second" << endl;
          return 0;
        }
        i++;
      }
      if(last > 0)
        cout << "first" << endl;
      else
        cout << "second" << endl;
    }
  }

 
  return 0;
}