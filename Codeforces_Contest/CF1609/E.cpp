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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,m;
char s[N];
struct node{
	int a,b,c,ab,bc,abc;
	node(int a=0,int b=0,int c=0,int ab=0,int bc=0,int abc=0):a(a),b(b),c(c),ab(ab),bc(bc),abc(abc){}
}t[N*8];

node merge(node a,node b){
	node res=node(a.a+b.a,a.b+b.b,a.c+b.c,min(a.ab+b.b,a.a+b.ab),min(a.bc+b.c,a.b+b.bc),0);
	res.abc=min(min(a.abc+b.c,a.ab+b.bc),min(a.a+b.abc,a.a+b.c));
	res.ab=min(res.a,res.ab),res.bc=min(res.c,res.bc);
	return res;
}

void build(int L,int R,int id){
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
		t[id]=merge(t[Lid],t[Rid]);
	}
	else{
		if(s[L]=='a')t[id]=node(1,0,0,0,0,1);
		if(s[L]=='b')t[id]=node(0,1,0,1,1,1);
		if(s[L]=='c')t[id]=node(0,0,1,0,0,1);
	}
	return;
}

void update(int L,int R,int id,int p,char c){
	if(L==R){
		if(c=='a')t[id]=node(1,0,0,0,0,1);
		if(c=='b')t[id]=node(0,1,0,1,1,1);
		if(c=='c')t[id]=node(0,0,1,0,0,1);
		s[p]=c;
	}
	else{
		int M=(L+R)>>1;
		if(p<=M)update(L,M,Lid,p,c);
		else update(M+1,R,Rid,p,c);
		t[id]=merge(t[Lid],t[Rid]);
	}
	return;
}

int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	build(1,n,1);
	char c;
	for(int i=1,p;i<=m;i++){
		p=read();cin>>c;
		update(1,n,1,p,c);
		int ans=min(min(t[1].a,t[1].b),min(min(t[1].c,t[1].ab),min(t[1].bc,t[1].abc)));
		printf("%d\n",ans);
	}
	return 0;
}

