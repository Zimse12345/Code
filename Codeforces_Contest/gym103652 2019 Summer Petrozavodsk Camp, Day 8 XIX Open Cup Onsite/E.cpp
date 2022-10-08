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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,k,L,R,v1[N],v2[N],w1,w2;

signed main(){
    T=read();
    for(int I=1;I<=T;I++){
        int ans=0,ValL=0,ValR;
        k=read(),L=read(),R=read();
        int _L=L,_R=R;
        w1=w2=0;
        while(L)v1[++w1]=L%k,L/=k;
        ValL=ValR=R;
        while(R)v2[++w2]=R%k,R/=k,ans+=v2[w2]+1;
        v1[w1+1]=v2[w2+1]=0;
        for(int i=w2,tag=1;i>=1;i--){
            if(v1[i]!=v2[i])tag=0;
            if(w1<w2||!tag)if(v2[i]!=0){
                int val=0,qwq=0;
                for(int j=w2;j>i;j--)val=val*k+v2[j],qwq+=v2[j]+1;
                val=val*k+(v2[i]-1),qwq+=v2[i]-1;
                if(!(i==w2&&v2[w2]==1))++qwq;
                for(int j=i-1;j>=1;j--)val=val*k+k-1,qwq+=k;
                if(qwq>ans)ans=qwq,ValL=ValR=val;
                else if(qwq==ans)ValL=min(ValL,val),ValR=max(ValR,val);
            }
        }
        printf("Case #%lld: %lld %lld %lld\n",I,ans-2,ValL,ValR);
    }
    return 0;
}
