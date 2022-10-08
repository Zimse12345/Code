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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,k,v[N];

int q(int x,int y,int ty){
	if(ty==1)printf("or %lld %lld\n",x,y);
	else printf("and %lld %lld\n",x,y);
	fflush(stdout);
	int res=read();
	return res;
}

signed main(){
	n=read(),k=read();
	int ab1=q(1,2,1),ac1=q(1,3,1),bc1=q(2,3,1);
	int ab2=q(1,2,2),ac2=q(1,3,2),bc2=q(2,3,2);
	int a=0,b=0,c=0;
	for(int i=0;i<=30;i++){
		int w=1ll<<i;
		int s1=(ab1&w)+(ac1&w)+(bc1&w);
		int s2=(ab2&w)+(ac2&w)+(bc2&w);
		if(s1==0ll)continue;
		if(s1==2ll*w){
			if((ab1&w)==0ll)c|=w;
			else if((ac1&w)==0ll)b|=w;
			else a|=w;
		}
		if(s2==w){
			if((ab2&w)==w)a|=w,b|=w;
			else if((ac2&w)==w)a|=w,c|=w;
			else b|=w,c|=w;
		}
		if(s2==w*3ll){
			a|=w,b|=w,c|=w;
		}
	}
	v[1]=a,v[2]=b,v[3]=c;
	for(int i=4;i<=n;i++){
		int l=q(1,i,1),r=q(1,i,2);
		v[i]=l-v[1]+r;
	}
	sort(v+1,v+n+1);
	printf("finish %lld\n",v[k]);
	fflush(stdout);
	return 0;
}
