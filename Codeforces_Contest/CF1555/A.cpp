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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n;

signed main(){
	T=read();
	while(T--){
		n=read();
		if(n%2)++n;
		if(n<=6){
			printf("15\n");
			continue;
		}
		if(n<=8){
			printf("20\n");
			continue;
		}
		if(n<=10){
			printf("25\n");
			continue;
		}
		int ans=(n/2)*5;
		printf("%lld\n",ans);
	}
	return 0;
}
