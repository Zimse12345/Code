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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,a[N],p[N]; 

void ins(int x){
	for(int i=60;i>=0;i--){
		if(x&(1ll<<i)){
			if(!p[i]){p[i]=x;break;}
			else x^=p[i];
		}
	}
	return;
}

int qmax(){
	int res=0;
	for(int i=60;i>=0;i--)if((res^p[i])>res)res^=p[i];
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ins(a[i]);
	}
	printf("%lld\n",qmax());
	return 0;
}

