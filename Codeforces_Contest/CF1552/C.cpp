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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,k,a[N],b[N],t[N],id[N],ans,tot;

signed main(){
	T=read();
	while(T--){
		n=read()*2,k=read(),ans=0,tot=0;
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=1;i<=k;i++){
			a[i]=read(),b[i]=read();
			if(b[i]<a[i])swap(a[i],b[i]);
			t[a[i]]=t[b[i]]=1;
		}
		for(int i=1;i<=n;i++)if(!t[i])id[i]=++tot;
		for(int i=1;i<=n;i++)if(!t[i])for(int j=i+1;j<=n;j++)if(!t[j])if(id[i]+tot/2==id[j])a[++k]=i,b[k]=j;
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				if((a[i]<a[j]&&b[i]>a[j]&&b[i]<b[j])||(a[i]>a[j]&&a[i]<b[j]&&b[i]>b[j]))++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

