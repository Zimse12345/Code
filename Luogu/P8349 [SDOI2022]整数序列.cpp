#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define int long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while('0'<=qrc&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e6+7,SZ=1000;
int n,q,a[N],b[N],pre[N],fm[N],ps[N],Ans[N],lf[N];int tot=0;
vector<int> val[N];
int st[N],top,tag[N];
int pos[N],cnt;
int k0[N],k1[N],k2[N],k01[N],c0,c1,c2,c01;

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x==A.x?y<A.y:x<A.x;}
};
vector<node> qu[N];

int lfind(int pos,int x){
	int L=0,R=val[x].size()-1,res=-1;
	while(L<=R){
		int M=(L+R)/2;++tot;
		if(val[x][M]<pos)res=M,L=M+1;
		else R=M-1;
	}
	return res;
}

int rfind(int pos,int x){
	int L=0,R=val[x].size()-1,res=-1;
	while(L<=R){
		int M=(L+R)/2;++tot;
		if(val[x][M]>pos)res=M,R=M-1;
		else L=M+1;
	}
	return res;
}

int sol(int x,int y){
	int ans=-1e15;
	cnt=0;
	if((val[x].size()+val[y].size()<=2000)||(val[x].size()>=SZ&&val[y].size()>=SZ)){
		unsigned p1=0,p2=0;
		while(p1<val[x].size()||p2<val[y].size()){
			if(p1<val[x].size()&&(p2>=val[y].size()||val[x][p1]<val[y][p2]))pos[++cnt]=val[x][p1++];
			else pos[++cnt]=val[y][p2++];
		}
	}
	else{
		if(val[x].size()>val[y].size())swap(x,y);
		top=0,c0=c1=c2=c01=0;
		st[++top]=0,st[0]=-1;
		int s=0;
		for(unsigned i=0;i<val[x].size();i++){
			k0[++c0]=val[x][i];
			int f=lfind(val[x][i],y);if(!i)lf[top]=f;
			if(!i||f==-1||val[y][f]<val[x][i-1])++s;
			else s=0,st[++top]=i,lf[top]=f;
		}
		st[top+1]=val[x].size();
		for(int i=1;i<=top;i++)tag[i]=st[i+1]-st[i]+1;
		for(int i=top;i>=1;i--){
			int p=lf[i];
			while(p!=-1&&(i==1||val[y][p]>val[x][st[i-1]])&&tag[i]){
				k1[++c1]=val[y][p],--p,--tag[i];
			}
			tag[i-1]+=tag[i];
		}
		for(int i=1;i<=top;i++)tag[i]=st[i+1]-st[i]+1;
		for(int i=1,p=-1;i<=top;i++){
			if(p==-1)p=rfind(val[x][st[i]],y);
			while(p!=-1&&p<signed(val[y].size())&&(i==top||val[y][p]<val[x][st[i+1]])&&tag[i]){
				k2[++c2]=val[y][p],++p,--tag[i];
			}
			tag[i+1]+=tag[i];
			if(!tag[i])p=-1;
		}
		reverse(k1+1,k1+c1+1);
		int p1=1,p2=1;
		while(p1<=c0||p2<=c1){
			if(p1<=c0&&(p2>c1||k0[p1]<k1[p2]))k01[++c01]=k0[p1++];
			else k01[++c01]=k1[p2++];
		}
		p1=1,p2=1;
		while(p1<=c01||p2<=c2){
			if(p1<=c01&&(p2>c2||k01[p1]<k2[p2]))pos[++cnt]=k01[p1++];
			else pos[++cnt]=k2[p2++];
		}
	}
	int p=0,L=0,R=0;
	for(unsigned I=1,i=0;I<=cnt;I++)if(pos[I]!=pos[I-1]){
		++i;
		ps[i]=ps[i-1]+b[pos[I]],fm[i]=0;
		if(a[pos[I]]==x)++p;
		else --p;
		L=min(L,p),R=max(R,p);
		if(!p||pre[p+500000]){
			int Pre=pre[p+500000];
			int sum=ps[i]-ps[Pre];
			if(fm[Pre]>0)sum+=fm[Pre];
			fm[i]=sum,ans=max(ans,sum);
		}
		pre[p+500000]=i;
	}
	for(int i=500000+L;i<=500000+R;i++)pre[i]=0;
	return ans;
}

signed main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(),val[a[i]].push_back(i);
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1,x,y;i<=q;i++){
		x=read(),y=read();
		if(y<x)swap(x,y);
		qu[x].push_back(node(y,i));
	}
	for(int i=1;i<=n;i++){
		sort(qu[i].begin(),qu[i].end());
		int ans=0;
		for(unsigned j=0;j<qu[i].size();j++){
			if(!j||qu[i][j].x!=qu[i][j-1].x)ans=sol(i,qu[i][j].x);
			Ans[qu[i][j].y]=ans;
		}
	}
//	printf("%lld %lld\n",tot,q);
	for(int i=1;i<=q;i++)printf("%lld\n",Ans[i]);
	return 0;
}

