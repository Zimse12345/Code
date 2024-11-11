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
	scanf("%s",s+1);
	scanf("%s",t+1);
	int c0=0,c1=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') c0++;
		else c1++;
	}
	for(int i=1;i<n;i++){
		if(c0==0||c1==0){
			puts("NO");
			return; 
		}
		if(t[i]=='0') c1--;
		else c0--;
	}
	puts("YES");
	return;
}
signed main(){
	T=read();
	while(T--){
		solve();
	}
	return 0;
}
