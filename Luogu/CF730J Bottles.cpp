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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],_b[N],sum,c,f[N][N*N],k,ans;

signed main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
    for(int i=1;i<=n;i++)_b[i]=b[i]=read();
    sort(_b+1,_b+n+1);
    int _s=sum;
    while(_s>0)_s-=_b[n-c],++c;
    for(int j=0;j<=c;j++)for(int i=0;i<=n*100;i++)f[j][i]=-INF;
    f[0][0]=0;
    for(int i=1;i<=n;i++){
    	for(int j=c;j>=1;j--){
    		for(int k=b[i];k<=n*100;k++)f[j][k]=max(f[j][k],f[j-1][k-b[i]]+a[i]);
		}
	}
	for(int k=sum;k<=n*100;k++)ans=max(ans,f[c][k]);
	ans=sum-ans;
	printf("%d %d\n",c,ans);
    return 0;
}
