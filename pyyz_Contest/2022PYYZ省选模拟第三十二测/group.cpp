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

const int N=5e5+7,Mod=998244353,INF=1e15+7;
int n,m,_n,a[N],s[N],suf[N],f[2][N],ans=INF,_t,que[N],Tag=1;
inline double X(int i){return -suf[i];}
inline double Y(int i){return f[_t][i-1];}

void dp(int t){
	_t=t^1;
	int l=1,r=0;
	int tag=0;
	for(int i=1;i<=n;i++){
		while(l<r&&(Y(i)-Y(que[r]))/(X(i)-X(que[r]))<=(Y(que[r])-Y(que[r-1]))/(X(que[r])-X(que[r-1])))--r;
		que[++r]=i;
		while(l<r&&a[i]>=(Y(que[l+1])-Y(que[l]))/(X(que[l+1])-X(que[l])))++l;
		f[t][i]=f[_t][que[l]-1]+a[i]*suf[que[l]];
		if(f[t][i]<f[t^1][i])tag=1;
//		f[t][i]=INF;
//		for(int j=i;j>=1;j--)f[t][i]=min(f[t][i],f[t^1][j-1]+a[i]*suf[j]);
	}
	Tag=tag;
	ans=min(ans,f[t][n]);
//	printf("[%lld %lld]\n",t,f[t][n]);
	return;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[i]=1;
	for(int i=1;i<=n;i++){
		if(a[i]>a[_n])a[++_n]=a[i],s[_n]=1;
		else ++s[_n];
	}
	n=_n;
	for(int i=n;i>=1;i--)suf[i]=s[i]+suf[i+1];
	for(int i=1;i<=n;i++)f[0][i]=INF;
	for(int i=1;i<=m;i++){
		dp(i&1);
		if(!Tag)break;
	}
	printf("%lld\n",ans);
	return 0;
}

