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

using namespace std;

int read(){int qrx=0;char qrc=getchar();while(qrc<'0'||qrc>'9')qrc=getchar();
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx;}
inline void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e5+7,Mod=998244353,INF=2147483647;
int n,rt[N],ch[N*70][11],v[N*70],mx[N*70],tot;
char s[N];

signed main(){
	n=read();
	for(int i=1,ans=0;i<=n;i++){
		int op=read();
		scanf("%s",s+1);
		int m=strlen(s+1);
		if(op==3){
			rt[i]=rt[i-1];
			int a=read(),b=read(),c=read(),k=(1ll*a*abs(ans)+b)%c;
			int L=1,R=i-1;
			ans=-1;
			while(L<=R){
				int M=(L+R)>>1;
				int id=rt[M];
				for(int j=1;j<=m;j++)id=ch[id][s[j]-'a'];
				if(mx[id]>k)ans=M,R=M-1;
				else L=M+1;
			}
			printf("%d\n",ans);
		}
		else{
			int t=(op==1)?1:-1;
			rt[i]=++tot;
			int id=tot,_id=rt[i-1];
			for(int j=1;j<=m;j++){
				for(int k=0;k<10;k++)ch[id][k]=ch[_id][k];
				ch[id][s[j]-'a']=++tot,v[tot]=v[ch[_id][s[j]-'a']]+t;
				mx[tot]=max(mx[ch[_id][s[j]-'a']],v[tot]);
				id=tot,_id=ch[_id][s[j]-'a'];
			}
		}
	}
	return 0;
}

