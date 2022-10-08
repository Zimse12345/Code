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

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],LL[N],RR[N],Lx[N],Rx[N],pre[32];
int stk[N],top;
ll ans;

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    a[0]=a[n+1]=INF;
    for(int i=1;i<=n;i++){
        while(top&&a[stk[top]]<=a[i])--top;
        LL[i]=stk[top]+1;
        stk[++top]=i;
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j))pre[j]=i;
            else Lx[i]=max(Lx[i],pre[j]);
        }
        ++Lx[i];
        Lx[i]=max(Lx[i],LL[i]);
    }
    top=0,stk[0]=n+1;
    for(int j=0;j<=30;j++)pre[j]=n+1;
    for(int i=n;i>=1;i--){
        while(top&&a[stk[top]]<a[i])--top;
        RR[i]=stk[top]-1;
        stk[++top]=i;
        Rx[i]=n+1;
        for(int j=0;j<=30;j++){
            if(a[i]&(1<<j))pre[j]=i;
            else Rx[i]=min(Rx[i],pre[j]);
        }
        --Rx[i];
        Rx[i]=min(Rx[i],RR[i]);
        ans+=1ll*(i-LL[i]+1)*(RR[i]-i+1)-1ll*(i-Lx[i]+1)*(Rx[i]-i+1);
    }
    printf("%lld\n",ans);
    return 0;
}
