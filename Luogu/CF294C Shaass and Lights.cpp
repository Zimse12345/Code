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

const int N=1e5+7,Mod=1000000007,INF=1e9+7;
int n,m,a[N],b[N],ans=1;

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

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)a[i]=read();
	sort(a+1,a+m+1);
	a[m+1]=n+1;
	for(int i=0;i<=m;i++){
		int c=a[i+1]-a[i]-1;
		if(i!=0&&i!=m&&c)ans=(ans*qp(2,c-1))%Mod;
		for(int j=1;j<=c;j++)ans=(ans*inv(j))%Mod;
	}
	for(int i=1;i<=n-m;i++)ans=(ans*i)%Mod;
	printf("%lld\n",ans);
	return 0;
}
