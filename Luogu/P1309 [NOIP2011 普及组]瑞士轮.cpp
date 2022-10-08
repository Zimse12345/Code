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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,R,Q,s[N],rk[N],v[N],win[N],fail[N],t1,t2;
struct p{
	int s,id;
	p(int s=0,int id=0):s(s),id(id){}
	bool operator <(const p& A)const{
		if(s==A.s)return id<A.id;
		else return s>A.s;
	}
}a[N];

int main(){
	n=read(),R=read(),Q=read(); 
	for(int i=1;i<=n*2;i++)s[i]=read(),a[i]=p(s[i],i);
	for(int i=1;i<=n*2;i++)v[i]=read();
	sort(a+1,a+n*2+1);
	for(int i=1;i<=n*2;i++)rk[i]=a[i].id;
	
	for(int rd=1;rd<=R;rd++){
		t1=t2=0;
		for(int i=1;i<=n;i++){
			int l=i*2-1,r=i*2;
			if(v[rk[l]]>v[rk[r]])++s[rk[l]],win[++t1]=rk[l],fail[++t2]=rk[r];
			else ++s[rk[r]],win[++t1]=rk[r],fail[++t2]=rk[l];
		}
		int f1=1,f2=1,k=0;
		while(f1<=t1||f2<=t2){
			if(f2>t2){
				rk[++k]=win[f1++];
				continue;
			}
			if(f1>t1){
				rk[++k]=fail[f2++];
				continue;
			}
			int l=win[f1],r=fail[f2],tag=1;
			if(s[l]==s[r]&&r<l)tag=0;
			if(s[r]>s[l])tag=0;
			if(tag)rk[++k]=win[f1++];
			else rk[++k]=fail[f2++];
		}
	}
	
	printf("%d\n",rk[Q]);
	return 0;
}
