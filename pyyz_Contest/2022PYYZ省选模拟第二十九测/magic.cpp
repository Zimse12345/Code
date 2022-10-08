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

const int N=2e6+7,Mod=998244353,INF=1e9+7;
int n,m,k,a[N],b[N],pre[N];
vector<int> g[N];
inline int calc_L(int sum,int cnt,int pos){return cnt*pos-sum-cnt*(cnt+1)/2;}
inline int calc_R(int sum,int cnt,int pos){return sum-cnt*pos-cnt*(cnt+1)/2;}
inline int calc(int lsum,int lc,int rsum,int rc,int pos){return calc_L(lsum,lc,pos)+calc_R(rsum,rc,pos);}

bool check(int x){
	for(int t=1;t<=m;t++){
		if(signed(g[t].size())<x)continue;
		int tot=0;
		for(unsigned i=0;i<g[t].size();i++)b[++tot]=g[t][i];
		for(unsigned i=0;i<g[t].size();i++)b[++tot]=g[t][i]+n;
		for(int i=1;i<=tot;i++)pre[i]=pre[i-1]+b[i];
		for(int i=1;i+x-1<=tot;i++){
			int L=i,R=i+x-1,M=(L+R)/2;
			if(calc(pre[M-1]-pre[L-1],M-L,pre[R]-pre[M],R-M,b[M])<=k)return true;
		}
//		int L=1,R=x;
//		int lsum=0,rsum=0,lc=0,rc=0,p=1;
//		for(int i=L+1;i<=R:i++)rsum+=b[i],++rc;
//		while(p<R){
//			int t1=calc(lsum,lc,rsum,rc,b[p]);
//			lsum+=b[p],rsum-=b[p+1],++lc,--rc;
//			int t2=calc(lsum,lc,rsum,rc,b[p+1]);
//			if(t2<=t1)++p;
//			else{
//				lsum-=b[p],rum+=b[p+1],--lc,++rc;
//				break;
//			}
//		}
//		if(calc(lsum,lc,rsum,rc,b[p])<=k)return true;
//		for(int i=2;i+x-1<=tot;i++){
//			
//		}
	}
	return false;
}

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		g[a[i]].push_back(i);
	}
	int L=2,R=n,ans=1;
	while(L<=R){
		int M=(L+R)>>1;
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	printf("%lld\n",ans);
	return 0;
}

