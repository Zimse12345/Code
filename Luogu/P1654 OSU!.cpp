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
#define Lid Ch[id][0]
#define Rid Ch[id][1]
#define lid ch[id][0]
#define rid ch[id][1]

using namespace std;

inline int read(){ll qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n;
double p[N],x1[N],x2[N],x3[N];

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%lf",&p[i]);
		x1[i]=(x1[i-1]+1)*p[i];
		x2[i]=(x2[i-1]+2*x1[i-1]+1)*p[i];
		x3[i]=x3[i-1]+(3*(x1[i-1]+x2[i-1])+1)*p[i];
	}
	printf("%.1lf\n",x3[n]);
	return 0;
}
