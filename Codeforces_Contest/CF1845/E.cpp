#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2.01e3,Mod=1000000007;
int n,k,a[N],pos[N],m,ans,f[2][N][N],T,l[N],r[N],suf[N];

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])pos[++m]=i;
    }
    for(int i=m;i>=1;i--)suf[i]=suf[i+1]+pos[i];
    f[T][0][0]=1;
    for(int i=1;i<=m;i++){
        l[i]=1,r[i]=pos[i];
        while(1){
            int tag=0;
            for(int x=0;x<=k;x++)if(f[T][l[i]-1][x])tag=1;
            if(tag)break;
            ++l[i];
        }
        int L=pos[i]+1,R=n;
        while(L<=R){
            int M=(L+R)/2;
            int tag=1;
            for(int j=i;j<=m;j++)if((M+M+(j-i+1)-1)*(j-i+1)/2-(suf[i]-suf[j+1])>k){tag=0;break;}
            if(!tag)R=M-1;
            else L=M+1,r[i]=M;
        }
        T^=1;
        for(int x=0;x<=k;x++){
            int sum=0;
            for(int p=l[i];p<=r[i];p++){
                (sum+=f[T^1][p-1][x])%=Mod;
                int _x=x+_abs(p-pos[i]);
                if(_x<=k)(f[T][p][_x]+=sum)%=Mod;
            }
            for(int p=l[i-1];p<=r[i-1];p++)f[T^1][p][x]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j-=2)(ans+=f[T][i][j])%=Mod;
    }
    printf("%lld\n",ans);
    return 0;
}



