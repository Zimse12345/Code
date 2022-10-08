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

using namespace std;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

inline node modread(int P){node res=node(0,0);char c=getchar();while(c<'0'||c>'9')c=getchar();
while(c>='0'&&c<='9')res.x=(res.x*10+c-48-P)%P+P,res.y=(res.y*10+c-48)%(P-1),c=getchar();return res;}

const unsigned N=524288;
const int Mod=998244353,inv2=499122177;
inline int fpow(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return fpow(x,Mod-2);}
inline int mod(int x){return x>=Mod?x-Mod:x;}
inline int _mod(int x){return x<0?x+Mod:x;}

int _pow[N],Inv[N],sav[N];

inline void init(){
	int p=fpow(3,(Mod-1)/N);
	_pow[N/2]=1;
	for(int i=N/2+1;i<N;i++)_pow[i]=_pow[i-1]*p%Mod;
	for(unsigned i=N/2-1;i<N;i--)_pow[i]=_pow[i*2];
	Inv[1]=1;
	for(int i=2;i<N;i++)Inv[i]=Inv[i-1]*i%Mod;
	sav[N-1]=inv(Inv[N-1]);
	for(int i=N-2;i>=1;i--)sav[i]=sav[i+1]*(i+1)%Mod;
	for(int i=N-1;i>=2;i--)Inv[i]=sav[i]*Inv[i-1]%Mod;
	return;
}

struct poly{
vector<int> f;

inline void resize(unsigned x){
	f.resize(x);
	return;
}

inline int size(){
	return f.size();
}

void dft(){
	int x=0,y=0;
	unsigned sz=f.size();
	for(unsigned i=sz/2;i;i/=2){
		for(unsigned j=0;j<sz;j+=i*2){
			for(unsigned k=0;k<i;k++){
				x=f[j+k],y=f[j+k+i];
				f[j+k]=mod(x+y);
				f[j+k+i]=_pow[i+k]*_mod(x-y)%Mod;
			}
		}
	}
	return;
}

void idft(){
	int x=0,y=0;
	unsigned sz=f.size();
	for(unsigned i=1;i<sz;i*=2){
		for(unsigned j=0;j<sz;j+=i*2){
			for(unsigned k=0;k<i;k++){
				x=f[j+k],y=f[j+k+i]*_pow[i+k];
				if(y)y%=Mod;
				f[j+k]=mod(x+y);
				f[j+k+i]=_mod(x-y);
			}
		}
	}
	
	reverse(f.begin()+1, f.end());
	int invn=inv(sz);
	for(unsigned i=0;i<sz;i++)f[i]=f[i]*invn%Mod;
	return;
}

inline void Input(unsigned sz){
	f.resize(sz);
	for(unsigned i=0;i<sz;i++)f[i]=read();
	return;
}

inline void Print(){
	for(unsigned i=0;i<f.size();i++)printf("%lld ",f[i]);
	printf("\n");
	return;
}

poly operator * (poly F){
	for(unsigned i=0;i<F.size();i++){
		F.f[i]=F.f[i]*f[i]%Mod;
	}
	return F;
}

poly operator + (poly F){
	for(unsigned i=0;i<F.size();i++){
		F.f[i]+=f[i];
		if(F.f[i]>=Mod)F.f[i]-=Mod;
	}
	return F;
}

poly operator * (int x){
	poly F;
	F.resize(f.size());
	for(unsigned i=0;i<f.size();i++){
		F.f[i]=(f[i]*x)%Mod;
	}
	return F;
}
};

poly PolyMul(poly F,poly G){
	unsigned n=F.size(),m=G.size();
	m+=n-1;
	for(n=1;n<m;n*=2);
	F.resize(n),G.resize(n);
	F.dft(),G.dft();
	for(unsigned i=0;i<n;i++)F.f[i]=(F.f[i]*G.f[i])%Mod;
	F.idft();
	F.resize(m);
	return F;
}

poly PolyInv(poly F){
	poly G,_F;
	unsigned n=F.size(),m=1;
	G.resize(1),G.f[0]=inv(F.f[0]);
	while(m<n*2)m*=2;
	F.resize(m),m=1;
	while(m<n){
		m*=2,_F.resize(m*2),G.resize(m*2);
		for(unsigned i=0;i<m;i++)_F.f[i]=F.f[i];
		_F.dft(),G.dft();
		for(unsigned i=0;i<m*2;i++)G.f[i]=(2ll-_F.f[i]*G.f[i]%Mod+Mod)*G.f[i]%Mod;
		G.idft(),G.resize(m);
	}
	G.resize(n);
	return G;
}

poly Derivation(poly F){
	unsigned n=F.size();
	for(unsigned i=0;i<n-1;i++)F.f[i]=F.f[i+1]*(i+1)%Mod;
	F.f[n-1]=0;
	return F;
}

poly Integral(poly F){
	unsigned n=F.size();
	for(unsigned i=n-1;i>0;i--)F.f[i]=F.f[i-1]*Inv[i]%Mod;
	F.f[0]=0;
	return F;
}

poly PolyLn(poly F){
	unsigned n=F.size();
	poly G=Integral(PolyMul(Derivation(F),PolyInv(F)));
	G.resize(n);
	return G;
}

poly PolySqrt(poly F){
	poly G,_F;
	unsigned n=F.size(),m=1;
	G.resize(1),G.f[0]=1;
	while(m<n*2)m*=2;
	F.resize(m),m=1;
	while(m<n){
		m*=2,_F.resize(m*2),G.resize(m);
		for(unsigned i=0;i<m;i++)_F.f[i]=F.f[i];
		poly ig=PolyInv(G);
		G.resize(m*2),ig.resize(m*2);
		_F.dft(),G.dft(),ig.dft();
		G=(_F*ig+G)*inv2;
		G.idft(),G.resize(m);
	}
	G.resize(n);
	return G;
}

poly PolyExp(poly F){
	poly G,_F;
	unsigned n=F.size(),m=1;
	G.resize(1),G.f[0]=1;
	while(m<n*2)m*=2;
	F.resize(m),m=1;
	while(m<n){
		m*=2,_F.resize(m*2),G.resize(m);
		for(unsigned i=0;i<m;i++)_F.f[i]=F.f[i];
		poly lnG=PolyLn(G);
		G.resize(m*2),lnG.resize(m*2);
		G.dft(),lnG.dft(),_F.dft();
		for(unsigned i=0;i<m*2;i++)G.f[i]=G.f[i]*(2*Mod+1-lnG.f[i]+_F.f[i])%Mod;
		G.idft(),G.resize(m);
	}
	G.resize(n);
	return G;
}

poly PolyPow(poly F,node k){
	unsigned n=F.size(),pre0=0;
	while(pre0<n&&F.f[pre0]==0)++pre0;
	for(unsigned i=0;i<n-pre0;i++)F.f[i]=F.f[i+pre0];
	for(unsigned i=n-pre0;i<n;i++)F.f[i]=0;
	int f0=F.f[0],invf0=inv(f0);
	for(unsigned i=0;i<n;i++)F.f[i]=F.f[i]*invf0%Mod;
	F=PolyExp(PolyLn(F)*k.x)*fpow(f0,k.y);
	k.x*=pre0;
	for(unsigned i=n-1;i>=k.x&&i<n;i--)F.f[i]=F.f[i-k.x];
	for(unsigned i=0;i<k.x&&i<n;i++)F.f[i]=0;
	return F;
}

signed main(){
	init();
	unsigned n=read(),m=read();
	poly G;
	G.resize(m+1);
	for(unsigned i=0,x;i<n;i++){
		x=read();
		if(x<=m+1)G.f[x]=1;
	}
	G=G*(Mod-4);
	G.f[0]=(G.f[0]+1)%Mod;
	G=PolySqrt(G);
	G.f[0]=(G.f[0]+1)%Mod;
	G=PolyInv(G);
	G=G*2;
	for(unsigned i=1;i<=m;i++)printf("%lld\n",G.f[i]);
	return 0;
}

