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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,ans,f[N],g[N];

struct p{
	int a,b;
	p(int a=0,int b=0):a(a),b(b){}
	bool operator < (const p& A)const{return a<A.a;}
}s[N];

int aa[N],bb[N];

int main(){
	n=read();
	for(int i=1;i<=n;i++)aa[i]=read();
	for(int i=1;i<=n;i++)bb[i]=read();
	for(int i=1;i<=n;i++)s[i]=p(aa[i],bb[i]);
	sort(s+1,s+n+1);
	f[0]=1;
	for(int i=1;i<=n;i++){
		int a=s[i].a,b=s[i].b;
		for(int j=0;j<b;j++)g[j]=0;
		for(int j=b;j<N;j++)g[j]=f[j-b];
		for(int j=0;j<=a;j++)ans=(ans+g[j])%Mod;
		for(int j=0;j<N;j++)f[j]=(f[j]+g[j])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}

