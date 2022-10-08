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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,a[N];

signed main(){
	T=read();
	while(T--){
		a[1]=read(),a[2]=read(),a[3]=read();
		sort(a+1,a+4);
		if((a[1]==a[2]&&a[3]%2==0)||(a[2]==a[3]&&a[1]%2==0)||(a[1]==a[3]&&a[2]%2==0)||a[1]+a[2]==a[3]){
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	}
	return 0;
}

