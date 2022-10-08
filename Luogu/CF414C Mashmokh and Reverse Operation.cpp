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

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}

const int N=2e6+7,Mod=998244353,INF=2e9+7;
int n,m,a[N],b[N],r[N],rr[N];

void sol(int L,int R,int x){
	if(!x)return;
	int M=(L+R)>>1ll;
	sol(L,M,x-1),sol(M+1,R,x-1);
	int p1=M+1,p2=L,c=0;
	for(int i=L;i<=M;i++){
		while(p1<=R&&a[p1]<a[i])++c,++p1;
		r[x]+=c;
	}
	c=0;
	for(int i=M+1;i<=R;i++){
		while(p2<=M&&a[p2]<a[i])++c,++p2;
		rr[x]+=c;
	}
	p1=L,p2=M+1,c=-1;
	while(p1<=M||p2<=R){
		++c;
		if(p1>M)b[L+c]=a[p2++];
		else if(p2>R)b[L+c]=a[p1++];
		else if(a[p1]<a[p2])b[L+c]=a[p1++];
		else b[L+c]=a[p2++];
	}
	for(int i=L;i<=R;i++)a[i]=b[i];
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=(1<<n);i++)a[i]=read();
	sol(1,1ll<<n,n);
	m=read();
	
	for(int i=1,x,ans;i<=m;i++){
		x=read(),ans=0;
		for(int j=1;j<=x;j++)swap(r[j],rr[j]);
		for(int j=1;j<=n;j++)ans+=r[j];
		printf("%lld\n",ans);
	}
	return 0;
}

