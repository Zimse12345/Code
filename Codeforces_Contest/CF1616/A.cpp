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

const int N=2e2+7,Mod=998244353,INF=1e9+7;
int T,n,t[N],ans;

signed main(){
	T=read();
	while(T--){
		n=read(),ans=0;
		for(int i=1,x;i<=n;i++){
			x=abs(read());
			if(t[x+101]&&!t[x]&&x)t[x]=1,++ans;
			else if(!t[x+101])t[x+101]=1,++ans;
		}
		printf("%d\n",ans);
		for(int i=0;i<=202;i++)t[i]=0;
	}
	return 0;
}
