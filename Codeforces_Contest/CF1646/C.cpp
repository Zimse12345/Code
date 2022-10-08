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
int T,n,fac[N];
inline void db(int& x){x-=(x&(-x));return;}

signed main(){
    fac[0]=1;
    for(int i=1;i<=18;i++)fac[i]=fac[i-1]*i;
    for(int i=1;i<=18;i++)fac[i-1]=fac[i];
	T=read();
	while(T--){
        int ans=INF;
        n=read();
        for(int i=0,s,c;i<(1<<18);i++){
            s=0,c=0;
            for(int j=0;j<18;j++)if(i&(1<<j))s+=fac[j],++c;
            if(s<=n){
                s=n-s;
                while(s)db(s),++c;
                ans=min(ans,c);
            }
        }
        if(ans==INF)ans=-1;
        printf("%lld\n",ans);
	}
	return 0;
}
