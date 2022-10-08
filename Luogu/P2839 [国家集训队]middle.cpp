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
#define Lid (ch[id][0])
#define Rid (ch[id][1])
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],c[N],ct,t,pos[N];
int ch[N*32][2],tot,rt[N];
vector<int> num[N];
struct val{int x,y;val(int x=0,int y=0):x(x),y(y){}bool operator < (const val& A)const{return x<A.x;}}b[N];
struct node{int sum,lx,rx,mx;node(int sum=0,int lx=0,int rx=0,int mx=0):sum(sum),lx(lx),rx(rx),mx(mx){}}tree[N*32];
inline node merge(node A,node B){return node(A.sum+B.sum,max(A.lx,A.sum+B.lx),max(B.rx,B.sum+A.rx),max(max(A.mx,B.mx),A.rx+B.lx));}

void build(int& id,int L,int R){
	id=++tot;
	if(L==R)tree[id]=node(-1,-1,-1,-1);
	else build(Lid,L,M),build(Rid,M+1,R),tree[id]=merge(tree[Lid],tree[Rid]);
	return;
}

void update(int& id,int L,int R,int _id,int x){
	id=++tot;
	if(L==R)tree[id]=node(1,1,1,1);
	else{
		if(x<=M)update(Lid,L,M,ch[_id][0],x),Rid=ch[_id][1];
		else update(Rid,M+1,R,ch[_id][1],x),Lid=ch[_id][0];
		tree[id]=merge(tree[Lid],tree[Rid]);
	}
	return;
}

node query(int id,int L,int R,int l,int r){
	if(l>r)return node(0,0,0,0);
	if(l<=L&&r>=R)return tree[id];
	if(r<=M)return query(Lid,L,M,l,r);
	if(l>M)return query(Rid,M+1,R,l,r);
	return merge(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
	n=read();
	build(rt[0],1,n);
	for(int i=1,x;i<=n;i++)x=read(),b[i]=val(x,i);
	sort(b+1,b+n+1),b[0].x=-1;
	for(int i=1;i<=n;i++){
		if(b[i].x!=b[i-1].x)c[++ct]=b[i].x;
		a[b[i].y]=ct,num[ct].push_back(b[i].y);
	}
	for(int i=ct;i>=1;i--){
		for(unsigned j=0;j<num[i].size();j++)++t,update(rt[t],1,n,rt[t-1],num[i][j]);
		pos[i]=t;
	}
	m=read();	 
	for(int i=1,A,B,C,D,ans=0;i<=m;i++){
		A=(read()+ans)%n+1,B=(read()+ans)%n+1,C=(read()+ans)%n+1,D=(read()+ans)%n+1;
		int q[6]={0,A,B,C,D,0};
		sort(q+1,q+5),A=q[1],B=q[2],C=q[3],D=q[4],ans=0;
		int L=1,R=ct;
		while(L<=R){
			if(query(rt[pos[M]],1,n,A,B).rx+query(rt[pos[M]],1,n,C,D).lx+query(rt[pos[M]],1,n,B+1,C-1).sum>=0)ans=M,L=M+1;
			else R=M-1;
		}
		ans=c[ans];
		printf("%d\n",ans);
	}
	return 0;
}

