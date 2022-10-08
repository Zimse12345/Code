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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e2+7,Mod=998244353,INF=1e9+7;
char s[N][N];
int h,w,sx,sy,tx,ty;

signed main(){
	h=read(),w=read();
	for(int i=1;i<=h;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=w;j++)if(s[i][j]=='o'){
			if(!sx)sx=i,sy=j;
			else tx=i,ty=j;
		}
	}
	printf("%d\n",signed(abs(sx-tx)+abs(sy-ty)));
	return 0;
}

