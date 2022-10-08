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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}
 
int gcd(int x,int y){
	if(x==0&&y==0)return 0;
	if(x==0)return y;
	if(y==0)return x;
	return gcd(y,x%y);
}
 
const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],g[N*8],p;
 
int build(int L,int R,int o){
	if(L==R){
		g[o]=a[L];
		return g[o];
	}
	int M=(L+R)>>1;
	g[o]=gcd(build(L,M,o<<1),build(M+1,R,(o<<1)|1));
	return g[o];
}
 
int Gcd(int L,int R,int l,int r,int o){
	if(l<=L&&r>=R)return g[o];
	int M=(L+R)>>1;
	int A=0,B=0;
	if(l<=M)A=Gcd(L,M,l,r,o<<1);
	if(r>M)B=Gcd(M+1,R,l,r,(o<<1)|1);
	if(A==0)return B;
	if(B==0)return A;
	return gcd(A,B);
}
 
int check(int L,int R){
	int G=Gcd(1,n,L,R,1);
	if(G==1||G==-1)return 0;
	return 1;
}
 
signed main(){
	T=read();
	while(T--){
		n=read();
		
		for(int i=1;i<=n;i++)a[i]=read();
		if(n==1){
		    printf("1\n");
		    continue;
		}
		for(int i=1;i<n;i++)a[i]=a[i]-a[i+1];
		--n;
		
		build(1,n,1);
		int ans=0,L=1;
		for(int i=1;i<=n;i++){
			while(!check(L,i))++L;
			ans=max(ans,i-L+1);
		}
		printf("%lld\n",ans+1);
	}
	return 0;
}
