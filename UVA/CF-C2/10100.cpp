#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){    

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    string s1,s2;
    int test=1;

    while(getline(cin,s1)){
        getline(cin,s2);
        vector <string> v1,v2;
        cout << setw(2) << test++ <<". ";
        
        for(int i=0;i<s1.size();i++) 
          if(!isupper(s1[i]) && !islower(s1[i]) && !isdigit(s1[i])) 
            s1[i]=' ';

        for(int i=0;i<s2.size();i++) 
          if(!isupper(s2[i]) && !islower(s2[i]) && !isdigit(s2[i])) 
            s2[i]=' ';
          
        istringstream is1(s1);
        istringstream is2(s2);

        string s;
        while(is1>>s) 
          v1.push_back(s);
        while(is2>>s) 
          v2.push_back(s);
        
        int n=v1.size();
        int m=v2.size();
        
        if(m==0 || n==0){
            cout<< "Blank!"<<endl;
            continue;
        }

        vector <vector <int> > lcs(n+1,vector <int>(m+1,0));
        vector <vector <bool> > equal(n,vector <bool>(m,false));

        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
            if(v1[i] == v2[j])
              equal[i][j] = true;

      lcs[0][0] = 0;

      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
          if(equal[i-1][j-1])
            lcs[i][j] = 1 + lcs[i-1][j-1];
          else
            lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
        }

      cout << "Length of longest match: " << lcs[n][m] << endl;
    }
    
    return 0;
}