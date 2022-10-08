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
int T,n,a[N];

signed main(){
	T=read();
    while(T--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)a[i]+=a[i-1];
        int ans=0;
        for(int i=1;i*2+1<=n;i++){
            if(a[i+1]<a[n]-a[n-i])ans=1;
        }
        if(ans)printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}
