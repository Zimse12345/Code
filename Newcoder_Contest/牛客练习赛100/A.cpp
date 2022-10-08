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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int a,b,x;

signed main(){
	a=read(),b=read(),x=read();
	for(int i=0;a*i<=x;i++){
		if((x-a*i)%b==0){
			printf("%d %d\n",i,(x-a*i)/b);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}

