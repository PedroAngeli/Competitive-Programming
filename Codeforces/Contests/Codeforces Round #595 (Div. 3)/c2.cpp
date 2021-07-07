#include <bits/stdc++.h>

using namespace std;

vector <int> convertToTernary(long long n){

  vector <int> converted;

  while(n > 0){
    converted.push_back(n % 3);
    n = n/3;
  }

  return converted;
}

vector <int> findComplement(vector <int> &converted){
  vector <int> complement(converted.size(),0);
  bool two = false;
  int maxtwo = 0;

  for(int i =0 ;i<converted.size();i++){
    if(converted[i] == 2){
      two = true;
      maxtwo = i;
    }
  }

  if(!two)
  return complement;

  complement.clear();
  int vaium = 0;

  for(int i =0 ;i<converted.size();i++){
    int el = converted[i];

    if(el == 2){
      int sum = el + vaium;
      vaium = 1;
      if(sum == 3){
        complement.push_back(0);
      }else{
        complement.push_back(1);
      }
    }
    else if(el == 1){
      int sum = el + vaium;
      

      if(i > maxtwo){
        if(sum == 2){
          complement.push_back(1);
          vaium = 1;
        }else{
          complement.push_back(0);
          vaium = 0;
        }

        continue;
      }
      vaium = 1;
      if(sum == 2){
        complement.push_back(1);
      }else{
        complement.push_back(2);
      }
    }else{
      int sum = el + vaium;

      if(i > maxtwo){
        complement.push_back(0);
        vaium = 0;
        continue;
      }

      if(sum == 1){
        vaium = 1;
        complement.push_back(2);
      }else{
        vaium = 0;
        complement.push_back(0);
      }
    }
  }

  return complement;
}

long long potencia(long long a,long long b){
  long long ans = 1;
  for(int i=1;i<=b;i++){
    ans = ans * a;
  }

  return ans;
}

long long convertToDecimal(vector <int> & complement){
  long long ans = 0;

  for(int i=0;i<complement.size();i++){
    ans = ans + (complement[i] * potencia(3,i));
  }

  return ans;
}



int main(){

  int q;
  cin >> q;

  while(q--){
    long long n;
    cin >> n;
    
    vector <int> converted = convertToTernary(n);
    vector <int> complement = findComplement(converted);
    
    long long ans = convertToDecimal(complement);

    cout << ans + n << endl;
    
  }

  return 0;
}