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
int p,n,m,s[N],t[N],S[N],ans,ab[N],ff[N];
int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%p;x=(x*x)%p,k/=2;}return res;}
int inv(int x){return qp(x,p-2);}

signed main(){
	p=read(),n=read(),m=read();
	for(int i=1;i<=n;i++)s[i]=read();
	for(int i=1;i<=m;i++)t[i]=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ab[(s[i]+s[j])%p]++;
	for(int x=0;x<p;x++){
		int _x=inv(x);
		ff[x]=(x+_x*_x)%p;
	}
	for(int x=1;x<p;x++){
		int _x=inv(x);
		for(int i=1,y;i<=n;i++)if(s[i]){
			y=s[i];
			S[ff[y*_x%p]]+=ab[x];
		}
	}
//	for(int ia=1;ia<=n;ia++){
//		for(int ib=1;ib<=n;ib++){
//			for(int ic=1;ic<=n;ic++){
//				int a=s[ia],b=s[ib],c=s[ic];
//				if((a*c+b*c)%p==0||c%p==0)continue;
//				int v=(c*inv(a+b))%p;
//				int _v=inv(v);
//				v=((v+_v*_v)%p+p)%p;
//				S[v]++;
//			}
//		}
//	}
	for(int i=1;i<=m;i++){
		int _t=-t[i]-1;
		_t=(_t%p+p)%p;
		ans=(ans+S[_t])%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}

