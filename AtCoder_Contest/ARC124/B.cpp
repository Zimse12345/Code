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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],b[N],ans[N],cnt;
map<int,int> m,t;

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		b[i]=read();
		if(!m.count(b[i]))m[b[i]]=1;
		else ++m[b[i]];
	}
	
	for(int i=1;i<=n;i++){
		t=m,--t[b[i]];
		int x=a[1]^b[i],y=1;
		for(int j=2;j<=n;j++){
			int to=x^a[j];
			if((!t.count(to))||t[to]==0){
				y=0;
				break;
			}
			else --t[to];
		}
		if(y)ans[++cnt]=x;
	}
	sort(ans+1,ans+cnt+1);
//	for(int i=1;i<=cnt;i++)if(i!=1&&ans[i]==ans[i-1])--cnt;
//	printf("%lld\n",cnt);
	int res=0;
	for(int i=1;i<=cnt;i++)if((i==1)||(ans[i]!=ans[i-1]))++res;
	printf("%lld\n",res);
	for(int i=1;i<=cnt;i++)if((i==1)||(ans[i]!=ans[i-1]))printf("%lld\n",ans[i]);
	return 0;
}
