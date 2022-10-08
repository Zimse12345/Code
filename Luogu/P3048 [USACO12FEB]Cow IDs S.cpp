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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e7+7,Mod=1e9+7,INF=1e9+7;
int n,K,fac[N],_fac[N],ans[N];

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

int C(int x,int y){
	if(x==y)return 1;
	if(y>x)return 0;
	ll res=1;
	for(int i=x;i>=x-y+1;i--)res*=i;
	for(int i=1;i<=y;i++)res/=i;
	return res;
}

signed main(){
	n=read(),K=read();
	n+=100;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(fac[i-1]*i)%Mod;
	_fac[n]=inv(fac[n]);
	for(int i=n-1;i>=0;i--)_fac[i]=(_fac[i+1]*(i+1))%Mod;
	n-=100;
	int len=K;
	while(1){
		int c=C(len-1,K-1);
		if(c>=n)break;
		else n-=c,++len;
	}
	ans[1]=1;
	for(int i=2,j=1;i<=len;i++){
		int c=C(len-i,K-j);
		if(c>=n)continue;
		ans[i]=1,n-=c,++j;
	}
	for(int i=1;i<=len;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}

