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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,v,a[N],b[N],ans;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2ll;
	}
	return res;
}

int inv(int x){
	return qp(x,Mod-2);
}

signed main(){
	n=read(),v=read();
	for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for(int i=1;i<=n;i++){
		int s1=b[i]%Mod,s2=1ll;
		for(int j=1;j<=n;j++)if(i!=j){
			s1=(s1*(v-a[j]))%Mod;
			s2=(s2*(a[i]-a[j]))%Mod;
		}
		ans=(ans+s1*inv(s2))%Mod;
	}
	ans=(ans+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}
