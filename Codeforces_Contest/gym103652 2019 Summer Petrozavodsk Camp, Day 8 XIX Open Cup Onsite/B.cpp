#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,P,a,c,X0,l1,r1,l2,r2,ans,X[N],pre[N],vis[N],t1[N],t2[N],presum[N],f[N];

signed main(){
    T=read();
    for(int I=1;I<=T;I++){
        P=read(),a=read(),c=read(),X0=read(),l1=read(),r1=read(),l2=read(),r2=read(),ans=0;
        for(int i=0;i<=P;i++)pre[i]=vis[i]=t1[i]=t2[i]=f[i]=0;
        int t=0,L=0;
        X[0]=X0;
        while(1){
            if(vis[X[t]]){
                L=pre[X[t]],--t;
                break;
            }
            else{
                pre[X[t]]=t,vis[X[t]]=1;
                X[t+1]=(X[t]*a+c)%P;
                ++t;
            }
        }
        for(int i=0;i<=t;i++){
            if(l1<=i&&i<=r1)++t1[X[i]];
            if(l2<=i&&i<=r2)++t2[X[i]+1];
        }
        // printf("[%d %d]\n",L,t);
        // for(int i=0;i<=t;i++)printf("%d ",X[i]);
        // printf("\n");
        int len=t-L+1;
        --l1,--l2;
        for(int i=L;i<=t;i++){
            int p=i-L+1;
            if(r1-t-p>=0)t1[X[i]]+=(r1-t-p)/len+1;
            if(l1-t-p>=0)t1[X[i]]-=(l1-t-p)/len+1;
            if(r2-t-p>=0)t2[X[i]+1]+=(r2-t-p)/len+1;
            if(l2-t-p>=0)t2[X[i]+1]-=(l2-t-p)/len+1;
        }
        int Sum=0;
        for(int i=1;i<=P;i++)Sum+=t2[i],presum[i]=presum[i-1]+i*t2[i];
        for(int i=1;i<=P;i++){
            for(int j=i;j<=P;j+=i)f[j]+=i*t2[i];
        }
        for(int i=1,ss=0;i<=P;i++){
            ss+=f[i];
            ans+=t1[i]*(Sum*i-ss);
        }
        // for(int i=0;i<=P;i++)for(int j=1;j<=P;j++)ans+=i%j*t1[i]*t2[j];
        printf("Case #%lld: %lld\n",I,ans);
    }
    return 0;
}
