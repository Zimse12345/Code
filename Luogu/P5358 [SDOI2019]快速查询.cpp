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

const int N=1e6+7,Mod=1e7+19,INF=1e9+7;
int n,q,t,op[N],val[N],Id[N],V,ans,sum,po=1,ad;
map<int,int> mp;
inline int f(int x,int ct){return (po*x+ad*ct)%Mod;}

inline int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%Mod;
		k/=2,x=(x*x)%Mod;
	}
	return res;
}

inline int inv(int x){
	return qp(x,Mod-2);
}

void sol(int id){
	int ty=op[id],x=val[id];
	if(ty==1){
		int y=((x-ad)*inv(po))%Mod;
		if(mp.count(Id[id]))sum-=mp[Id[id]];
		else sum-=V;
		mp[Id[id]]=y;
		sum=(sum+y)%Mod;
	}
	if(ty==2)ad=(ad+x)%Mod;
	if(ty==3){
		po=(po*x)%Mod,ad=(ad*x)%Mod;
		if(po==0)mp.clear(),sum=V=0,po=1;
	}
	if(ty==4)mp.clear(),po=1,ad=0,sum=(x*n)%Mod,V=x;
	if(ty==5){
		if(mp.count(x))ans=(ans+f(mp[x],1))%Mod;
		else ans=(ans+f(V,1))%Mod;
	}
	if(ty==6)ans=(ans+f(sum,n))%Mod;
	return;
}

signed main(){
	n=read(),q=read();
	for(int i=1;i<=q;i++){
		op[i]=read();
		if(op[i]==1)Id[i]=read();
		if(op[i]!=6)val[i]=read();
	}
	t=read();
	for(int i=1,a,b;i<=t;i++){
		a=read(),b=read();
		for(int j=1;j<=q;j++)sol((a+j*b)%q+1);
	}
	ans=(ans%Mod+Mod)%Mod;
	printf("%lld\n",ans);
	return 0;
}

