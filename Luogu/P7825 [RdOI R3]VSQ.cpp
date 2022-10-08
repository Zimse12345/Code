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

inline int read(){
	int x;
	IO.read_int(x);
	return x;
}

inline void write(int x){
	IO.write_int(x);
	IO.write_char('\n');
	return;
}

const int N=3e5+7,SZ=256;
int n,m,a[N],cnt,Id[N];

struct block{
	int L,R,l,r,len,pre,suf,full,t[SZ+1],ts[SZ+1],mx,val,rev;
	
	inline void init_block(){
		l=a[L],r=a[R],len=R-L+1,pre=1,suf=1,full=mx=rev=0,val=-1;
		for(int i=0;i<=SZ;i++)t[i]=ts[i]=0;
		while(L+pre<=R&&a[L+pre]!=a[L+pre-1])++pre;
		while(R-suf>=L&&a[R-suf]!=a[R-suf+1])++suf;
		if(pre==len)full=1;
		else{
			int s=1;
			for(int i=L+pre+1;i<=R-suf;i++){
				if(a[i]==a[i-1])mx=max(mx,s),++t[s],s=1;
				else ++s;
			}
			mx=max(mx,s),++t[s],ts[mx]=mx*t[mx];
			for(int i=mx-1;i>=0;i--)ts[i]=ts[i+1]+i*t[i],t[i]+=t[i+1];
		}
		return;
	}
	
	inline void upt(){
		if(rev){
			if(val!=-1)val^=1;
			else for(int i=L;i<=R;i++)a[i]^=1;
		}
		if(val!=-1){
			for(int i=L;i<=R;i++)a[i]=val;
		}
		return;
	}
}b[4096];

inline int calc(int x,int y){
	if(y>x)return 0;
	return x-y+1;
}

signed main(){
	block L,R,P;
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int l=1,r;l<=n;){
		r=min(n,l+SZ-1),++cnt;
		b[cnt].L=l,b[cnt].R=r,b[cnt].init_block();
		for(int i=l;i<=r;i++)Id[i]=cnt;
		l=r+1;
	}
	for(int I=1;I<=m;I++){
		int op=read();
		if(op<=2){
			int l=read(),r=read();
			for(int i=Id[l]+1;i<=Id[r]-1;i++){
				if(op<2)b[i].val=b[i].l=b[i].r=op,b[i].rev=0;
				else b[i].rev^=1,b[i].l^=1,b[i].r^=1;
			}
			
			if(Id[l]==Id[r]){
				b[Id[l]].upt();
				for(int i=l;i<=r;i++){
					if(op<2)a[i]=op;
					else a[i]^=1; 
				}
				b[Id[l]].init_block();
			}
			else{
				b[Id[l]].upt(),b[Id[r]].upt();
				for(int i=l;i<b[Id[l]+1].L;i++){
					if(op<2)a[i]=op;
					else a[i]^=1;
				}
				for(int i=b[Id[r]-1].R+1;i<=r;i++){
					if(op<2)a[i]=op;
					else a[i]^=1;
				}
				b[Id[l]].init_block(),b[Id[r]].init_block();
			}
		}
		else if(op==4){
			int ans=1,l=read(),r=read();
			b[Id[l]].upt(),b[Id[l]].init_block();
			b[Id[r]].upt(),b[Id[r]].init_block();
			if(Id[l]==Id[r]){
				P.L=l,P.R=r;
				P.init_block();
				if(P.full)ans=P.len;
				else ans=max(max(ans,P.mx),max(P.pre,P.suf));
			}
			else{
				L.L=l,L.R=b[Id[l]+1].L-1,R.L=b[Id[r]-1].R+1,R.R=r;
				L.init_block(),R.init_block();
				ans=max(ans,max(max(L.pre,L.mx),max(R.mx,R.suf)));
				int s=L.suf;
				for(int i=Id[l]+1;i<=Id[r]-1;i++){
					int p=b[i-1].r;
					if(i==Id[l]+1)p=L.r;
					if(b[i].l==p){
						ans=max(ans,s);
						if(b[i].val==-1)s=b[i].suf,ans=max(ans,b[i].pre);
						else s=1;
					}
					else if(b[i].full)s+=b[i].len;
					else{
						if(b[i].val==-1)s+=b[i].pre;
						else s+=1;
						ans=max(ans,s);
						if(b[i].val==-1)s=b[i].suf;
						else s=1;
					}
					if(b[i].val==-1)ans=max(ans,b[i].mx);
				}
				if(R.l!=b[Id[r]-1].r)ans=max(ans,s+R.pre);
				else ans=max(ans,max(s,R.pre));
			}
			write(ans);
		}
		else{
			int ans=0,l=read(),r=read(),k=read();
			b[Id[l]].upt(),b[Id[l]].init_block();
			b[Id[r]].upt(),b[Id[r]].init_block();
			if(Id[l]==Id[r]){
				block P;
				P.L=l,P.R=r;
				P.init_block();
				if(P.full)ans=calc(P.len,k);
				else{
					ans=calc(P.pre,k)+calc(P.suf,k);
					if(k<=SZ)ans+=P.ts[k]-P.t[k]*(k-1);
				}
			}
			else{
				block L,R;
				L.L=l,L.R=b[Id[l]+1].L-1,R.L=b[Id[r]-1].R+1,R.R=r;
				L.init_block(),R.init_block();
				if(k<=SZ)ans+=L.ts[k]-L.t[k]*(k-1);
				if(k<=SZ)ans+=R.ts[k]-R.t[k]*(k-1);
				if(!L.full)ans+=calc(L.pre,k);
				if(!R.full)ans+=calc(R.suf,k);
				int s=L.suf;
				for(int i=Id[l]+1;i<=Id[r]-1;i++){
					int p=b[i-1].r;
					if(i==Id[l]+1)p=L.r;
					if(b[i].l==p){
						ans+=calc(s,k);
						if(b[i].val==-1){
							s=b[i].suf;
							if(!b[i].full)ans+=calc(b[i].pre,k);
						}
						else s=1;
					}
					else if(b[i].full)s+=b[i].len;
					else{
						if(b[i].val==-1)s+=b[i].pre;
						else s+=1;
						ans+=calc(s,k);
						if(b[i].val==-1)s=b[i].suf;
						else s=1;
					}
					if(b[i].val==-1)if(k<=SZ)ans+=b[i].ts[k]-b[i].t[k]*(k-1);
				}
				if(R.l!=b[Id[r]-1].r)ans+=calc(s+R.pre,k);
				else ans+=calc(s,k)+calc(R.pre,k);
			}
			write(ans);
		}
	}
	return 0;
}

