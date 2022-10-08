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

const int N=1e5+7,Mod=1e9+9,INF=1e9+7;
int n,a,b,ans;
char s;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

int f(int x,int l,int r){
	if(l==r)return qp(x,l);
	int m=(l+r)/2;
	if((r-l+1)%2==1){
		int s=f(x,l,m-1);
		return (s+qp(x,m)+s*qp(x,m-l+1)%Mod)%Mod;
	}
	else{
		int s=f(x,l,m);
		return (s+s*qp(x,m-l+1)%Mod)%Mod;
	}
}

signed main(){
	n=read(),a=read(),b=read();
	int k=read(),ia=inv(a),A=qp(a,n),B=1;
	int u=(ia*b)%Mod,v=qp(a,n);
	for(int i=0;i<k;i++){
		s=getchar();
		while(s!='+'&&s!='-')s=getchar();
		if(s=='+')ans=(ans+v)%Mod;
		else ans=(ans-v)%Mod;
		v=(u*v)%Mod;
	}
	A=inv(qp(a,k)),B=qp(b,k);
	v=(A*B)%Mod;
	int q=f(v,0,n/k);
	ans=(ans*q)%Mod;
	printf("%lld\n",(ans+Mod)%Mod);
	return 0;
}
