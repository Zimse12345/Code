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

const int N=2100,Mod=998244353,INF=1e9+7;
int n,m,sum[N][N][4];
char op[10];
inline int lowbit(int x){return x&(-x);}

void add(int x,int y,int w,int t){
	for(int i=x;i<=n;i+=lowbit(i)){
		for(int j=y;j<=m;j+=lowbit(j))sum[i][j][t]+=w;
	}
	return;
}

int sm(int x,int y,int t){
	int res=0;
	for(int i=x;i;i-=lowbit(i)){
		for(int j=y;j;j-=lowbit(j))res+=sum[i][j][t];
	}
	return res;
}

void update(int x,int y,int w){
	add(x,y,w,0),add(x,y,w*x,1),add(x,y,w*y,2),add(x,y,w*x*y,3);
}

int query(int x,int y){
	return sm(x,y,0)*(x*y+x+y+1)-sm(x,y,1)*(y+1)-sm(x,y,2)*(x+1)+sm(x,y,3);
}

int main(){
	n=read(),m=read();
	while(scanf("%s",op)==1){
		int a1=read(),b1=read(),a2=read(),b2=read();
		if(op[0]=='L'){
			int w=read();
			update(a1,b1,w),update(a1,b2+1,-w),update(a2+1,b1,-w),update(a2+1,b2+1,w);
		}
		else write(query(a2,b2)-query(a1-1,b2)-query(a2,b1-1)+query(a1-1,b1-1)),putchar(10);
	}
	return 0;
}

