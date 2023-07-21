#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,p[N],tot,a[N],vis[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        tot=0;
        for(int i=1;i<=n;i++)if(n%i==0)p[++tot]=i;
        for(int i=1;i<=n;i++){
            a[i]=0;
            for(int i=0;i<26;i++)vis[i]=0;
            for(int j=1;j<=tot;j++)if(i-p[j]>0)vis[a[i-p[j]]]=1;
            while(vis[a[i]])++a[i];
            printf("%c",'a'+a[i]);
        }
        printf("\n");
    }
    return 0;
}


