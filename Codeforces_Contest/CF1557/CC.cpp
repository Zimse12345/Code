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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=1e9+7,INF=1e9+7;
int T,n,k,f[N],b[N],fac[N],_fac[N];
int f1,f2;

int qp(int x,int k){
	if(k==0)return 1;
	int s=qp(x,k/2);s=(s*s)%Mod;
	if(k&1ll)s=(s*x)%Mod;
	return s;
}

int inv(int x){
	return qp(x,Mod-2);
}

int C(int n,int m){
	return fac[n]*_fac[m]%Mod*_fac[n-m]%Mod;
}

int F(int x,int o){
	return x;
}

signed main(){
	T=read();
	b[0]=1,fac[0]=1;
	for(int i=1;i<N;i++)b[i]=(b[i-1]*2ll)%Mod,fac[i]=(fac[i-1]*i)%Mod;
	_fac[N-1]=inv(fac[N-1]);
	for(int i=N-2;i>=0;i--)_fac[i]=(_fac[i+1]*(i+1))%Mod;
	
	while(T--){
		n=read(),k=read();
		int A=0,B=0;
		for(int i=0;i<=n;i++){
//			printf("(%d %d)",i,C(n,i));
			if(i%2==0)A=(A+C(n,i))%Mod;
			else B=(B+C(n,i))%Mod;
		}
		if(k==0){
			printf("1\n");
			continue;
		}
		printf("[%d %d]",A,B);
		f1=0,f2=1;
		for(int i=1;i<=k;i++){
			int _f1=0,_f2=0;
			
			if(n%2==0)_f1=(f1+f2)%Mod;
			if(n%2==1)_f2=(f2*A)%Mod;
			if(n%2==0)_f2=(f2*(A-1))%Mod;
			
			f1=_f1,f2=_f2; 
		}
		printf("%lld,%lld\n",f1,f2);
	}
	return 0;
}

