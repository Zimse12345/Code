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

const int N=1e6+7,Mod=998244353,INF=2e18+7;
int T,n,m,C,c[N];
double a[N],A[N],mx[N],atk[N];

signed main(){
	n=read(),C=read();
	for(int i=1;i<=n;i++)c[i]=read(),a[i]=double(read())*double(read()),mx[c[i]]=max(mx[c[i]],a[i]);
	for(int i=1;i<=C;i++)if(mx[i]>0)for(int j=1;i*j<=C;j++)atk[i*j]=max(atk[i*j],mx[i]*j);
	for(int i=1;i<=C;i++)atk[i]=max(atk[i],atk[i-1]);
	m=read();
	for(int i=1;i<=m;i++){
		A[i]=double(read())*double(read());
		int L=0,R=C,ans=-1;
		while(L<=R){
			int M=(L+R)>>1;
			if(atk[M]>A[i])ans=M,R=M-1;
			else L=M+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

