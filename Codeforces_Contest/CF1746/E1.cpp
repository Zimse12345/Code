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

int n,s[N];
char str[64];
vector<int> a,_a;
vector<int> q1,q2;

int query(vector<int> q){
	printf("? %d ",int(q.size()));
	for(unsigned i=0;i<q.size();i++)printf("%d ",q[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",str);
	return str[0]=='Y'?1:0;
}

int answer(int ans){
	printf("! %d\n",ans);
	fflush(stdout);
	scanf("%s",str);
	return str[1]==')'?1:0;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a.push_back(i);
	while(a.size()>3){
		int sz=a.size();
//		printf("<a>  ");
//		for(int i=0;i<sz;i++)printf("%d ",a[i]);
//		pc(10);
		for(int i=0;;i+=4){
			if(i+3>=sz)break;
			q1.push_back(a[i+1]);
			q1.push_back(a[i+3]);
			q2.push_back(a[i+2]);
			q2.push_back(a[i+3]);
		}
		int A=query(q1),B=query(q2);
		q1.resize(0),q2.resize(0);
		for(int i=0;;i+=4){
			if(i+3>=sz){
				for(int j=i;j<sz;j++)_a.push_back(a[j]);
				break;
			}
			if(!(A==1&&B==1))_a.push_back(a[i]);
			if(!(A==0&&B==1))_a.push_back(a[i+1]);
			if(!(A==1&&B==0))_a.push_back(a[i+2]);
			if(!(A==0&&B==0))_a.push_back(a[i+3]);
		}
		a=_a,_a.resize(0);
	}
	if(a.size()==1)answer(a[0]);
	else if(a.size()==2){
		if(!answer(a[0]))answer(a[1]);
	}
	else{
		q1.push_back(a[0]),q1.push_back(a[1]);
		if(!query(q1)){
			if(!answer(a[2])){
				q2.push_back(a[0]);
				if(query(q2))answer(a[0]);
				else answer(a[1]);
			}
		}
		else{
			if(!query(q1)){
				if(!answer(a[2])){
					q2.push_back(a[0]);
					if(query(q2))answer(a[0]);
					else answer(a[1]);
				}
			}
			if(!answer(a[0]))answer(a[1]);
//			q2.push_back(a[0]);
//			if(query(q2)){
//				if(!answer(a[0]))answer(a[1]);
//			}
//			else{
//				if(!answer(a[1])){
//					if(!query(q2))answer(a[2]);
//					else{
//						if(query(q2))answer(a[0]);
//						else answer(a[2]);
//					}
//				}
//			}
		}
	}
//	for(unsigned i=0;i<a.size();i++)printf("%d ",a[i]);
//	pc(10);
	return 0;
}


