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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int H,W,n;
int ans;
int Lb[N],Rb[N];
unsigned stk[N],top;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
}p[N];

vector<node> q;

bool cmp_x(const node& A,const node& B){
	if(A.x==B.x)return A.y<B.y;
	return A.x<B.x;
}

bool cmp_y(const node& A,const node& B){
	return A.y<B.y;
}

void sol(int x){
//	printf("[%d]",x);
	top=0;
	for(unsigned i=0;i<q.size();i++){
		if(i)ans=max(ans,2*x+2*(q[i].y-q[i-1].y));
//	printf(" (%d %d)",q[i].x,q[i].y);
		while(top&&q[i].x>=q[stk[top]].x)--top;
		if(!top)Lb[i]=0;
		else Lb[i]=q[stk[top]].y;
		stk[++top]=i;
	}
//	printf("\n");
	top=0;
	for(unsigned i=q.size()-1;i<N;i--){
		while(top&&q[i].x>=q[stk[top]].x)--top;
		if(!top)Rb[i]=H;
		else Rb[i]=q[stk[top]].y;
//		printf("(%d %d %d %d %d)\n",Lb[i],Rb[i],x,q[i].x,2*(Rb[i]-Lb[i])+2*(x-q[i].x));
		ans=max(ans,2*(Rb[i]-Lb[i])+2*(x-q[i].x));
		stk[++top]=i;
	}
	return;
}

void see(){
	sort(q.begin(),q.end(),cmp_y);
	for(unsigned i=0;i<q.size();i++)printf("(%d,%d)  ",q[i].x,q[i].y);
	printf("\n\n");
	return;
}

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	W=read(),H=read(),n=read();
	for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
	
//	for(int x=0;x<=100;x++)for(int tx=x;tx<=100;tx++){
//		for(int y=0;y<=100;y++)for(int ty=y;ty<=100;ty++){
//			int tag=1;
//			for(int i=1;i<=n;i++)if(x<p[i].x&&p[i].x<tx&&y<p[i].y&&p[i].y<ty)tag=0;
//			if(tag){
//				int C=(tx-x)*2+(ty-y)*2;
//				if(C==270){
//					printf("(%d %d %d %d)",x,tx,y,ty);
//				}
//			}
//		}
//	}
	
	sort(p+1,p+n+1,cmp_x);
	p[n+1]=node(-1,-1);                                                                                    
	q.push_back(node(0,0)),q.push_back(node(0,H));
	for(int i=1,j;i<=n;){
		j=i;
		while(p[j+1].x==p[j].x)++j;
		sol(p[i].x);
		int p1=0;
		for(int k=i;k<=j;k++){
			while(p1<signed(q.size())&&q[p1].y<p[k].y)++p1;
			if(q[p1].y==p[k].y)q[p1].x=p[k].x;
			else q.push_back(p[k]);
		}
		sort(q.begin(),q.end(),cmp_y);
		i=j+1;
	}
	sol(W);
	printf("%d\n",ans);
	return 0;
}

