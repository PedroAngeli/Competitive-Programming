#include <bits/stdc++.h>

using namespace std;

map <string, pair <long long int, pair <long long int,long long int> > > carros;
map <string, pair <string, long long int> > esp;

int main(){
  long long int t;
  cin >> t;

  while(t--){
    long long int n,m;
    cin >> n >> m;
    carros.clear();
    esp.clear();

    while(n--){
      string car;
      long long int c,p,k;
      cin >> car >> c >> p >> k;
      carros[car] = make_pair(c, make_pair(p,k));
    }

    while(m--){
      long long int temp;
      char event;
      string spy;

      cin >> temp >> spy >> event;

      if(event == 'p'){
        string car;
        cin >> car;

        if(!esp.count(spy)){
          esp[spy] = make_pair(car,carros[car].second.first);
        }else{
          if(esp[spy].first == ""){
            long long int cost = esp[spy].second;
            esp[spy] = make_pair(car,carros[car].second.first + cost);
          }else{
            esp[spy] = make_pair("INCONSISTENT",0);
          }
        }
      }

      if(event == 'a'){
        long long int percent;
        cin >> percent;

        if(!esp.count(spy)){
          esp[spy] = make_pair("INCONSISTENT",0);
        }else{
          if(esp[spy].first != "" && esp[spy].first != "INCONSISTENT"){
            string car = esp[spy].first;
            long long int cost = esp[spy].second;
            esp[spy] = make_pair(car,(long long int)ceil((carros[car].first * percent)/100.0) + cost);
          }else{
            esp[spy] = make_pair("INCONSISTENT",0);
          }
        }
      }

      if(event == 'r'){
        long long int km;
        cin >> km;

        if(!esp.count(spy)){
          esp[spy] = make_pair("INCONSISTENT",0);
        }else{
          if(esp[spy].first == "" || esp[spy].first == "INCONSISTENT"){
            esp[spy] = make_pair("INCONSISTENT",0);
          }else{
            long long int cost = esp[spy].second;
            string car = esp[spy].first;
            esp[spy] = make_pair("",carros[car].second.second * km + cost);
          }
        }
      }
    }

    map <string, pair <string, long long int> > :: iterator it;

    for(it = esp.begin();it != esp.end();it++){
      string spy = it->first;
      string car = it->second.first;

      if(car != ""){
        cout << spy << " " << "INCONSISTENT" << endl;
      }else{
        long long int cost = it->second.second;
        cout << spy << " " << cost << endl;
      }
    }
  }

  return 0;
}