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

int n,q,a[11000],p,ds[11000000],l=1,r;
int s[11000000],tot,op;

signed main(){
	IO.read_int(n);
	for(int i=0;i<n;i++)IO.read_int(a[i]);
	IO.read_int(q);
	while(q--){
		do{op=IO.read_char();}while(op<'1'||op>'4');
		if(op=='1')ds[++r]=a[p++],p%=n;
		if(op=='2')s[++tot]=ds[l++];
		if(op=='3')s[++tot]=ds[r--];
		if(op=='4'){
			int t=1;
			while(t<=tot&&!s[t])++t;
			for(int i=t;i<=tot;i++)IO.write_int(s[i]);
			if(tot<t)IO.write_char('0');
			IO.write_char('\n');
			tot=0;
		}
	}
	return 0;
}

