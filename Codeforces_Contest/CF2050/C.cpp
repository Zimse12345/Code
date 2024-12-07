#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,m,f[10],g[10];
char s[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        m=strlen(s+1);
        for(int i=0;i<9;i++)f[i]=g[i]=0;
        f[0]=1;
        for(int i=1;i<=m;i++){
            int v=s[i]-'0';
            for(int x=v;x-v<9;x++)g[x%9]|=f[x-v];
            while(v>1&&v<10){
                v=v*v;
                if(v<10)for(int x=v;x-v<9;x++)g[x%9]|=f[x-v];
            }
            for(int x=0;x<9;x++)f[x]=g[x],g[x]=0;
        }
        if(f[0])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


