#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>

#define int long long
#define M ((L+R)>>1)
#define Lid ((id<<1))
#define Rid ((id<<1)|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5+7;
int n,q,a[N],lmax[N],rmax[N],lmin[N],rmin[N];
int stk1[N],stk2[N],tp1,tp2;
int I,ans[N],mxid;
struct node{int num,cnt,his,Min,tot,sum,from,to;node(int num=0,int cnt=0,int his=0,int Min=0,int tot=0,int sum=0,int from=0,int to=0):num(num),cnt(cnt),his(his),Min(Min),tot(tot),sum(sum),from(from),to(to){}}tr[N*4];
struct line{int l,r,v;line(int l=0,int r=0,int v=0):l(l),r(r),v(v){}};
vector<line> p[N],Q[N];

void mergetag(int id,int _id){
	if(tr[_id].sum==tr[_id].Min)tr[_id].tot+=tr[id].from-tr[_id].to-1;
	if(tr[id].Min+tr[_id].sum==tr[_id].Min)tr[_id].tot+=tr[id].tot;
	if(tr[id].Min+tr[_id].sum<tr[_id].Min)tr[_id].Min=tr[id].Min+tr[_id].sum,tr[_id].tot=tr[id].tot;
	tr[_id].to=tr[id].to,tr[_id].sum+=tr[id].sum;
	return;
}

void pushdown(int id){
	if(tr[id].from==I){
		if(Rid<=mxid){
			if(tr[Lid].from!=I)pushdown(Lid);
			if(tr[Rid].from!=I)pushdown(Rid);
			tr[Lid].sum+=tr[id].sum,tr[Lid].Min+=tr[id].sum,tr[Rid].sum+=tr[id].sum,tr[Rid].Min+=tr[id].sum;
		}
		tr[id].num+=tr[id].sum,tr[id].sum=tr[id].Min=0;
		return;
	}
	if(tr[id].Min==tr[id].sum)tr[id].tot+=I-1-tr[id].to;
	tr[id].to=I-1;
	if(tr[id].num+tr[id].Min==0)tr[id].his+=tr[id].cnt*tr[id].tot;
	tr[id].num+=tr[id].sum;
	if(Rid<=mxid)mergetag(id,Lid),mergetag(id,Rid);
	tr[id].Min=tr[id].sum=0,tr[id].tot=1,tr[id].from=tr[id].to=I;
	return;
}

node merge(node l,node r){
	node res=node(min(l.num,r.num),0,l.his+r.his,0,1,0,I,I);
	if(l.num==res.num)res.cnt+=l.cnt;
	if(r.num==res.num)res.cnt+=r.cnt;
	return res;
}

void build(int L,int R,int id){
	mxid=max(mxid,id);
	tr[id]=node(0,R-L+1,0,0,1,0,1,1);
	if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(R<l||r<L)return;
	if(l<=L&&r>=R)tr[id].sum+=x,tr[id].Min+=x,pushdown(id);
	else{
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		tr[id]=merge(tr[Lid],tr[Rid]);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(r<L||R<l)return 0;
	if(l<=L&&r>=R)return tr[id].his;
	return query(L,M,Lid,l,r)+query(M+1,R,Rid,l,r);
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	q=read();
	for(int i=1,l,r;i<=q;i++)l=read(),r=read(),Q[r].push_back(line(l,r,i));
	lmax[1]=lmin[1]=1,tp1=tp2=1,stk1[1]=stk2[1]=1;
	for(int i=2;i<=n;i++){
		while(tp1&&a[i]>a[stk1[tp1]])--tp1;
		while(tp2&&a[i]<a[stk2[tp2]])--tp2;
		lmax[i]=stk1[tp1]+1,lmin[i]=stk2[tp2]+1;
		stk1[++tp1]=i,stk2[++tp2]=i;
	}
	rmax[n]=rmin[n]=n,tp1=tp2=1,stk1[1]=stk2[1]=n,stk1[0]=stk2[0]=n+1;
	for(int i=n-1;i>=1;i--){
		while(tp1&&a[i]>a[stk1[tp1]])--tp1;
		while(tp2&&a[i]<a[stk2[tp2]])--tp2;
		rmax[i]=stk1[tp1]-1,rmin[i]=stk2[tp2]-1;
		stk1[++tp1]=i,stk2[++tp2]=i;
	}
	for(int i=1;i<=n;i++){
		p[i].push_back(line(lmax[i],i,a[i]));
		p[rmax[i]+1].push_back(line(lmax[i],i,-a[i]));
		p[i].push_back(line(lmin[i],i,-a[i]));
		p[rmin[i]+1].push_back(line(lmin[i],i,+a[i]));
		p[1].push_back(line(i,i,i));
		p[i].push_back(line(1,n,-i));
		p[i+1].push_back(line(1,n,i));
	}
	build(1,n,1);
	for(int i=1;i<=n+1;i++){
		I=i;
		for(unsigned j=0;j<Q[i-1].size();j++)ans[Q[i-1][j].v]=query(1,n,1,Q[i-1][j].l,Q[i-1][j].r);
		for(unsigned j=0;j<p[i].size();j++)if(p[i][j].v>0)update(1,n,1,p[i][j].l,p[i][j].r,p[i][j].v);
		for(unsigned j=0;j<p[i].size();j++)if(p[i][j].v<0)update(1,n,1,p[i][j].l,p[i][j].r,p[i][j].v);
		
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}

