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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,a[N],d[N],ans;

bool ins(int x){
	for(int i=30;i>=0;i--)if(x&(1<<i)){
		if(!d[i]){
			d[i]=x;
			return true;
		}
		x^=d[i];
	}
	return false;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read()^a[i-1];
	if(a[n]==0)ans=-1;
	else for(int i=n;i>=1;i--)if(ins(a[i]))++ans;
	printf("%d\n",ans);
	return 0;
}

