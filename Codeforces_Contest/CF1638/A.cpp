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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		int p=0,q=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(a[i]!=i&&p==0)p=i;
		}
		if(!p)for(int i=1;i<=n;i++)printf("%d ",a[i]);
		else{
			for(int i=p;i<=n;i++)if(a[i]==p){q=i;break;}
			for(int i=p;i<=q;i++)b[i]=a[q-i+p];
			for(int i=p;i<=q;i++)a[i]=b[i];
			for(int i=1;i<=n;i++)printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}

