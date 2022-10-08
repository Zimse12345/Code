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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m,x[N],y[N],t[N],f[N],ans;

int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		t[i]=read(),x[i]=read(),y[i]=read();
		for(int j=1;j<i;j++){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])f[i]=max(f[i],f[j]);
		}
		++f[i],ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}

