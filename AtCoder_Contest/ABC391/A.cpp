#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n;
char s[N]; 

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='W')s[i]='E';
        else if(s[i]=='E')s[i]='W';
        else if(s[i]=='N')s[i]='S';
        else if(s[i]=='S')s[i]='N';
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}


