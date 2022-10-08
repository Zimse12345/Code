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
//#define int long long
//#define M ((L+R)/2)
//#define Lid (id<<1)
//#define Rid (Lid|1)
//#define Lid ch[id][0]
//#define Rid ch[id][1]

using namespace std;

namespace Zimse{
const int Mod=998244353;
//const int Mod=1000000007;
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
const int INF=1000114514;
}using namespace Zimse;

const int N=1e6+7;

struct word{
	int id,cnt,lst;
	word(int id=0,int cnt=0,int lst=0):id(id),cnt(cnt),lst(lst){}
	bool operator < (const word& _)const{
		if(cnt==_.cnt)return lst<_.lst;
		return cnt<_.cnt;
	}
}a[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};

int n;
char s[N];
vector<char> str[N];
vector<int> rm;
vector<node> A,B;

inline void pr(int id){
	for(unsigned i=0;i<str[id].size();i++)pc(str[id][i]);
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int j=1;j<=len;j++)str[i].push_back(s[j]);
		int cnt=0,lst=0;
		for(int j=1;j<=len;j++){
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
				++cnt,lst=s[j];
			}
		}
		a[i]=word(i,cnt,lst);
	}
	sort(a+1,a+n+1);
	for(int l=1,r=0;l<=n;){
		if(a[l].cnt!=a[l-1].cnt){
			for(unsigned i=0;i+1<rm.size();i+=2){
				B.push_back(node(rm[i],rm[i+1]));
			}
			rm.resize(0);
		}
		r=l;
		while(r<n&&a[r+1].cnt==a[l].cnt&&a[r+1].lst==a[l].lst)++r;
		for(int i=l;i<r;i+=2){
			A.push_back(node(a[i].id,a[i+1].id));
		}
		if((r-l+1)&1)rm.push_back(a[r].id);
		l=r+1;
	}
	for(unsigned i=0;i+1<rm.size();i+=2){
		B.push_back(node(rm[i],rm[i+1]));
	}
	int ca=A.size(),cb=B.size();
	if(ca>cb){
		int k=(ca-cb)/2;
		for(int i=ca-1;i>=ca-k;i--)B.push_back(A[i]);
		ca=cb+k;
	}
	_write(ca);
	for(int i=0;i<ca;i++){
		pr(B[i].x),pc(32),pr(A[i].x),pc(10);
		pr(B[i].y),pc(32),pr(A[i].y),pc(10);
	}
	return 0;
}


