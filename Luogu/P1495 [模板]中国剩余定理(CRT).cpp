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

int qp(int x,int k,int P){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%P;
		k>>=1ll,x=(x*x)%P;
	}
	return res;
}

int inv(int x,int P){
	return qp(x,P-2ll,P);
}

void exgcd(int A,int B,int &x,int &y){
	if(B==0){x=1,y=0;return;}
	exgcd(B,A%B,x,y);
	int z=x;x=y,y=z-y*(A/B);
	return;
}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],c[N],d[N],p=1,ans;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read(),p*=a[i];
	for(int i=1;i<=n;i++){
		c[i]=p/a[i];
		int x,y;
		exgcd(c[i],a[i],x,y),d[i]=x;
		ans=(ans+b[i]*c[i]%p*d[i]%p)%p;
	}
	printf("%lld",(ans%p+p)%p);
	return 0;
}
