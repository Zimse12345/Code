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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],tag;

int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	T=read();
	while(T--){
		n=read(),m=INF,tag=1;
		for(int i=1;i<=n;i++)a[i]=read(),m=min(m,a[i]);
		for(int i=1;i<=n;i++){
			a[i]-=m;
			if(a[i]>0)tag=0;
		}
		if(tag){
			printf("-1\n");
			continue;
		}
		int ans=a[1];
		for(int i=2;i<=n;i++)ans=gcd(ans,a[i]);
		printf("%d\n",ans);
	}
	return 0;
}
