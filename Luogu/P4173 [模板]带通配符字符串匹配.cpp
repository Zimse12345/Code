/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

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

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define pb push_back
#define ll long long
#define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)
// #define Lid ch[id][0]
// #define Rid ch[id][1]

namespace Zimse{
const int INF=1000114514;
const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline ll fpow(ll x,ll y){ll res=1;while(y){if(y&1)res=res*x%Mod;x=x*x%Mod,y/=2;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;using namespace std;

const int N=4194304;
const int G=3,iG=332748118;

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
inline void resize(unsigned x){f.resize(x);return;}
inline int size(){return f.size();}
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
				x=f[j+k],y=f[j+k+i]*_pow[i+k]%Mod;
				f[j+k]=mod(x+y);
				f[j+k+i]=_mod(x-y);
			}
		}
	}
	reverse(f.begin()+1,f.end());
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

poly mul(poly A,poly B){
	int n=A.f.size(),m=B.f.size();
	m+=n-1;
	for(n=1;n<m;n*=2);
	A.resize(n),B.resize(n);
	A.dft(),B.dft();
	for(int i=0;i<n;i++)A.f[i]=(A.f[i]*B.f[i])%Mod;
	A.idft();
	A.resize(m);
	return A;
}

int m,n;
char str1[N],str2[N];
vector<int> Ans;

signed main(){
    init();
    m=read(),n=read();
    scanf("%s %s",str1,str2);
    poly a,b,a2,b2,a3,b3;
    int sz=1;
    while(sz<n+m)sz*=2;
    a.resize(sz),b.resize(sz);
    a2.resize(sz),b2.resize(sz);
    a3.resize(sz),b3.resize(sz);
    for(int i=0;i<m;i++){
        if(str1[m-i-1]!='*'){
            a.f[i]=str1[m-i-1]-'a'+1;
            a2.f[i]=a.f[i]*a.f[i];
            a3.f[i]=a2.f[i]*a.f[i];
        }
    }
    for(int i=0;i<n;i++){
        if(str2[i]!='*'){
            b.f[i]=str2[i]-'a'+1;
            b2.f[i]=b.f[i]*b.f[i];
            b3.f[i]=b2.f[i]*b.f[i];
        }
    }
    a.dft(),a2.dft(),a3.dft(),b.dft(),b2.dft(),b3.dft();
    poly ans;
    ans.resize(sz);
    for(int i=0;i<sz;i++)ans.f[i]=_mod((a3.f[i]*b.f[i]+a.f[i]*b3.f[i]-2*a2.f[i]*b2.f[i])%Mod);
    ans.idft();
    for(int i=m-1;i<n;i++)if(ans.f[i]==0)Ans.pb(i-m+2);
    printf("%u\n",Ans.size());
    for(unsigned i=0;i<Ans.size();i++)write_(Ans[i]);
    pc(10);
    return 0;
}
