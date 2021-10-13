#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
//Computa a função do prefixo do pattern.
//Roda em O(|pattern|)
//pi[i] -> É o maior sufixo da string de 0..i que também é prefixo.
//Ex: pattern = "a|b|a|c|a|b|a|b"
//         Pi =  0|0|1|0|1|2|3|2 
vector <int> pi(string& pattern){ 
    vector <int> p(sz(pattern), 0);
    for(int i=1,j=0;i<sz(pattern);i++){
      while(j > 0 and pattern[i] != pattern[j]) j = p[j-1];
      if(pattern[i] == pattern[j]) j++;
      p[i] = j;
      if(j == sz(pattern)) j = p[j-1];
    }
    return p;
}
//recebe o texto e o padrão e retorna os indices dos matchings.
//Roda em O(|text| + |pattern|) (Achar matchings + Pi)
vector <int> matching(string& text, string& pattern){ 
    vector <int> p = pi(pattern);
    vector <int> match;
    for(int i=0,j=0;i<sz(text);i++){
      while(j > 0 and text[i] != pattern[j]) j = p[j-1]; //j diminui em pelo menos 1
      if(text[i] == pattern[j]) j++; //j aumenta no máximo |text| vezes
      if(j == sz(pattern)) match.push_back(i - j + 1), j = p[j-1];
    }
    return match;
}