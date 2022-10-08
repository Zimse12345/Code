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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,f[N*N],g[N*N],c[N*N],R;
struct s{
	int a,b;
	s(int a=0,int b=0):a(a),b(b){}
	bool operator <(const s& A)const{return a>A.a;}
}p[N];

int main(){
	n=read();
	for(int i=1,a,b;i<=n;i++){
		a=read(),b=read();
		p[i]=s(a,b);
	}
	sort(p+1,p+n+1);
	
	R=1,c[1]=1;
	for(int i=1;i<=n;i++){
		int a=p[i].a,b=p[i].b;
		for(int i=0;i<=R;i++)g[i]=f[i];
		for(int i=0;i<=R+abs(a);i++)f[i]=-INF;
		for(int i=0;i<=R;i++)f[i]=g[i];
		
		for(int i=1;i<=R;i++)f[i-1+a]=max(f[i-1+a],g[i]+b);
		if(a>1)R+=a-1;
	}
	int ans=0;
	for(int i=0;i<=R;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
