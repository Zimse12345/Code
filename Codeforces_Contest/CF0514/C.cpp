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
#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

const int Mod=998244353;//1000000007;
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
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int _abs(int x){return x<0?-x:x;}
inline void addmod(int& x,int y){(x+=y)%=Mod;return;}
inline void _max(int& x,int y){if(y>x)x=y;return;}
inline void _min(int& x,int y){if(y<x)x=y;return;}

const int N=1250000;
const int INF=1000114514;
const int H1=43,H2=117;

int n,m,rt[N],tot,h1[N],h2[N],ch[N][3];
char s[N];
set<int> S[N][2][3];

void ins(int pos,int val,int id,int c){
	S[pos][id-1][c].insert(val);
	return;
}

int Find(int pos,int v1,int v2,int c){
	for(int i=0;i<3;i++)if(c^i){
		if(S[pos][0][i].find(v1)!=S[pos][0][i].end()&&S[pos][1][i].find(v2)!=S[pos][1][i].end())return 1;
	}
	return 0;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=600000;i++)rt[i]=++tot;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		h1[len+1]=h2[len+1]=0;
		for(int i=len;i>=1;i--){
			h1[i]=(h1[i+1]*H1+s[i])%Mod;
			h2[i]=(h2[i+1]*H2+s[i])%Mod;
		}
		int pos=rt[len];
		ins(pos,h1[2],1,s[1]-'a'),ins(pos,h2[2],2,s[1]-'a');
		for(int j=1;j<len;j++){
			if(!ch[pos][s[j]-'a'])ch[pos][s[j]-'a']=++tot;
			pos=ch[pos][s[j]-'a'];
			ins(pos,h1[j+2],1,s[j+1]-'a'),ins(pos,h2[j+2],2,s[j+1]-'a');
		}
	}
	while(m--){
		scanf("%s",s+1);
		int len=strlen(s+1),tag=0;
		int pos=rt[len];
		h1[len+1]=h2[len+1]=0;
		for(int i=len;i>=1;i--){
			h1[i]=(h1[i+1]*H1+s[i])%Mod;
			h2[i]=(h2[i+1]*H2+s[i])%Mod;
		}
		tag|=Find(pos,h1[2],h2[2],s[1]-'a');
		for(int i=1;i<len;i++){
			pos=ch[pos][s[i]-'a'];
			if(!pos)break;
			tag|=Find(pos,h1[i+2],h2[i+2],s[i+1]-'a');
		}
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}


