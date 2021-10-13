#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int)(x).size()
vector <int> pi(string pattern){ 
    vector <int> p(sz(pattern), 0);
    for(int i=1,j=0;i<sz(pattern);i++){
      while(j > 0 and pattern[i] != pattern[j]) j = p[j-1];
      if(pattern[i] == pattern[j]) j++;
      p[i] = j;
    }
    return p;
}
struct Automato{
  //nxt[c][i] -> Para onde vou quando estou no estado (posição) i
  //e leio o caracter c.
  vector <vector <int> > nxt; 
  Automato(string& pattern): nxt(26, vector <int> (sz(pattern) + 1)){
    vector <int> p = pi(pattern+'$');
    nxt[pattern[0] - 'a'][0] = 1;
    for(char c=0;c<26;c++){
      for(int i=1;i<=sz(pattern);i++)
        nxt[c][i] = (c == pattern[i]-'a') ? i + 1 : nxt[c][p[i-1]];
    }
  }
};
//matching usando o Automato
//recebe o texto e o padrão e retorna os indices dos matchings.
//roda em O(|text|)
vector <int> matching(string& text, string& pattern){ 
    vector <int> match;
    auto aut = Automato(pattern);
    int at = 0;
    for(int i=0;i<sz(text);i++){
      at = aut.nxt[text[i] - 'a'][at];
      if(at == sz(pattern)) match.push_back(i - at + 1);
    }
    return match;
}