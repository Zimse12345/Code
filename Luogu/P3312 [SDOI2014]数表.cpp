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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=2147483648,INF=1e9+7;
int T,ans[N],prime[N],t,pr[N],e[N],mu[N],sigma[N];
struct query{int n,m,a,id;query(int n=0,int m=0,int a=0,int id=0):n(n),m(m),a(a),id(id){}
bool operator < (const query& A)const{return a<A.a;}}q[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){};
bool operator < (const node& A)const{return y<A.y;}}sgm[N];

int tr[N];
inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int t){for(;x<N;ub(x))tr[x]=(tr[x]+t)%Mod;return;}
inline int sum(int x){int res=0;for(;x;db(x))res=(res+tr[x])%Mod;return res;}

signed main(){
	T=read();
	for(int i=1,n,m,a;i<=T;i++)n=read(),m=read(),a=read(),q[i]=query(n,m,a,i);
	sort(q+1,q+T+1);
	mu[1]=sigma[1]=1;
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++t]=i,mu[i]=-1,e[i]=1,sigma[i]=i+1;
		for(int j=1,x;j<=t&&prime[j]*i<N;j++){
			x=prime[j]*i;
			pr[x]=prime[j],mu[x]=-mu[i],e[x]=sigma[i],sigma[x]=sigma[i]*(prime[j]+1);
			if(pr[i]==prime[j]){mu[x]=0,e[x]=e[i],sigma[x]=sigma[i]*prime[j]+e[i];break;}
		}
	}
	for(int i=1;i<N;i++)sgm[i]=node(i,sigma[i]);
	sort(sgm+1,sgm+N);
	for(int i=1,j=1,n,m,a,s;i<=T;i++){
		n=q[i].n,m=q[i].m,a=q[i].a,s=0;
		while(j<N&&sgm[j].y<=a){
			for(int k=1;k*sgm[j].x<N;k++)add(k*sgm[j].x,sgm[j].y*mu[k]%Mod);
			++j;
		}
		for(int l=1,r;l<=min(n,m);){
			r=min(n/(n/l),m/(m/l));
			s+=(n/l)*(m/l)%Mod*(sum(r)-sum(l-1))%Mod;
			l=r+1;
		}
		ans[q[i].id]=(s+Mod)%Mod;
	}
	for(int i=1;i<=T;i++)printf("%lld\n",ans[i]);
	return 0;
}

