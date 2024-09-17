#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N],L[N],d[N];
int g[N][20],ans;

inline int gcd(int x,int y){
    if(!y)return x;
    return gcd(y,x%y);
}

inline int lowbit(int x){
    return x&(-x);
}

inline int popc(int x){
    int c=0;
    while(x)x^=lowbit(x),++c;
    return c; 
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            d[i]=a[i]-a[i-1];
            if(d[i]<0)d[i]=-d[i];
            if(a[i-1]!=a[i])L[i]=i-1;
            else L[i]=L[i-1];
            g[i][0]=d[i];
            for(int j=1;j<20&&i>(1<<(j-1));j++)g[i][j]=gcd(g[i][j-1],g[i-(1<<(j-1))][j-1]);
        }
        ans=0;
        for(int r=1;r<=n;r++){
            ans+=r-L[r];
            int l=L[r]+1,G=0;
            while(1){
                int t=19;
                while(t>=0&&(1<<t)>=l)--t;
                while(t>=0&&popc(gcd(G,g[l][t]))==1)--t;
                if(t>=0)G=gcd(G,g[l][t]),l-=(1<<t);
                else break;
            }
            ans+=l-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


