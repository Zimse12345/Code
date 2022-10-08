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
#define M ((L+R)>>1)
#define Lid (id<<1)
#define Rid (Lid|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m;
double x[N],y[N];
double sum2(double x){return x*(x+1)*(2*x+1)/6;}
struct node{
	double len,sx,sy,x2,xy;
	bool tag1,tag2;
	double addx,addy,setx,sety;
	node(double len=0,double sx=0,double sy=0,double x2=0,double xy=0,
	bool tag1=0,bool tag2=0,double addx=0,double addy=0,double setx=0,double sety=0):
	len(len),sx(sx),sy(sy),x2(x2),xy(xy),tag1(tag1),tag2(tag2),addx(addx),addy(addy),setx(setx),sety(sety){}
	void settag(node A){tag1=false,tag2=true,addx=addy=0,setx=A.setx,sety=A.sety;return;}
}t[N*4];

node merge(node A,node B){
	return node(A.len+B.len,A.sx+B.sx,A.sy+B.sy,A.x2+B.x2,A.xy+B.xy,0,0,0,0);
}

void pushdown(int id,double l,double r){
	if(t[id].tag2){
		t[Lid].settag(t[id]),t[Rid].settag(t[id]);
		t[id].sx=(t[id].setx*2+l+r)*(t[id].len)/2,t[id].sy=(t[id].sety*2+l+r)*(t[id].len)/2;
		t[id].x2=sum2(t[id].setx+r)-sum2(t[id].setx+l-1);
		double S=t[id].setx+l,T=t[id].sety+l;
		t[id].xy=S*T*t[id].len+(S+T)*(1+r-l)*(r-l)/2+sum2(r-l);
		t[id].tag2=false;
	}
	if(t[id].tag1){
		t[Lid].tag1=t[Rid].tag1=true;
		t[Lid].addx+=t[id].addx,t[Lid].addy+=t[id].addy;
		t[Rid].addx+=t[id].addx,t[Rid].addy+=t[id].addy;
		t[id].x2+=t[id].addx*t[id].sx*2+t[id].addx*t[id].addx*t[id].len;
		t[id].xy+=t[id].addx*t[id].sy+t[id].addy*t[id].sx+t[id].addx*t[id].addy*t[id].len;
		t[id].sx+=t[id].addx*t[id].len,t[id].sy+=t[id].addy*t[id].len;
		t[id].tag1=false,t[id].addx=t[id].addy=0;
	}
	return;
}

void build(int L,int R,int id){
	if(L==R)t[id]=node(R-L+1,x[L],y[L],1.0*x[L]*x[L],1.0*x[L]*y[L],false,false,0,0,0,0);
	else{
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void update1(int L,int R,int id,int l,int r,int S,int T){
	pushdown(id,L,R);
	if(R<l||r<L)return;
	if(l<=L&&r>=R)t[id].tag1=true,t[id].addx=S,t[id].addy=T,pushdown(id,L,R);
	else{
		update1(L,M,Lid,l,r,S,T),update1(M+1,R,Rid,l,r,S,T);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

void update2(int L,int R,int id,int l,int r,int S,int T){
	pushdown(id,L,R);
	if(R<l||r<L)return;
	if(l<=L&&r>=R)t[id].tag2=true,t[id].setx=S,t[id].sety=T,pushdown(id,L,R);
	else{
		update2(L,M,Lid,l,r,S,T),update2(M+1,R,Rid,l,r,S,T);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

node query(int L,int R,int id,int l,int r){
	pushdown(id,L,R);
	if(R<l||r<L)return node(0,0,0,0,0,false,false,0,0,0,0);
	if(l<=L&&r>=R)return t[id];
	return merge(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)x[i]=read();
	for(int i=1;i<=n;i++)y[i]=read();
	build(1,n,1);
	while(m--){
		int op=read(),l=read(),r=read();
		if(op==1){
			node s=query(1,n,1,l,r);
			double avex=s.sx/s.len,avey=s.sy/s.len;
			double ans=(s.xy-avex*s.sy-avey*s.sx+s.len*avex*avey)/(s.x2-avex*s.sx*2+s.len*avex*avex);
			printf("%.7lf\n",ans);
			continue;
		}
		int S=read(),T=read();
		if(op==2)update1(1,n,1,l,r,S,T);
		else update2(1,n,1,l,r,S,T);
	}
	return 0;
}

