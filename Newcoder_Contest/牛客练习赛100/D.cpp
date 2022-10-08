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

const int N=1e6+7,M=50000,INF=1e9+7;
int x,a[N],t,cnt[N],b[N],_t;

signed main(){
	x=read();
	if(!x){
		printf("qwq\n");
		return 0;
	}
	for(int i=1;i<=min(M,x);i++)a[++t]=1;
	int A=t;
	for(int i=1;i*A<=x&&i<=M;i++)a[++t]=2;
	int B=t-A;
	for(int i=B;i>=1;i--){
		while(i*A<=x){
			x-=i*A,++cnt[A+i];
			if(i==B)break;
		}
	}
	for(int i=1;i<=t;i++){
		b[++_t]=a[i];
		while(cnt[i]--)b[++_t]=3;
	}
	for(int i=1;i<=_t-2;i++){
		if(b[i]==1)putchar('r');
		if(b[i]==2)putchar('e');
		if(b[i]==3)putchar('d');
	}
	while(x--)putchar('r');
	putchar('e');
	putchar('d');
	putchar('\n');
	return 0;
}

