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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,M=1e6+7,Mod=998244353,INF=1e9+7;
struct data{
	int h,v,id,f;double c;
	data(int h=0,int v=0,int id=0,int f=0,double c=0):h(h),v(v),id(id),f(f),c(c){}
}a[N];
struct node{int x;double y;node(int x=0,double y=0):x(x),y(y){}};

inline bool cmp_h(data& A,data& B){return A.h<B.h;}
inline bool cmp_v(data& A,data& B){return A.v<B.v;}
inline bool cmp_id(data& A,data& B){return A.id<B.id;}
int n,mx[M],lf[N],rf[N],F;
double ans[N],mc[M],C,lc[N],rc[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x,int f,double c){for(;x<M;ub(x)){
	if(f>mx[x])mx[x]=f,mc[x]=c;else if(f==mx[x])mc[x]+=c;}return;}
inline void del(int x){for(;x<M;ub(x))mx[x]=mc[x]=0;return;}
inline node qu(int x){node res;for(;x>0;db(x)){
if(mx[x]>res.x)res=node(mx[x],mc[x]);else if(mx[x]==res.x)res.y+=mc[x];}return res;}

void sol(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	sol(l,mid);
	sort(a+l,a+mid+1,cmp_h),sort(a+mid+1,a+r+1,cmp_h);
	
	int j=l;
	for(int i=mid+1;i<=r;i++){
		while(j<=mid&&a[j].h<=a[i].h)add(a[j].v,a[j].f,a[j].c),++j;
		node q=qu(a[i].v);++q.x;
		if(q.x>a[i].f)a[i].f=q.x,a[i].c=q.y;
		else if(q.x==a[i].f)a[i].c+=q.y;
	}
	for(int i=l;i<j;i++)del(a[i].v);
	
	sort(a+l,a+r+1,cmp_id);
	sol(mid+1,r);
	return;
}

signed main(){
	n=read();
	for(int i=1,h,v;i<=n;i++)h=read(),v=read(),a[i]=data(h,v,i,1,1);
	sort(a+1,a+n+1,cmp_h);
	for(int i=1,j=0,pr=0;i<=n;i++){
		if(a[i].h!=pr)++j;
		pr=a[i].h,a[i].h=j;
	}
	sort(a+1,a+n+1,cmp_v);
	for(int i=1,j=0,pr=0;i<=n;i++){
		if(a[i].v!=pr)++j;
		pr=a[i].v,a[i].v=j;
	}
	sort(a+1,a+n+1,cmp_id);
	for(int i=1;i<=n;i++)a[i].h=1e6-a[i].h,a[i].v=1e6-a[i].v;
	
	sol(1,n);
	sort(a+1,a+n+1,cmp_id);
	for(int i=1;i<=n;i++){
		lf[i]=a[i].f,lc[i]=a[i].c;
		if(lf[i]>F)F=lf[i],C=lc[i];
		else if(lf[i]==F)C+=lc[i];
	}
	for(int i=1;i<=n;i++){
		a[i].id=n-a[i].id+1;
		a[i].h=1e6-a[i].h,a[i].v=1e6-a[i].v;
		a[i].f=a[i].c=1;
	}
	sort(a+1,a+n+1,cmp_id);
	sol(1,n);
	printf("%d\n",F);
	for(int i=1;i<=n;i++){
		rf[i]=a[n-i+1].f,rc[i]=a[n-i+1].c;
		if(lf[i]+rf[i]-1==F)ans[i]=lc[i]*rc[i]/C;
		printf("%.5lf ",ans[i]);
	}
	printf("\n");
	return 0;
}

