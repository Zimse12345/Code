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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a,b,c,d,e,f,ans;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		x=(x*x)%Mod,k/=2; 
	}
	return res;
}

int inv(int x){return qp(x,Mod-2);}

signed main(){
	n=read();
	if(n==1){
		a=read(),b=read();
		for(int i=a;i<b;i++)ans+=abs(i)+(i<0?-inv(2):inv(2));
		ans=(ans%Mod*inv(b-a));
	}
	if(n==2){
		a=read(),b=read(),c=read(),d=read();
		for(int i=a+c+1;i<b+d;i++){
			int L=max(i-d,a),R=min(i-1-c,b-1);
			if(L<=R)ans+=(R-L+1)*abs(i)%Mod;
		}
		ans=(ans%Mod*inv((b-a)%Mod*(d-c)%Mod));
	}
	ans=(ans%Mod+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

