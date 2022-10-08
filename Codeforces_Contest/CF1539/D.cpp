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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){
	int __x=0,__y=1;char __c=' ';
	while(__c<'0'||__c>'9'){__c=getchar();if(__c=='-'){__y=-1,__c=getchar();break;}}
	while(__c>='0'&&__c<='9')__x=__x*10+__c-'0',__c=getchar();
	return __x*__y;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;

struct itm{
	int a,b;
	itm(int a=0,int b=0):a(a),b(b){}
	bool operator <(const itm& A)const{return b<A.b;}
}s[N];
int n,sum,c;

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		int a=read(),b=read();
		s[i]=itm(a,b);
	}sort(s+1,s+n+1);
	
	int L=1,R=n;
	while(L<=R){
		if(sum>=s[L].b)c+=s[L].a,sum+=s[L].a,++L;
		else{
			int k=min(s[L].b-sum,s[R].a);
			sum+=k,c+=k*2,s[R].a-=k;
			if(s[R].a==0)--R;
		}
	}
	printf("%lld\n",c);
	return 0;
}

