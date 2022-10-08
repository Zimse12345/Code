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
#include <cctype>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){
		if(p==q){
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x){
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c){
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x){
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int a[N],OP[N];
ll m,qX[N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;}
}num[N];
unsigned b[20][N];
ll sum[N*8],ADD,v[N],Btag[N];
unsigned n,q,BlockSize,BlockCnt,BL[N],BR[N],qL[N],qR[N];

void build(unsigned L,unsigned R,unsigned d,unsigned id){
	for(unsigned i=L;i<=R;i++)sum[id]+=a[b[d][i]];
	if(L==R)return;
	unsigned M=(L+R)>>1,p1=L,p2=M+1;
	for(unsigned i=L;i<=R;i++){
		if(b[d][i]<=M)b[d+1][p1++]=b[d][i];
		else b[d+1][p2++]=b[d][i];
	}
	build(L,M,d+1,id<<1),build(M+1,R,d+1,(id<<1)|1);
	return;
}

ll query(unsigned L,unsigned R,unsigned id,unsigned d,unsigned l,unsigned r){
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R){
		unsigned _l=L,_r=R,p=L-1;
		while(_l<=_r){
			unsigned _m=(_l+_r)>>1;
			if(a[b[d][_m]]+ADD<m)p=_m,_l=_m+1;
			else _r=_m-1;
		}
		ll res=sum[id]-m*(R-p)+ADD*(R-L+1);
		return res;
	}
	else{
		unsigned M=(L+R)>>1;
		return query(L,M,id<<1,d+1,l,r)+query(M+1,R,(id<<1)|1,d+1,l,r);
	}
}

void sol4(){
	for(unsigned i=1;i<=n;i++)num[i]=node(a[i],i);
	sort(num+1,num+n+1);
	for(unsigned i=1;i<=n;i++)b[0][i]=num[i].y;
	build(1,n,0,1);
	for(unsigned i=1;i<=q;i++){
		if(OP[i]==1)ADD=(ADD+qX[i])%m;
		else{
			IO.write_int(query(1,n,1,0,qL[i],qR[i]));
			IO.write_char('\n');
		}
	}
	return;
}

signed main(){
//	freopen("sequence3.in","r",stdin);
//	freopen("d.out","w",stdout);
	int tag4=1;
	IO.read_int(n),IO.read_int(m),IO.read_int(q);
	for(unsigned i=1;i<=n;i++)IO.read_int(a[i]);
	for(unsigned i=1;i<=q;i++){
		IO.read_int(OP[i]),IO.read_int(qL[i]),IO.read_int(qR[i]);
		if(OP[i]==1){
			IO.read_int(qX[i]);
			if(qL[i]!=1u||qR[i]!=n)tag4=0;
		}
	}
	if(tag4){
		sol4();
		return 0;
	}
	BlockSize=max(2u,unsigned(sqrt(n/4)));
	BlockCnt=n/BlockSize;
	for(unsigned i=0;i<=BlockCnt;i++){
		BL[i]=max(1u,BlockSize*i),BR[i]=min(n,BlockSize*(i+1)-1);
		for(unsigned j=BL[i];j<=BR[i];j++)v[j]=a[j],sum[i]+=a[j];
		sort(v+BL[i],v+BR[i]+1);
	}
	for(unsigned i=1,l,r,x;i<=q;i++){
		l=qL[i],r=qR[i];
		if(OP[i]==1){
			x=qX[i];
			unsigned bl=l/BlockSize,br=r/BlockSize;
			for(unsigned j=bl+1;j<br;j++)Btag[j]=(Btag[j]+x)%m;
			if(bl==br){
				for(unsigned j=l;j<=r;j++)a[j]=(a[j]+x)%m;
				sum[bl]=0;
				for(unsigned j=BL[bl];j<=BR[bl];j++)v[j]=a[j],sum[bl]+=v[j];
				sort(v+BL[bl],v+BR[bl]+1);
			}
			else{
				for(unsigned j=l;j<=BR[bl];j++)a[j]=(a[j]+x)%m;
				sum[bl]=0;
				for(unsigned j=BL[bl];j<=BR[bl];j++)v[j]=a[j],sum[bl]+=v[j];
				sort(v+BL[bl],v+BR[bl]+1);
				for(unsigned j=BL[br];j<=r;j++)a[j]=(a[j]+x)%m;
				sum[br]=0;
				for(unsigned j=BL[br];j<=BR[br];j++)v[j]=a[j],sum[br]+=v[j];
				sort(v+BL[br],v+BR[br]+1);
			}
		}
		else{
			unsigned bl=l/BlockSize,br=r/BlockSize;
			ll ans=0;
			for(unsigned j=bl+1;j<br;j++){
				unsigned _l=BL[j],_r=BR[j],p=_l-1;
				while(_l<=_r){
					unsigned _m=(_l+_r)>>1;
					if(v[_m]+Btag[j]<m)p=_m,_l=_m+1;
					else _r=_m-1;
				}
				ans+=sum[j]-m*(BR[j]-p)+Btag[j]*(BR[j]-BL[j]+1);
			}
			if(bl==br){
				for(unsigned j=l;j<=r;j++)ans+=(a[j]+Btag[bl])%m;
			}
			else{
				for(unsigned j=l;j<=BR[bl];j++)ans+=(a[j]+Btag[bl])%m;
				for(unsigned j=BL[br];j<=r;j++)ans+=(a[j]+Btag[br])%m;
			}
			IO.write_int(ans);
			IO.write_char('\n');
		}
	}
	return 0;
}

