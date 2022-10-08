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
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)>>1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e18;
int T,n,a[N],lt[N],rt[N],sum[N],stk[N],top,mx[N*2],mi[N*2],A[N];

void build(int L,int R,int id){
	if(L==R)mx[id]=mi[id]=sum[L];
	else build(L,M,Lid),build(M+1,R,Rid),mx[id]=max(mx[Lid],mx[Rid]),mi[id]=min(mi[Lid],mi[Rid]);
	return;
}

int qmax(int L,int R,int id,int l,int r){
	if(r<L||R<l)return -INF;
	if(l<=L&&r>=R)return mx[id];
	return max(qmax(L,M,Lid,l,r),qmax(M+1,R,Rid,l,r));
}

int qmin(int L,int R,int id,int l,int r){
	if(r<L||R<l)return INF;
	if(l<=L&&r>=R)return mi[id];
	return min(qmin(L,M,Lid,l,r),qmin(M+1,R,Rid,l,r));
}

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)A[i]=a[i]=read();
		top=0,stk[0]=0;
		for(int i=1;i<=n;i++){
			while(top&&a[i]>=a[stk[top]])--top;
			lt[i]=stk[top]+1,stk[++top]=i;
		}
		top=0,stk[0]=n+1;
		for(int i=n;i>=1;i--){
			while(top&&a[i]>=a[stk[top]])--top;
			rt[i]=stk[top]-1,stk[++top]=i;
		}
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		build(0,n,1);
		int ans=1;
		for(int i=1;i<=n;i++){
			int ms=qmax(0,n,1,i,rt[i])-qmin(0,n,1,lt[i]-1,i-1);
			if(ms>A[i]){ans=0;break;}
		}
		if(ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

