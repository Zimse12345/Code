#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n;
char s[N];

signed main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int l=1;l<=n;){
        if(s[l]=='W'){
            int r=l+1;
            while(s[r]=='W')++r;
            if(s[r]=='A'){
                s[l]='A';
                for(int j=l+1;j<=r;j++)s[j]='C';
            }
            l=r+1;
        }
        else ++l;
    }
    for(int i=1;i<=n;i++)printf("%c",s[i]);
    return 0;
}


