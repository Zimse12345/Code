#include <bits/stdc++.h>
using namespace std;

const int N=10;


signed main(){
    system("md data");
    for(int T=1;T<=N;T++){
        freopen("id.txt","w",stdout);
        cout<<T<<" ";
        fclose(stdout);
        system("maker.exe");
        
        
        char c1='0'+(T/10),c2='0'+(T%10);
        string s="cp data.in ./data/data";
        char str[256];
        int len=s.length();
        for(int i=0;i<len;i++)str[i]=s[i];
        str[len]=c1,str[len+1]=c2;
        str[len+2]='.',str[len+3]='i',str[len+4]='n',str[len+5]='\0';
        system(str);
        
        s="cp data.out ./data/data";
        len=s.length();
        for(int i=0;i<len;i++)str[i]=s[i];
        str[len]=c1,str[len+1]=c2;
        str[len+2]='.',str[len+3]='o',str[len+4]='u',str[len+5]='t',str[len+6]='\0';
        system(str);
    } 
    return 0;
}


