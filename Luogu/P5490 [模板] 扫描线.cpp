#include <cstdio>
#include <algorithm>
#include <map>
#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,X[N],tx,tt,sum[N<<1],len[N<<1],ans;
struct line{int y,x1,x2,tag;
line(int y=0,int x1=0,int x2=0,int tag=0):y(y),x1(x1),x2(x2),tag(tag){}
bool operator <(const line& A)const{return y<A.y;} }lin[N];
map<int,int> mx;

void update(int L,int R,int id,int l,int r,int c){
	if(l<=L&&r>=R)sum[id]+=c;
	else{int M=(L+R)>>1;
		if(l<M)update(L,M,id<<1,l,r,c);
		if(r>M)update(M,R,(id<<1)|1,l,r,c);}
	if(sum[id]>0)len[id]=X[R]-X[L];
	else len[id]=len[id<<1]+len[(id<<1)|1];
	return;
}

signed main(){
	n=read();
	for(int i=1,x1,y1,x2,y2;i<=n;i++){
		x1=read(),y1=read(),x2=read(),y2=read();
		lin[i*2-1]=line(y1,x1,x2,1),lin[i*2]=line(y2,x1,x2,-1);
		X[++tx]=x1,X[++tx]=x2;
	}n<<=1,tt=tx,tx=0,sort(X+1,X+tt+1);
	for(int i=1;i<=tt;i++)if(X[i]!=X[i-1])mx[X[i]]=++tx,X[tx]=X[i];
	for(int i=1;i<=n;i++)lin[i]=line(lin[i].y,mx[lin[i].x1],mx[lin[i].x2],lin[i].tag);
	sort(lin+1,lin+n+1);
	for(int i=1;i<n;i++){
		update(1,tx,1,lin[i].x1,lin[i].x2,lin[i].tag);
		ans+=len[1]*(lin[i+1].y-lin[i].y);
	}printf("%lld\n",ans);
	return 0;
}
