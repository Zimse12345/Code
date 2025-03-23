#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,Mod=998244353;
int n,f[N],g[N],h[N];
char s[N],_s[N];

signed main(){
    cin>>n;
    scanf("%s",_s+1);
    int p=n+1,c=0;
    for(int i=1;i<=n;i++)if(_s[i]=='1'){
        p=i;
        break;
    }
    for(int i=p;i<=n;i++)s[++c]=_s[i];
    for(int i=1;i<p;i++)s[++c]=_s[i];
    f[1]=g[1]=1;
    if(s[1]=='1')h[1]=1,f[1]=g[1]=2;
    for(int i=2;i<=n;i++){
        if(s[i]=='1'){
            f[i]+=g[i-1];//0
            f[i]+=g[i-1]+f[i-1]-h[i-1];//1
            f[i]+=f[i-1];//2
            
            g[i]+=g[i-1];//1
            g[i]+=g[i-1]+f[i-1]-h[i-1];//2
            g[i]+=f[i-1];//3
            
            h[i]+=g[i-1];//1
            h[i]+=f[i-1];//2
        }
        else{
            f[i]+=g[i-1];//0
            f[i]+=f[i-1];//1
            
            g[i]+=g[i-1];//1
            g[i]+=f[i-1];//2
            
            h[i]+=h[i-1];//1;
        }
        f[i]%=Mod,g[i]%=Mod,h[i]%=Mod;
    }
    int ans=f[n]+g[n];
    for(int i=1;i<=n;i++)f[i]=g[i]=h[i]=0;
    if(s[1]=='1')f[1]=g[1]=1;
    for(int i=2;i<=n;i++){
        if(s[i]=='1'){
            f[i]+=g[i-1];//0
            f[i]+=g[i-1]+f[i-1]-h[i-1];//1
            f[i]+=f[i-1];//2
            
            g[i]+=g[i-1];//1
            g[i]+=g[i-1]+f[i-1]-h[i-1];//2
            g[i]+=f[i-1];//3
            
            h[i]+=g[i-1];//1
            h[i]+=f[i-1];//2
        }
        else{
            f[i]+=g[i-1];//0
            f[i]+=f[i-1];//1
            
            g[i]+=g[i-1];//1
            g[i]+=f[i-1];//2
            
            h[i]+=h[i-1];//1;
        }
        f[i]%=Mod,g[i]%=Mod,h[i]%=Mod;
    }
    ans-=h[n]+2;
    if(p>n)++ans;
    printf("%lld\n",(ans%Mod+Mod)%Mod);
    return 0;
}


