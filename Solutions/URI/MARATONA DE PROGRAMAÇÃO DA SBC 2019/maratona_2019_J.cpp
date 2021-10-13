#include <bits/stdc++.h>

using namespace std;

map <char,int> carta_value;
vector <string> cartas;
int N,K;
bool passar_coringa;

int vencedor(){

  for(int i=1;i<=N;i++){
    int count = 0;
    for(int j=0;j<cartas[i].size()-1;j++){
      if(cartas[i][j] == cartas[i][j+1]){
        count++;
      }else{
        break;
      }
    }

    if(count == cartas[i].size()-1){
      return i;
    }
  }

  return 0;
}

char passa_carta(int k){

  map <char,int> conta_cartas;

  for(int i = 0;i<cartas[k].size();i++){
    if(cartas[k][i] == 'C'){
      if(passar_coringa){
        cartas[k].erase(cartas[k].begin() + i);
        passar_coringa = false;
        return 'C';
      }else{
        passar_coringa = true;
      }
    }

    if(cartas[k][i] != 'C')
      conta_cartas[cartas[k][i]]++;
  }

  char carta = 'C';
  int menor = 1e9 + 5;

  map <char,int> :: iterator it;

  for(it=conta_cartas.begin();it!=conta_cartas.end();it++){
    if(it->second < menor && it->first != 'C'){
      menor = it->second;
      carta = it->first;
    }else if(it->second == menor && carta_value[it->first] < carta_value[carta] && it->first != 'C'){
      menor = it->second;
      carta = it->first;
    }

    // cout << it->second << " " << it->first << endl;
  }

  for(int i = 0;i<cartas[k].size();i++){
    if(cartas[k][i] == carta){
      cartas[k].erase(cartas[k].begin() + i);
      break;
    }
  }

  // cout << carta << endl;

  return carta;
}

int main(){

  cin >> N >> K;

  carta_value['C'] = 1e9 + 5;
  carta_value['A'] = 1;
  carta_value['2'] = 2;
  carta_value['3'] = 3;
  carta_value['4'] = 4;
  carta_value['5'] = 5;
  carta_value['6'] = 6;
  carta_value['7'] = 7;
  carta_value['8'] = 8;
  carta_value['9'] = 9;
  carta_value['D'] = 10;
  carta_value['Q'] = 11;
  carta_value['J'] = 12;
  carta_value['K'] = 13;

  cartas = vector <string> (N+1);

  for(int i=1;i<=N;i++)
    cin >> cartas[i];

  cartas[K] += "C";
  int winner;
  int k = K;
  passar_coringa = false;

  while(true){

    winner = vencedor();
    if(winner)
      break;

    char carta = passa_carta(k);

    // cout << cartas[k] << endl;

    k++;

    if(k == N+1)
      k = 1;

    cartas[k] += carta;
  }

  cout << winner << endl;

  return 0;
}