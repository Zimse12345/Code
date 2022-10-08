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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,L,R,sx,sy,tx,ty,Len,so,q[N],vis[N][N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}};
int lt=0;
node line[N];
vector<node> ans;
inline void aa(int x,int y){vis[x][y]=1,ans.push_back(node(x,y));return;}

void Go(int& x,int& y){
	if(y<=L)while(y<=R)aa(x,y),++y;
	else while(y>=L)aa(x,y),vis[x][y]=1,--y;
	return;
}

bool print_ans(){
	printf("YES\n%llu\n",ans.size());
	for(unsigned i=0;i<ans.size();i++)printf("%d %d\n",ans[i].x,ans[i].y);
	return 0;
}


void Rto(int x_1,int y_1,int x_2,int y_2){
	while(y_1<=y_2)aa(x_1,y_1++);
	return;
}

void Lto(int x_1,int y_1,int x_2,int y_2){
	while(y_1>=y_2)aa(x_1,y_1--);
	return;
}

void Dto(int x_1,int y_1,int x_2,int y_2){
	while(x_1>=x_2)aa(x_1--,y_1);
	return;
}

void Uto(int x_1,int y_1,int x_2,int y_2){
	while(x_1<=x_2)aa(x_1++,y_1);
	return;
}
int a[N][N];
signed main(){
	freopen("d.out","r",stdin);
	freopen("6.out","w",stdout);
	for(int i=1;i<=40;i++){
		for(int j=0;j<=31;j++){
			if(j>=11&&j<=22)continue;
			a[i][j]=read();
		}
	}
	
	for(int k=2;k<=80;k++){
		for(int i=1;i<=40;i++){
			for(int j=1;j<=31;j++){
				if(a[i][j]==k-1)sx=i,sy=j;
				if(a[i][j]==k)tx=i,ty=j;
			}
		}
//		if(sx==8&&sy==24&&tx==8&&ty==9)ty=10;
		if(ty>sy)Rto(sx,sy,tx,ty-1);
		else if(ty<sy)Lto(sx,sy,tx,ty+1);
		else if(tx>sx)Uto(sx,sy,tx-1,ty);
		else Dto(sx,sy,tx+1,ty);
		if(k==80)aa(tx,ty); 
	}
	return print_ans();
}

