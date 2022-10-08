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

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;

struct opt{
	int ty,i,k,num;
	opt(int ty=0,int i=0,int k=0,int num=0):ty(ty),i(i),k(k),num(num){}
}op[N];

struct fra{
	double a;
	int num;
	fra(double a=0,int num=0):a(a),num(num){}
	bool operator <(const fra& A)const{
		return a>A.a;}
}p[N];

struct add{
	int vl,num;
	add(int vl=0,int num=0):vl(vl),num(num){}
	bool operator <(const add& A)const{
		return vl>A.vl;}};

vector<int> v[N];
int T,k,n,m,a[N],cnt,ans[N];

int main(){
	k=read(),n=read(),m=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int r1=read(),r2=read(),r3=read();
		op[i]=opt(r1,r2,r3,i),v[op[i].i].push_back(i);
	}
	for(int i=1;i<=k;i++){
		int ty1=0,ty11=0;
		vector<add> q;
		
		for(int j=0;j<v[i].size();j++){
			opt o=op[v[i][j]];
			if(o.ty==1)if(o.k>ty1)ty1=o.k,ty11=o.num;
			if(o.ty==2)q.push_back(add(o.k,o.num));
			if(o.ty==3){
				p[++cnt]=fra(o.k,o.num);
//				printf("(%d %f)\n",i,p[cnt].a);
			}
		}
//		printf("(%d %d %d)\n",i,ty1,ty11);
		
		sort(q.begin(),q.end());
		if(ty1>q.begin())q.push_back(add(ty1-a[i],ty11));
		sort(q.begin(),q.end());
		
		double u=a[k];//printf("[%d %d ]\n",i,q.size());
		for(int j=0;j<q.size();j++){
			p[++cnt]=fra(((u+q[j].vl)/u),q[j].num);
			u+=q[j].vl;
		}
	}
	
	sort(p+1,p+cnt+1);
	m=min(m,cnt);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)ans[i]=p[i].num;
//	sort(ans+1,ans+1+m);
	for(int i=1;i<=m;i++)if(op[ans[i]].ty==1)printf("%d ",ans[i]);
	for(int i=1;i<=m;i++)if(op[ans[i]].ty==2)printf("%d ",ans[i]);
	for(int i=1;i<=m;i++)if(op[ans[i]].ty==3)printf("%d ",ans[i]);
	printf("\n");
	
	return 0;
}

