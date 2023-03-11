/************************
*FileName:
*Author: Zimse
*Data: 2023-02-
*Description:
************************/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define gc getchar
#define pc putchar
#define yes printf("Yes\n")
#define no printf("No\n")
#define pb push_back
#define ll long long
 #define int long long
// #define M ((L+R)/2)
// #define Lid (id<<1)
// #define Rid (Lid|1)

namespace Zimse{
//const int INF=1000114514;
//const int Mod=998244353;
// const int Mod=1000000007;
inline int read(){int x=0,y=1;char c=gc();while(c<48||57<c)
{if(c==45)y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _lcm(int x,int y){return x/_gcd(x,y)*y;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(x<y)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
}using namespace Zimse;using namespace std;

const unsigned N=524288;
const int Mod=998244353,inv2=499122177;
inline int fpow(int x,int k){int res=1;while(k){if(k&1ll)res=(res*x)%Mod;x=(x*x)%Mod,k/=2;}return res;}
inline int inv(int x){return fpow(x,Mod-2);}
inline int mod(int x){return x>=Mod?x-Mod:x;}
inline int _mod(int x){return x<0?x+Mod:x;}

int _pow[N],Inv[N],sav[N],mxsz;
int n,a[N],b[N],ans[2][N],T;

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
				x=f[j+k],y=f[j+k+i]*_pow[i+k];
				if(y)y%=Mod;
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

inline void Print(){
	int sz=f.size();
	while(sz&&!f[sz-1])--sz;
	for(int i=sz-1;i>=0;i--)pc('0'+f[i]);
	pc(10);
	return;
}
}pow2[200];

void Over(poly& F){
	F.resize(F.size()+10);
	_max(mxsz,F.size());
	for(int i=0;i<F.size();i++)F.f[i+1]+=F.f[i]/10,F.f[i]%=10;
	int m=F.size(),tag=0;
	while(m&&!F.f[m-1])--m;
	while(m!=(m&(-m)))m-=(m&(-m)),tag=1;
	if(tag)m*=2;
	F.resize(m);
	return;
}

poly PolyMul(poly F,poly G){
	int n=F.size(),m=G.size();
	m+=n-1;
	for(n=1;n<m;n*=2);
	F.resize(n),G.resize(n);
	F.dft(),G.dft();
	for(int i=0;i<n;i++)F.f[i]=(F.f[i]*G.f[i])%Mod;
	F.idft();
	Over(F);
	return F;
}

poly PolyAdd(poly F,poly& G){
	int sz=max(F.size(),G.size());
	F.resize(sz);
	for(int i=0;i<G.size();i++)F.f[i]+=G.f[i];
	Over(F);
	return F;
}

void dfs(int x,int pos,int t){
    if(!x)return;
    if(a[x]==pos)dfs(x-1,pos,t);
    else{
        int emp=1;
        if(a[x]==1||pos==1){
            ++emp;
            if(a[x]==2||pos==2)++emp;
        }
        dfs(x-1,emp,t);
        ans[t][x-1]++;
    }
    return;
}

void calc(int x,int pos,int t){
    for(int i=x;i>=1;i--){
        if(b[i]!=pos){
            ans[t][i-1]++;
            int p=1;
            if(b[i]==1||pos==1){
                ++p;
                if(b[i]==2||pos==2)++p;
            }
            pos=p;
        }
    }
    return;
}

poly solve(int L,int R){
	if(L==R){
		poly res;
		res.resize(1);
		res.f[0]=ans[T][L];
		return res;
	}
	int M=1,t=0;
	while(L+M*2-1<(L+R)/2)M*=2,++t;
	poly l=solve(L,L+M-1),r=PolyMul(solve(L+M,R),pow2[t]);
	return PolyAdd(l,r);
}

signed main(){
	// ifile("hanoi.in");
	// ofile("hanoi.out");
	init();
	
	pow2[0].resize(1);
	pow2[0].f[0]=2;
	int k=1,tt=0;
	while(k*2<300000)k*=2,++tt,pow2[tt]=PolyMul(pow2[tt-1],pow2[tt-1]);
	
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=read();
    while(n&&a[n]==b[n])--n;
    if(!n){
        _write(0);
        return 0;
    }
    int e1=1,e2=1;
    if(a[n]==1||b[n]==1){
        ++e1;
        if(a[n]==2||b[n]==2)++e1;
    }
    if(a[n]==1||e1==1){
        ++e2;
        if(a[n]==2||e1==2)++e2;
    }
    dfs(n-1,e1,0);
    ans[0][0]++;
    calc(n-1,e1,0);
    dfs(n-1,e2,1);
    ans[1][n-1]++,ans[1][0]++,e2=a[n];
    calc(n-1,e2,1);
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++)ans[i][j+1]+=ans[i][j]/2,ans[i][j]&=1;
    }
    for(int i=n+1;i>=0;i--){
        if(ans[0][i]<ans[1][i])break;
        if(ans[1][i]<ans[0][i]){T=1;break;}
    }
	solve(0,n+1).Print();
    return 0;
}
