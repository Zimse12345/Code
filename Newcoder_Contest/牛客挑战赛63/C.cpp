/********************************
*FileName:
*Author: Zimse
*Data:
*Description:
*Other:
********************************/

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

#define gc getchar
#define pc putchar
#define yes _Yes()
#define no _No()
#define ll long long
#define int __int128
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=998244353;//1000000007;
namespace Zimse{
inline int read(){int x=0,y=1;char c=gc();while(c<48||c>57){if(c==45)y=-1;c=gc();}while(c>=48&&c<=57)x=x*10+c-48,c=gc();return x*y;}
inline void write(int x){if(x<0)pc(45),x=-x;if(x>=10)write(x/10);pc(48+x%10);return;}
inline void _Yes(){pc(89),pc(101),pc(115),pc(10);return;}
inline void _No(){pc(78),pc(111),pc(10);return;}
inline void _ck(bool x){x?yes:no;return;}
inline void write_(int x){write(x),pc(32);return;}
inline void _write(int x){write(x),pc(10);return;}
inline void ifile(const char str[]){freopen(str,"r",stdin);return;}
inline void ofile(const char str[]){freopen(str,"w",stdout);return;}
inline void cfile(){fclose(stdin),fclose(stdout);return;}
inline ll fpow(ll x,ll y){ll res=1ll;while(y){if(y&1ll)res=res*x%Mod;x=x*x%Mod,y/=2ll;}return res;}
inline ll inv(ll x){return fpow(x,Mod-2);}
inline int _gcd(int x,int y){return y?_gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
}using namespace Zimse;

const int N=1e6+7;
const int INF=1e37;

int T,n,m;
char s[N],v[N];

void see(){
	m=0;int p=10000;
	while(p--){
		for(int i=1;i<=m;i++)pc(v[i]);pc(10);
		int w=m;
			while(v[w]=='9')v[w]='0',--w;
			if(!w)v[1]='1',v[++m]='0';
			else ++v[w];
	}return;
}

bool ck(int b){
	for(int i=1;i<=n;i++){
		if(s[i]!=v[b])return false;
		++b;
		if(b>m){
			b=1;
			int w=m;
			while(v[w]=='9')v[w]='0',--w;
			if(!w)v[1]='1',v[++m]='0';
			else ++v[w];
		}
	}
	return true;
}

signed main(){//see();
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=INF;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				m=j;
				int tag=1;
				for(int k=1;k<=i;k++){
					v[j-i+k]=s[k];
					if(s[k]!='9')tag=0;
				}
				for(int k=1;k<=j-i;k++)v[k]='0';
				for(int k=1;k<=min(j-i,n-i);k++)v[k]=s[i+k];
				if(v[1]=='0')continue;
				if(tag){
					int w=j-i;
					while(v[w]=='0')v[w]='9',--w;
					--v[w];
				}
				int val=0;
				for(int k=1;k<=j;k++)val=val*10+v[k]-'0';
				if(ck(j-i+1)){
					int sum=val+1;
					for(int t=10;t<=val;t*=10)sum+=val-t+1;
					ans=min(ans,sum-i+1);
//					_write(val);
//					_write(sum-i+1);
//					printf("\n\n");
				}
			}
		}
		_write(ans);
	}
	return 0;
}


