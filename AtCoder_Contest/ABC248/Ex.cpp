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

#define ll long long
#define M ((L+R)>>1)
#define Lid ((id<<1))
#define Rid ((id<<1)|1)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=3e5+7,Mod=1004535809,INF=1e9+7;
int n,K,a[N],lmax[N],rmax[N],lmin[N],rmin[N];
int stk1[N],stk2[N],tp1,tp2;
int mi[N*4][8],cnt[N*4][8],tag[N*4];
ll ans;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;}
};
struct line{int l,r,v;line(int l,int r,int v):l(l),r(r),v(v){}};
vector<line> p[N];

void pushdown(int id){
	if(tag[id]!=0){
		for(int i=0;i<8;i++)mi[id][i]+=tag[id];
		if(Rid<N*4)tag[Lid]+=tag[id],tag[Rid]+=tag[id];
		tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	for(int i=0;i<8;i++)mi[id][i]=N;
	cnt[id][0]=R-L+1;
	if(L!=R)build(L,M,Lid),build(M+1,R,Rid);
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(R<l||r<L)return;
	if(l<=L&&r>=R)tag[id]+=x,pushdown(id);
	else{
		update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x);
		vector<node> val;
		for(int i=0;i<8;i++)val.push_back(node(mi[Lid][i],cnt[Lid][i])),val.push_back(node(mi[Rid][i],cnt[Rid][i]));
		sort(val.begin(),val.end());
		int p=-1;
		for(int i=0;i<signed(val.size());i++){
			if(i==0||val[i].x!=val[i-1].x){
				++p;
				if(p>7)break;
				cnt[id][p]=0,mi[id][p]=val[i].x;
			}
			cnt[id][p]+=val[i].y;
		}
		for(int i=p+1;i<8;i++)mi[id][i]=N,cnt[id][i]=0;
	}
	return;
}

signed main(){
	n=read(),K=read();
	for(int i=1;i<=n;i++)a[i]=read();
	
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
		//i         : (lmax[i],i)+a[i]
		//rmax[i]+1 : (lmax[i],i)-a[i]
		//i         : (lmin[i],i)-a[i]
		//rmin[i]+1 : (lmin[i],i)+a[i]
		//i         : (i,i)+i
		//i         : (1,i)-i
		//i+1       : (1,i)+i
		p[i].push_back(line(lmax[i],i,a[i]));
		p[rmax[i]+1].push_back(line(lmax[i],i,-a[i]));
		p[i].push_back(line(lmin[i],i,-a[i]));
		p[rmin[i]+1].push_back(line(lmin[i],i,+a[i]));
		p[i].push_back(line(i,i,i));
		p[i].push_back(line(1,i,-i));
		p[i+1].push_back(line(1,i,i));
	}
	build(1,n,1);
	for(int i=1;i<=n;i++){
		update(1,n,1,i,i,-N);	
		for(unsigned j=0;j<p[i].size();j++){
			update(1,n,1,p[i][j].l,p[i][j].r,p[i][j].v);
		}
		pushdown(1);
		for(int j=0;j<8;j++){
			if(mi[1][j]<=K)ans+=cnt[1][j];
		}
	}
	printf("%lld\n",ans);
//	for(int i=1;i<=n;i++)printf("%d [%d %d %d %d]\n",a[i],lmax[i],rmax[i],lmin[i],rmin[i]);
	return 0;
}

