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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,d,a[N],c[N],ans;

void sol(int pos){
	//[1,pos-1][pos+1,n]
	int mi=a[pos+1]-a[pos-1]-1;
	for(int i=1;i<pos;i++)mi=min(mi,a[i]-a[i-1]-1);
	for(int i=pos+1;i<n;i++)mi=min(mi,a[i+1]-a[i]-1);
	int mx=(a[pos+1]-a[pos-1]-2)/2;
	for(int i=1;i<pos;i++)mx=max(mx,(a[i]-a[i-1]-2)/2);
	for(int i=pos+1;i<=n;i++)mx=max(mx,(a[i+1]-a[i]-2)/2);
	if(pos==n)mx=max(mx,d-a[n-1]-1);
	mx=max(mx,d-a[n]-1);
	ans=max(ans,min(mi,mx));
//	printf("sol(%d)= min(%d,%d)\n",pos,mi,mx);
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read(),d=read();
		int mi=INF,pos=0;
		a[n+1]=d;
		for(int i=1;i<=n;i++){
			a[i]=read();
			c[i]=a[i]-a[i-1]-1;
			if(c[i]<mi)mi=c[i],pos=i;
		}
		ans=mi;
		sol(pos);
		if(pos>1)sol(pos-1);
		printf("%d\n",ans);
	}
	return 0;
}

