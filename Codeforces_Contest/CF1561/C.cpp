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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,nd[N],to[N],f[N];
vector<int> a;

struct p{
	int l,r,sz;
	p(int l=0,int r=0,int sz=0):l(l),r(r),sz(sz){}
	bool operator < (const p& A)const{if(l==A.l)return sz>A.sz;return l<A.l;}
}s[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			int k=read();
			a.resize(0);a.push_back(0);
			for(int j=1;j<=k;j++)a.push_back(read());
			f[k]=a[k]+1;
			for(int j=k-1;j>=1;j--)f[j]=max(a[j]+1,f[j+1]-1);
			nd[i]=f[1],to[i]=0;
			for(int j=1;j<=k;j++)to[i]=max(to[i],f[j]+(k-j+1));
			s[i]=p(nd[i],to[i],k);
		}
		sort(s+1,s+n+1);
		f[n]=s[n].l;
		for(int i=n-1;i>=1;i--)f[i]=max(s[i].l,f[i+1]-s[i].sz);
		printf("%d\n",f[1]);
	}
	return 0;
}

