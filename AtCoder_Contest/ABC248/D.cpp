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

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;

struct Var{vector<int> p;}var[N];
int n,m,a[N],L0,R0,e[N];
int t,l,r,x,y;

int main(){
	n=read();
	L0=0,R0=n+1;
	for(int i=0;i<=n;i++)e[i]=i;
	
	for(int i=1;i<=n;i++)a[i]=read(),var[a[i]].p.push_back(i);
	m=read();
	while(m--){
			l=read(),r=read(),x=read(),x=e[x];
			int L,R,_L=-1,_R=-1,s=var[x].p.size();
			
			if(s==0||var[x].p[0]>r||var[x].p[s-1]<l){
				printf("0\n");
				continue;
			}
			
			L=0,R=s-1;
			while(L<=R){
				int M=(L+R)>>1;
				if(var[x].p[M]>=l)_L=M,R=M-1;
				else L=M+1;
			}
			
			L=0,R=s-1;
			while(L<=R){
				int M=(L+R)>>1;
				if(var[x].p[M]<=r)_R=M,L=M+1;
				else R=M-1;
			}
			
			if(var[x].p[_L]<l||var[x].p[_R]>r||_R<_L){
				printf("0\n");
				continue;
			}
			printf("%d\n",_R-_L+1);
	}
	return 0;
}
