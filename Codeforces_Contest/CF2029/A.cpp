#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			y=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*y;
}
const int INF=1e9;
int T,n,m,k,q,a[1000010],f[1000010][3];
int cnt,sum,ans,res;
bool flag,vis[1000010];
char s[1000010],t[1000010];
void init(){
	flag=0,cnt=sum=ans=res=0;
	for(int i=1;i<=n;i++){
		
	} 
	return;
}
void solve(){
	init();
	int l=read(),r=read(),k=read();
	int L=l,R=r;
	if(l*k>r){
		puts("0");
		return;
	}
	while(L!=R){
		int mid=(L+R+1)>>1;
		if(mid*k<=r){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	printf("%lld\n",(R-l+1));
	return;
}
signed main(){
	T=read();
	while(T--){
		solve();
	}
	return 0;
}
