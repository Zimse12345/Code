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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],p[N],fa[N];
int F(int x){if(fa[x]^x)fa[x]=F(fa[x]);return fa[x];}

bool ck(){
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=0;i<=30;i++){
		for(int j=1,pre=0;j<=n;j++)if(a[j]&(1<<i)){
			if(pre){
				int A=F(pre),B=F(j);
				if(A^B)fa[B]=A;
			}
			pre=j;
		}
	}
	for(int i=2;i<=n;i++)if(F(i)^F(i-1))return false;
	return true;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		int ans=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(!a[i])++a[i],++ans;
		}
		if(!ck()){
			int tag=0;
			for(int i=1;i<=n;i++){
				--a[i];
				if(ck()){tag=1;break;}
				++a[i];
				++a[i];
				if(ck()){tag=1;break;}
				--a[i];
			}
			if(tag)++ans;
			if(!tag){
				int mx=0;
				for(int i=1;i<=n;i++){
					int v=a[i];
					p[i]=0;
					while(!(v&1))v/=2,++p[i];
					mx=max(mx,p[i]);
				}
				ans+=2;
				int tag=0;
				for(int i=1;i<=n;i++)if(p[i]==mx){
					if(tag==0)tag=1,--a[i];
					else if(tag==1)tag=2,++a[i];
				}
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}

