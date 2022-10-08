#include<cstdio>
#include<algorithm>
#include<ctime>
#include<map>

namespace INPUT_SPACE{
	const int S=(1<<20)+5;char B[S],*H,*T;inline int gc() { if(H==T) T=(H=B)+fread(B,1,S,stdin);return (H==T)?EOF:*H++; }
	inline unsigned int inn() { unsigned int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';while((ch=gc())>='0'&&ch<='9') x=x*10+(ch^'0');return x; }
}using INPUT_SPACE::inn;

namespace GENERATE_VALUE_SPACE{
	unsigned int _gen(unsigned int x,unsigned int A,unsigned int B,unsigned int C) { return A*x*x+B*x+C; }
	void gen_value(unsigned int *a,int n,unsigned int A,unsigned int B,unsigned int C,unsigned int a0)
	{ a[1]=_gen(a0,A,B,C);for(int i=2;i<=n;i++) a[i]=_gen(a[i-1],A,B,C); }
}using GENERATE_VALUE_SPACE::gen_value;

int B,N;
unsigned int a[7000000+100];
unsigned int  fa[7000000+100];
unsigned int P[5000],Fa[5000],len[5000],s[5000],ad[5000];
std::map<int,int> Id,SonId;
void cdep(int x,int v){a[x+B]=v;return;}
int qdep(int x){return a[x+B];}
void cFa(int x,int v){fa[x+B]=v;return;}
int qFa(int x){return fa[x+B];}
void aCnt(int x,int v){a[x+B+B]+=v;return;}
int qCnt(int x){return a[x+B+B];}
void cDfn(int x,int v){fa[x+B+B]=v;return;}
int qDfn(int x){return fa[x+B+B];}

void update(int x,int y,unsigned int v) { /*do the update*/ }
unsigned int query(int x,int y) { /*do the query*/unsigned int ans=0; return ans; }
unsigned int K=(1<<28)-1;

void update_s0(int x,int y,unsigned int v){
	int p=x,k=(1<<30)-1,tag=0;
	while(p){
		a[p]+=v;
		fa[p]|=(1<<30);
		p=(fa[p]&k);
	}
	p=y;
	while(p){
		if(tag)a[p]-=v;
		else if(fa[p]&(1<<30))tag=1;
		else a[p]+=v;
		p=(fa[p]&k);
	}
	p=x;
	while(p)fa[p]&=k,p=fa[p];
	p=y;
	while(p)fa[p]&=k,p=fa[p];
	return;
}

unsigned int query_s0(int x,int y){
	unsigned int ans=0;
	int p=x,k=(1<<30)-1,tag=0;
	while(p){
		ans+=a[p];
		fa[p]|=(1<<30);
		p=(fa[p]&k);
	}
	p=y;
	while(p){
		if(tag)ans-=a[p];
		else if(fa[p]&(1<<30))tag=1;
		else ans+=a[p];
		p=(fa[p]&k);
	}
	p=x;
	while(p)fa[p]&=k,p=fa[p];
	p=y;
	while(p)fa[p]&=k,p=fa[p];
	return ans;
}

void sol0(int n,int q){
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			update_s0(x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=query_s0(x,y));
		}
	}
	return;
}

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}

inline void tadd1(int n,int p,unsigned int v){
	for(;p<=n;ub(p))a[p]+=v;
	return;
}

inline void tadd2(int n,int p,unsigned int v){
	for(;p<=n;ub(p))fa[p]+=v;
	return;
}

inline unsigned int tqu1(int p){
	unsigned sum=0;
	for(;p;db(p))sum+=a[p];
	return sum;
}

inline unsigned int tqu2(int p){
	unsigned sum=0;
	for(;p;db(p))sum+=fa[p];
	return sum;
}

void update_s1(int n,int x,int y,unsigned int v){
	if(y<x){int ttt=x;x=y,y=ttt;}
	
	tadd1(n,x,v),tadd1(n,y+1,-v);
	tadd2(n,x,v*unsigned(x)),tadd2(n,y+1,-v*unsigned(y+1));
	return;
}

unsigned query_s1(unsigned l,unsigned r){
	if(r<l){unsigned ttt=l;l=r,r=ttt;}
	unsigned sum=tqu2(r)-tqu2(l-1);
	sum-=l*(tqu1(r)-tqu1(l-1));
	sum=tqu1(r)*(r-l+1)-sum;
	return sum;
}

void sol1(int n,int q){
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	for(int i=n;i>=1;i--){
		unsigned x=a[i];
		a[i]=0,fa[i]=0;
		tadd1(n,i,x),tadd2(n,i,x*unsigned(i));
	}
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			update_s1(n,x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=query_s1(x,y));
		}
	}
	return;
}

void update_s2(int n,int x,int y,unsigned int v){
	
	return;
}

void color(int x){
	fa[x]^=(1<<29);
	int pos=fa[x]&K;
	while(pos&&(!(fa[pos]&(1<<30))))fa[pos]^=(1<<29),pos=fa[pos]&K;
	if(pos)fa[pos]^=(1<<29);
	return;
}

int getlca(int x,int y){
	int X=x,Y=y;
	while(!(fa[X]&(1<<30)))X=fa[X]&K;
	while(!(fa[Y]&(1<<30)))Y=fa[Y]&K;
	if(X^Y){
		X=Id[X],Y=Id[Y];
		int pos=X,mid=0,la=0;
		while(pos)Fa[pos]|=(1<<30),pos=Fa[pos]&K;
		pos=Y;
		while(!(Fa[pos]&(1<<30)))la=pos,pos=Fa[pos]&K;
		mid=pos,pos=X;
		if(la)y=P[la];
		la=0;
		while(pos!=mid)la=pos,pos=Fa[pos]&K;
		if(la)x=P[la];
		pos=X;
		while(pos)Fa[pos]&=K,pos=Fa[pos]&K;
	}
	color(x);
	while(!(fa[y]&(1<<29)))y=fa[y]&K;
	color(x);
	return y;
}

int getid(int x){
	if(fa[x]&(1<<30))return Id[x];
	while(!(fa[fa[x]&K]&(1<<30)))x=fa[x]&K;
	return SonId[x]; 
}

void addval(int x,int y,unsigned v){
	//printf("add(%d %d %d)\n",x,y,v);
	int lca=getlca(x,y);
	int id=getid(x),lcaid=getid(lca);
	if(id!=lcaid){
		a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		while(!(fa[x]&(1<<30)))a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		id=Id[x];
		while(id!=lcaid)s[id]+=v*len[id],ad[id]+=v,id=Fa[id];
		x=P[id];
	}
	a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0);
	while(x!=lca)x=fa[x]&K,a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0);
	x=y;
	id=getid(x);
	if(id!=lcaid){
		a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		while(!(fa[x]&(1<<30)))a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		id=Id[x];
		while(id!=lcaid)s[id]+=v*len[id],ad[id]+=v,id=Fa[id];
		x=P[id];
	}
	while(x!=lca)a[x]+=v,s[id]+=v*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
	return;
}

unsigned qsum(int x,int y){
	//printf("qsum(%d %d) lca=%d\n",x,y,getlca(x,y));
	int ttt=x;x=y,y=ttt;
	unsigned res=0;
	int lca=getlca(x,y);
	int id=getid(x),lcaid=getid(lca);
	if(id!=lcaid){
		res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		while(!(fa[x]&(1<<30)))res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		id=Id[x];
		while(id!=lcaid)res+=s[id],id=Fa[id];
		x=P[id];
	}
	res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0);
	while(x!=lca)x=fa[x]&K,res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0);
	x=y;
	id=getid(x);
	if(id!=lcaid){
		res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		while(!(fa[x]&(1<<30)))res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
		id=Id[x];
		while(id!=lcaid)res+=s[id],id=Fa[id];
		x=P[id];
	}
	while(x!=lca)res+=a[x]+ad[id]*((fa[x]&(1<<28))?1:0),x=fa[x]&K;
	return res;
}

int ggetlca(int x,int y){
	if(qdep(x)<qdep(y)){int ttt=x;x=y,y=ttt;}
	int dc=qdep(x)-qdep(y);
	while(dc>=400)dc-=400,x=qFa(x);
	while(dc)dc--,x=fa[x];
	if(x==y)return x;
	int fx=0,fy=0;
	while(1){
		fx=qFa(x),fy=qFa(y);
		if(fx!=fy)x=fx,y=fy;
		else break;
	}
	while(fa[x]!=fa[y])x=fa[x],y=fa[y];
	return fa[x];
}

unsigned query_s2(unsigned l,unsigned r){
	int sum=0,lca=getlca(l,r);
	sum=a[l]+a[r]-a[lca]-a[fa[lca]&K];
	return sum;
}

void sol2(int n,int q){
	for(int i=1;i<=N;i++)fa[P[i]]|=(1<<30);
	for(int i=2;i<=n;i++)a[i]+=a[fa[i]&K];
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			update_s2(n,x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=query_s2(x,y));
		}
	}
	return;
}

void update_s3(int n,int x,int y,unsigned int v){
	int L=qDfn(x),R=L+qCnt(x)-1;
	tadd1(n,L,v),tadd1(n,R+1,-v);
	return;
}

unsigned query_s3(unsigned l,unsigned r){
	int sum=0,lca=ggetlca(l,r);
	sum=tqu1(qDfn(l))+tqu1(qDfn(r))-tqu1(qDfn(lca))-tqu1(qDfn(fa[lca]));
	return sum;
}

void sol3(int n,int q){
	B=2000020;
	cdep(1,1);
	for(int i=n;i>=1;i--){
		aCnt(i,1);
		aCnt(fa[i],qCnt(i));
	}
	cDfn(1,1);
	for(int i=2;i<=n;i++){
		int f=fa[i];
		int dfn=qDfn(f);
		cDfn(i,dfn+1);
		cDfn(fa[i],dfn+qCnt(i));
	}
	for(int i=1;i<=n;i++){
		int dfn=qDfn(i)-qCnt(i)+1;
		cDfn(i,dfn);
	}
	for(int i=2;i<=n;i++){
		cdep(i,qdep(fa[i])+1);
		a[i]+=a[fa[i]];
	}
	for(int i=1;i<=n;i++)cFa(qDfn(i),a[i]);
	for(int i=1;i<=n;i++)a[i]=qFa(i);
	
	for(int i=n;i>=1;i--)a[i]-=a[i-1];
	for(int i=n;i>=1;i--){
		unsigned x=a[i];
		a[i]=0;
		tadd1(n,i,x);
	}
	
	for(int i=1;i<=n;i++){
		int p=i;
		for(int j=1;j<=400&&p;j++)p=fa[p];
		cFa(i,p);
	}
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			update_s3(n,x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=query_s3(x,y));
		}
	}
	return;
}

void update_s4(int n,int x,int y,unsigned int v){
	int lca=ggetlca(x,y);
	tadd1(n,qDfn(x),v),tadd1(n,qDfn(y),v),tadd1(n,qDfn(lca),-v);
	if(fa[lca])tadd1(n,qDfn(fa[lca]),-v);
	return;
}

unsigned query_s4(unsigned l,unsigned r){
	int L=qDfn(l),R=L+qCnt(l)-1;
	int sum=tqu1(R)-tqu1(L-1);
	return sum;
}

void sol4(int n,int q){
	B=2000020;
	cdep(1,1);
	for(int i=n;i>=1;i--){
		aCnt(i,1);
		aCnt(fa[i],qCnt(i));
	}
	cDfn(1,1);
	for(int i=2;i<=n;i++){
		int f=fa[i];
		int dfn=qDfn(f);
		cDfn(i,dfn+1);
		cDfn(fa[i],dfn+qCnt(i));
	}
	for(int i=1;i<=n;i++){
		int dfn=qDfn(i)-qCnt(i)+1;
		cDfn(i,dfn);
	}
	for(int i=2;i<=n;i++){
		cdep(i,qdep(fa[i])+1);
	}
	
	for(int i=1;i<=n;i++)a[fa[i]]-=a[i];
	for(int i=1;i<=n;i++)cFa(qDfn(i),a[i]);
	for(int i=1;i<=n;i++)a[i]=qFa(i);
	
	for(int i=n;i>=1;i--){
		unsigned x=a[i];
		a[i]=0;
		tadd1(n,i,x);
	}
	
	for(int i=1;i<=n;i++){
		int p=i;
		for(int j=1;j<=400&&p;j++)p=fa[p];
		cFa(i,p);
	}
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			update_s4(n,x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=query_s4(x,y));
		}
	}
	return;
}

int main()
{
	srand(time(0));
//	freopen("3.in","r",stdin);
//	freopen("problemprovidercreep.out","w",stdout);
	
	int subtask_id=inn(),n=inn(),q=inn();
//	printf("%d\n",subtask_id);
//	return 0;
	unsigned int A=inn(),B=inn(),C=inn(),a0=inn();
	
	for(int i=2;i<=n;i++) fa[i]=inn();
	N=std::min(2000,n);
	P[1]=1,a[1]=1,Id[1]=1;
	for(int i=2,x;i<=N;i++){
		x=rand()%(1<<15);
		x=((x<<15)+(rand()%(1<<15)))%n+1;
		while(a[x])x=(x==n?1:x+1);
		a[x]=1,P[i]=x,Id[x]=i;
	}
	for(int i=1;i<=n;i++)a[i]=0;
	int _N=N;
	for(int i=1,x;i<=N;i++){
		x=P[i];
		while(x&&(!a[x]))a[x]=1,x=fa[x];
		if(x&&!Id[x])Id[x]=++_N,P[_N]=x;
	}
	N=_N;
	for(int i=1;i<=n;i++){
		if(a[i])fa[i]|=(1<<28);
		a[i]=0;
	}
	for(int i=1;i<=N;i++)a[P[i]]=i;
	len[1]=1;
	for(int i=2,x,y;i<=N;i++){
		x=fa[P[i]]&K,y=P[i],len[i]=1;
		while(!a[x])y=x,x=fa[x]&K,++len[i];
		Fa[i]=a[x],SonId[y]=i;
	}
	GENERATE_VALUE_SPACE::gen_value(a,n,A,B,C,a0);
	for(int i=1;i<=N;i++)fa[P[i]]|=(1<<30);
	s[1]=a[1];
	for(int i=2,x;i<=N;i++){
		x=P[i],s[i]=a[x],x=fa[x]&K;
		while(!(fa[x]&(1<<30)))s[i]+=a[x],x=fa[x]&K;
	}
//	for(int i=1;i<=N;i++)printf("%d ",P[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)printf("getid(%d)=%d\n",i,getid(i));
/*	if(subtask_id<=2){
//		sol0(n,q);
		return 0;
	}
	if(3<=subtask_id&&subtask_id<=16){
//		sol1(n,q);
		return 0;
	}
	if(17<=subtask_id&&subtask_id<=23){
		sol2(n,q);
		return 0;
	}
	if(24<=subtask_id&&subtask_id<=25){
//		sol3(n,q);
		return 0;
	}
	if(31<=subtask_id&&subtask_id<=32){
//		sol4(n,q);
		return 0;
	}
	return 0;
*/
	
//	for(int i=1;i<=n;i++)printf("%u ",a[i]);
//	addval(1,8,1);printf("\n");
//	for(int i=1;i<=n;i++)printf("%u ",a[i]+ad[getid(i)]);
	unsigned int last_ans=0;
	for(int i=1;i<=q;i++)
	{
		int t=inn();
		int P=last_ans&((1<<20)-1);
		if(t==0)
		{
			int x=inn()^P,y=inn()^P;
			unsigned int v=inn()^P;
			addval(x,y,v);
		}
		else{
			int x=inn()^P,y=inn()^P;
			printf("%u\n",last_ans=qsum(x,y));
		}
	}
	return 0;
}
