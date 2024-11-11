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
inline int calc(int x,int y){
	return (x<y)?1:(x>y)?-1:0;
}
void solve(){
	init();
	n=read();
	f[0][1]=f[0][2]=-INF;
	for(int i=1;i<=n;i++){
		a[i]=read();
		f[i][0]=f[i-1][0]+calc(f[i-1][0],a[i]);
		f[i][1]=max(f[i-1][0],f[i-1][1]);
		f[i][2]=max(f[i-1][1]+calc(f[i-1][1],a[i]),f[i-1][2]+calc(f[i-1][2],a[i]));
	} 
	printf("%lld\n",max(f[n][1],f[n][2]));
	return;
}
signed main(){
	T=read();
	while(T--){
		solve();
	}
	return 0;
}
