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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,s[N],t[N],tr[N],ans,k=1,tn[N],fac[N];

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void add(int x,int t){for(;x<N;ub(x))tr[x]+=t;return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}
inline int qp(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){if(!x)return 1;return qp(x,Mod-2);}

signed main(){
	n=read(),m=read();
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(fac[i-1]*i)%Mod;
	for(int i=1;i<=n;i++){
		s[i]=read();
		add(s[i],1);
		++tn[s[i]];
	}
	int div=1;
	for(int i=1;i<N;i++)if(tn[i]>1)div=(div*inv(fac[tn[i]]))%Mod;
	for(int i=1;i<=m;i++){
		t[i]=read();
		int s1=sum(t[i]-1);
		ans=(ans+k*s1%Mod*fac[n-1])%Mod;
		if(tn[t[i]]){
			k=(k*tn[t[i]])%Mod,--tn[t[i]],add(t[i],-1),--n;
			if(n==0&&i<m){
				ans+=k;
				break;
			}
		}
		else break;
	}
	ans=(ans*div)%Mod;
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

