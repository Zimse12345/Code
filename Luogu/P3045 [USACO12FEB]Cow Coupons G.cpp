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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,k,m,ans;
struct cow{
	int p,c;
	cow(int p=0,int c=0):p(p),c(c){}
	bool operator < (const cow& A)const{return c<A.c;}
}a[N];
priority_queue<int> Q;

signed main(){
	n=read(),k=read(),m=read();
	for(int i=1,p,c;i<=n;i++)p=read(),c=read(),a[i]=cow(p,c);
	sort(a+1,a+n+1);
	int s=0;
	for(int i=1;i<=k;i++){
		if(s+a[i].c<=m)s+=a[i].c,Q.push(-a[i].p+a[i].c);
		else{
			printf("%lld\n",i-1);
			return 0;
		}
	}
	ans=k;
	for(int i=k+1,tag;i<=n;i++){
		tag=1;
		if(-Q.top()<a[i].p-a[i].c){
			if(s-Q.top()+a[i].c<=m)s=s-Q.top()+a[i].c,Q.pop(),Q.push(-a[i].p+a[i].c),++ans,tag=0;
		}
		else if(a[i].p+s<=m&&tag)s+=a[i].p,++ans;
	}
	printf("%lld\n",ans);
	return 0;
}
