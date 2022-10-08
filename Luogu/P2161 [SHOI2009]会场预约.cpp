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
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m=1e5,mi[N*8],tag[N*8],del[N],ty[N],lll[N],rrr[N];
char op;

void pushdown(int id){
	if(tag[id])mi[id]=tag[Lid]=tag[Rid]=tag[id],tag[id]=0;
	return;
}

void build(int L,int R,int id){
	mi[id]=INF;
	if(L^R){
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l>R||r<L)return;
	if(l<=L&&r>=R)tag[id]=x,pushdown(id);
	else{
		int M=(L+R)>>1;
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		mi[id]=min(mi[Lid],mi[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l>R||r<L)return INF;
	if(l<=L&&r>=R)return mi[id];
	int M=(L+R)>>1;
	return min(query(L,M,Lid,l,r),query(M+1,R,Rid,l,r));
}

int main(){
	srand(time(0));
	n=read();
	build(1,m,1);
	for(int i=1;i<=n;i++){
		do{op=getchar();}while(op!='A'&&op!='B');
		if(op=='A')lll[i]=read(),rrr[i]=read();
		else ty[i]=1;
	}
	for(int i=n;i>=1;i--)if(ty[i]==0){
		int l=lll[i],r=rrr[i];
		int d=query(1,m,1,l,r);
		if(d!=INF)++del[d];
		update(1,m,1,l,r,i);
	}
	for(int i=1,s=0;i<=n;i++){
		if(!ty[i]){
			s+=1-del[i];
			printf("%d\n",del[i]);
		}
		else printf("%d\n",s);
	}
	return 0;
}

