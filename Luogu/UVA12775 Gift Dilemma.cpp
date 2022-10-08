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
int T,A,B,C,P,g,ans;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline void exgcd(int a,int b,int& x,int& y){
	if(b)exgcd(b,a%b,y,x),y-=a/b*x;
	else x=1,y=0;return;
}

signed main(){
	T=read();
	for(int i=1;i<=T;i++){
		int X,Y,t;
		A=read(),B=read(),C=read(),P=read(),ans=0;
		g=gcd(A,B),exgcd(A,B,X,Y);
		for(int z=0;z*C<=P;z++){
			int s=P-z*C;
			if(s%g)continue;
			int x=X*s/g,y=Y*s/g;
			if(x<0){
				t=(-x)/(B/g);
				if((-x)%(B/g))++t;
			}
			else t=-(x/(B/g));
			x+=t*(B/g),y-=t*(A/g);
			if(y>=0)ans+=y/(A/g)+1;
		}
		printf("Case %lld: %lld\n",i,ans);
	}
	return 0;
}

