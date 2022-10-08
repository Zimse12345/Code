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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,K=1000,Mod=1e9+7,INF=1e9;
int n,q,a[N],ans[N],t[N],pr[N],prime[N],tot,Inv[N],pre[N],fac[N],_fac[N];
int pre1[N],pre2[N];
int c[300000][100],iid[10000],to[N];
ll p=1ll;
int cnt;

struct query{
	int l,r,id;
	query(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
	bool operator < (const query& A)const{
		if(l/K==A.l/K){
			if((l/K)&1)return r>A.r;
			return r<A.r;
		}
		return l<A.l;
	}
}qu[N];

int qp(ll x,int K){
	ll res=1;
	while(K){
		if(K&1)res=(res*x)%Mod;
		x=(x*x)%Mod,K/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

void add(int x){
	++cnt;
	x=to[x];
	while(x>1){
		if(!t[pr[x]])p=(p*pre1[x])%Mod;
		++t[pr[x]],x/=pr[x];
	}
	return;
}

void rem(int x){
	++cnt;
	x=to[x];
	while(x>1){
		if(t[pr[x]]==1)p=(p*pre2[x])%Mod;
		--t[pr[x]],x/=pr[x];
	}
	return;
}

signed main(){
	for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	fac[0]=1;
	for(int i=1;i<N;i++)fac[i]=(1ll*fac[i-1]*i)%Mod;
	_fac[N-1]=inv(fac[N-1]),_fac[0]=1;
	for(int i=N-2;i>=1;i--)_fac[i]=(1ll*_fac[i+1]*(i+1))%Mod;
	for(int i=1;i<N;i++)Inv[i]=(1ll*fac[i-1]*_fac[i])%Mod;
	for(int i=2;i<N;i++)pre1[i]=1ll*(pr[i]-1)*Inv[pr[i]]%Mod,pre2[i]=1ll*(pr[i])*Inv[pr[i]-1]%Mod;
	for(int i=1;prime[i]<300;i++)iid[prime[i]]=i;
	
	n=read();
	pre[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=read(),pre[i]=(1ll*pre[i-1]*a[i])%Mod;
		for(int j=1;prime[j]<300;j++)c[i][j]=c[i-1][j];
		int x=a[i];
		while(x>1&&pr[x]<300)++c[i][iid[pr[x]]],x/=pr[x];
		to[a[i]]=x;
	}
	q=read();
	for(int i=1,l,r;i<=q;i++)l=read(),r=read(),qu[i]=query(l,r,i);
	sort(qu+1,qu+q+1);
	int L=1,R=0;
	for(int i=1,l,r;i<=q;i++){
		l=qu[i].l,r=qu[i].r;
		while(R<r)++R,add(a[R]);
		while(L>l)--L,add(a[L]);
		while(R>r)rem(a[R]),--R;
		while(L<l)rem(a[L]),++L;
		ans[qu[i].id]=p*pre[r]%Mod*inv(pre[l-1])%Mod;
		int z=1;
		for(int j=1;prime[j]<300;j++)if(c[r][j]-c[l-1][j]>0)z=(1ll*z*pre1[prime[j]])%Mod;
		ans[qu[i].id]=(1ll*ans[qu[i].id]*z)%Mod;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}
