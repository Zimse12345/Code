#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,f[N],M,q[N],L,R,g[N];
int s[8];
char s1[8],s2[8];

inline int hs(){
    int x=0;
    for(int i=n;i>=1;i--)x=x*10+s[i];
    return x;
}

signed main(){
    cin>>T;
    n=5,M=100000;
    for(int j=1;j<M;j++)f[j]=51;
    q[1]=0,L=R=1;
    while(L<=R){
        int x=q[L];
        for(int i=1;i<=n;i++)s[i]=x%10,x/=10;
        x=q[L++];
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                s[r]=(s[r]+1)%10;
                int h=hs();
                if(f[h]==51)f[h]=f[x]+1,q[++R]=h; 
            }
            for(int r=l;r<=n;r++)s[r]=(s[r]+9)%10;
            for(int r=l;r<=n;r++){
                s[r]=(s[r]+9)%10;
                int h=hs();
                if(f[h]==51)f[h]=f[x]+1,q[++R]=h; 
            }
            for(int r=l;r<=n;r++)s[r]=(s[r]+1)%10;
        }
    }
    while(T--){
        scanf("%s",s1+1);
        scanf("%s",s2+1);
        int d=0;
        for(int i=1;i<=4;i++){
            d=d*10+(s1[i]-s2[i]+10)%10;
        }
        printf("%d\n",f[d]);
    }
    return 0;
}


