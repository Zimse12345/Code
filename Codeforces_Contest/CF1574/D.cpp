#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=12,M=1e5+7,INF=1e9+7;
int n,m,c[N],bst[N],to[M*N],ec,ch[M*N],s;
vector<int> a[N];

struct b{
	int v[N];
	bool operator <(const b& A)const{
		for(int i=1;i<=n;i++){
			if(v[i]>A.v[i])return 1;
			if(v[i]<A.v[i])return 0;
		}
		return 1;
	}
}ban[M];

struct two{int A,B;two(int A=0,int B=0):A(A),B(B){};};

two f(int d,int L,int R){
	int id=++ec;
	if(d==n)return two(-INF,id);
	int res=-INF;
	int p=d+1,q=c[p];
	for(int i=L;i<=R;){
		if(q<=0)break;
		int j=i;
		if(q!=ban[i].v[p]){
			s=a[p][q]+bst[p+1];
			if(s>res)to[id]=-1,ch[id]=q;
			break;
		}
		else{
			while(j<R&&q==ban[j+1].v[p])++j;
			two w=f(d+1,i,j);
			s=a[p][q]+w.A;
			if(s>res)res=s,to[id]=w.B,ch[id]=q;
			--q;
		}
		i=j+1;
	}
	if(q>0){
		s=a[p][q]+bst[p+1];
		if(s>res)res=s,to[id]=-1,ch[id]=q;
	}
	return two(res,id);
}

int main(){
	n=read();
	for(int i=1;i<=n;i++){
		c[i]=read(),a[i].push_back(0);
		for(int j=1;j<=c[i];j++)a[i].push_back(read());
	}
	for(int i=n;i>=1;i--)bst[i]=bst[i+1]+a[i][c[i]];
	m=read();
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)ban[i].v[j]=read();
	sort(ban+1,ban+m+1);
	f(0,1,m);
	int p=1,ot=1;
	while(1){
		if(p==-1){
			for(int i=ot;i<=n;i++)printf("%d ",c[i]);
			break;
		}
		else printf("%d ",ch[p]),++ot;
		p=to[p];
	}
	printf("\n");
	return 0;
}
