#include <bits/stdc++.h>

using namespace std;

int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<48||57<c){if(c==45)y=-1;c=getchar();}
    while(47<c&&c<58)x=x*10+c-48,c=getchar();
    return x*y;
}

const int N=1e6+10,inf=1e9;
int T,n,a[N],f[N][4],g[N],p[4];

signed main(){
    T=read();
    p[1]=p[2]=1,p[3]=2;
    while(T--){
        n=read();
        for(int i=0;i<=n;i++)f[i][1]=f[i][2]=f[i][3]=inf;
        for(int i=1;i<=n;i++){
            a[i]=read();
            f[i][0]=g[i-1]+1;
            if(a[i]<=4){
                for(int j=0;j<4;j++)f[i][j]=min(f[i][j],f[i-1][3^j]+p[j]);
            }
            if(a[i]<=2){
                f[i][0]=min(f[i][0],min(f[i-1][3],f[i-1][1]));
                f[i][1]=f[i-1][0]+1;
            }
            if(a[i]<=0)f[i][0]=g[i-1];
            g[i]=min(min(f[i][0],f[i][1]),min(f[i][2],f[i][3]));
        }
        printf("%d\n",g[n]);
    }
    return 0;
}

