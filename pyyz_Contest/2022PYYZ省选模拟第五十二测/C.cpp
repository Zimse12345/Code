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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,k,f[N],C[N],V[N],tag=1,t[N];

signed main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		C[i]=read(),V[i]=read();
		if(C[i]!=V[i])tag=0;
	}
	if(tag){
		f[0]=1;
		for(int i=1;i<=n;i++)++t[C[i]];
		for(int i=1;i<=n;i++)if(t[i]){
			for(int j=1;j<=t[i];j*=2){
				for(int x=k;x>=i*j;x--)f[x]|=f[x-i*j];
				t[i]-=j;
			}
			if(t[i])for(int x=k;x>=i*t[i];x--)f[x]|=f[x-i*t[i]];
		}
		for(int i=k;i>=0;i--)if(f[i]){
			printf("%lld\n",i);
			break;
		}
		return 0;
	} 
	for(int i=1;i<=n;i++){
		int c=C[i],v=V[i];
		for(int i=k;i>=c;i--)f[i]=max(f[i],f[i-c]+v); 
	}
	for(int i=1;i<=k;i++)printf("%lld ",f[i]);
	printf("\n");
	return 0;
}

