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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,k,a[N];

bool ck(int x,int y){
	if(y==1)return false;
	int c1=0,c2=0;
	for(int i=1;i<=k;i++){
		if(a[i]/x>1){
			c1+=2;
			c2+=a[i]/x-2;
		}
	}
	while(c1&&y>1)y-=2,c1-=2;
	if(c2>=y)return true;
	return false;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=k;i++)a[i]=read();
		if(ck(n,m)||ck(m,n))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

