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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;

int T,n,m,k,tot,_a[N],_b[N],x,y,z,ans,res,pre[N*N];
char a[N],b[N],Ans[N*2];

signed main(){
	T=read();
	while(T--){
		tot=0;
		int t=0;
		for(int i=0;i<26;i++)_a[i]=_b[i]=0;
		n=read(),m=read(),k=read();
		scanf("%s%s",a+1,b+1);
		for(int i=1;i<=n;i++)++_a[a[i]-'a'];
		for(int i=1;i<=m;i++)++_b[b[i]-'a'];
		while(n>0&&m>0){
			int A=0,B=0;
			for(int j=0;j<26;j++)if(_a[j]){A=j;break;}
			for(int j=0;j<26;j++)if(_b[j]){B=j;break;}
			if(tot==k)--m,tot=min(-1ll,tot-1),Ans[++t]=B,_b[B]--;
			else if(tot==-k)--n,tot=max(1ll,tot+1),Ans[++t]=A,_a[A]--;
			else{
				if(A<B)Ans[++t]=A,_a[A]--,tot=max(1ll,tot+1),n--;
				else if(A>B)Ans[++t]=B,_b[B]--,tot=min(-1ll,tot-1),m--;
				else{
					if(n==_a[A]&&_a[A]<_b[B])Ans[++t]=A,_a[A]--,tot=max(1ll,tot+1),n--;
					else if(m==_b[B]&&_b[B]<=_a[A])Ans[++t]=B,_b[B]--,tot=min(-1ll,tot-1),m--;
					else{
						if(_a[A]>_b[B])Ans[++t]=A,_a[A]--,tot=max(1ll,tot+1),n--;
						else Ans[++t]=B,_b[B]--,tot=min(-1ll,tot-1),m--;
					}
				}
			}
		}
		for(int i=1;i<=t;i++)printf("%c",Ans[i]+'a');
		printf("\n");
	}
	return 0;
} 
