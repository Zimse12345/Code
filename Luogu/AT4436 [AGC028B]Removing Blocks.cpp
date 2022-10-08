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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=1e9+7;
int n,a[N],H[N],ans;

inline int fpow(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=res*x%Mod;
		x=x*x%Mod,k/=2;
	}
	return res;
}

inline int inv(int x){
	return fpow(x,Mod-2);
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),H[i]=(H[i-1]+inv(i))%Mod;
	for(int i=1;i<=n;i++)ans=(ans+a[i]*(H[i]+H[n-i+1]-1+Mod))%Mod;
	for(int i=1;i<=n;i++)ans=ans*i%Mod;
	printf("%lld\n",ans);
	return 0;
}

