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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const unsigned N=262144;
const int Mod=998244353,G=3,iG=332748118;
inline int fpow(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return fpow(x,Mod-2);}
inline int mod(int x){return x>=Mod?x-Mod:x;}
inline int _mod(int x){return x<0?x+Mod:x;}

int _pow[N];

inline void init(){
	int p=fpow(G,(Mod-1)/N);
	_pow[N/2]=1;
	for(int i=N/2+1;i<N;i++)_pow[i]=_pow[i-1]*p%Mod;
	for(unsigned i=N/2-1;i<N;i--)_pow[i]=_pow[i*2]; 
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

void print(){
	for(unsigned i=0;i<f.size();i++)printf("%lld ",f[i]);
	printf("\n");
	return;
}
};

poly PolyMul(poly A,poly B){
	unsigned n=A.f.size(),m=B.f.size();
	m+=n-1;
	for(n=1;n<m;n*=2);
	A.resize(n),B.resize(n);
	A.dft(),B.dft();
	for(unsigned i=0;i<n;i++)A.f[i]=(A.f[i]*B.f[i])%Mod;
	A.idft();
	A.resize(m);
	return A;
}

poly PolyInv(poly F){
	poly G,_F;
	unsigned n=F.size(),m=1;
	G.resize(1),G.f[0]=inv(F.f[0]);
	while(m<n*2)m*=2;
	F.resize(m),m=1;
	while(m<n*2){
		m*=2,_F.resize(m),G.resize(m);
		for(unsigned i=0;i<m/2;i++)_F.f[i]=F.f[i];
		_F.dft(),G.dft();
		for(unsigned i=0;i<m;i++)G.f[i]=(2ll-_F.f[i]*G.f[i]%Mod+Mod)*G.f[i]%Mod;
		G.idft(),G.resize(m/2);
	}
	G.resize(n);
	return G;
}

signed main(){
	init();
	unsigned n=read();
	poly A;
	A.resize(n);
	for(unsigned i=0;i<n;i++)A.f[i]=read();
	PolyInv(A).print();
	return 0;
}
