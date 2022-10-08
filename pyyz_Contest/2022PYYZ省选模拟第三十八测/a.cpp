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
#include <cctype>

#define ll long long
#define ull unsigned long long

using namespace std;

const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){
		if(p==q){
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void read_int(T& x){
		char c=read_char(),l=0;
		for(x=0;!isdigit(c);c=read_char())l=c;
		for(;isdigit(c);c=read_char())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void write_char(char c){
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void write_int(T x){
		if(x<0)write_char('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)write_char(stk[tp--]);
	}
}IO;

const int N=4e6+7,Mod=998244353,INF=1e9+7;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int n,a[N],g,t[N],MX;
ll f[N],C[N];

signed main(){
	IO.read_int(n);
	for(int i=1;i<=n;i++){
		IO.read_int(a[i]);
		g=gcd(g,a[i]);
	}
	for(int i=1;i<=n;i++)a[i]/=g,t[a[i]]++,MX=max(MX,a[i]);
	if(t[1]){
		printf("%d\n",n-t[1]);
		return 0;
	}
	for(int i=1;i<=MX;i++)if(t[i]){
		t[i]=1;
		for(int j=2;j*i<=MX;j++)t[j*i]=0;
	}
	for(int i=0;i<=MX;i++)C[i]=i;
	for(int k=2;k<=100;k++){
		for(int i=0;i<k;i++)C[i]=0;
		for(int i=k;i<=MX;i++)C[i]=C[i]*(i-k+1)/k;
		for(int i=1;i<=MX;i++){
			int c=0;
			for(int j=1;i*j<=MX;j++)c+=t[i*j];
			f[i]=C[c];
		}
		for(int i=MX;i>=1;i--){
			for(int j=2;i*j<=MX;j++)f[i]-=f[i*j];
		}
		if(f[1]){
			printf("%d\n",k-1+n-1);
			return 0;
		}
	}
	return 0;
}
