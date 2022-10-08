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

#define int long double

using namespace std;

inline signed read(){signed qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const signed N=1e5+7,Mod=998244353;
const int INF=1e18;
signed T,n,p;
int L,len[N],f[N],q[N],S[N],pre[N],ans[N],Len;
char s[N][40];

int F(signed id,int x){
	//f[id]+(x-S[A])^p
	int t=(x-S[id]);
	if(t<0)t=-t;
	int res=1;
	for(signed i=1;i<=p;i++){
		res*=t;
//		if(res>INF)break;
	}
	return f[id]+res;
}

int md(signed A,signed B){
	//(S[A],f[A],S[B],f[B])
	//min p b(p)<a(p)
	int L=0,R=Len,res=R+1;
	while(L<=R){
		int M=floor((L+R)/2);
		if(F(B,M)<=F(A,M))res=M,R=M-1;
		else L=M+1;
	}
	return res; 
}

signed main(){
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	T=read();
	while(T--){
		n=read(),L=read(),p=read(),Len=0;
		for(signed i=1;i<=n;i++)scanf("%s",s[i]+1),len[i]=strlen(s[i]+1),Len+=len[i]+1;
		signed l=1,r=1;
		q[1]=0;
		int sl=0;
		S[0]=1+L;
		for(signed i=1;i<=n;i++){
			sl+=1+len[i],S[i]=sl+1+L;
			while(l<r&&sl>=md(q[l],q[l+1]))++l;
			f[i]=F(q[l],sl),pre[i]=q[l];
			//printf("f[%lld]= %lld^%lld + %lld   <%lld>\n",i,(sl-S[q[l]]),p,f[q[l]],q[l]);
			while(l<r&&md(q[r-1],q[r])>=md(q[r],i))--r;
			q[++r]=i;
			//printf("[%lld %lld] f[%lld]=%lld pre=%lld\n",l,r,i,f[i],pre[i]); 
		}
		if(f[n]>INF){
			printf("Too hard to arrange\n");
			printf("--------------------\n");
			continue;
		}
		long long Ans=f[n];
		printf("%lld\n",Ans);
		signed t=n,tot=0;
		while(t)ans[++tot]=t,t=pre[t];
		ans[tot+1]=0;
		for(signed i=tot;i>=1;i--){
			for(signed j=ans[i+1]+1;j<=ans[i];j++){
				for(signed k=1;k<=len[j];k++)putchar(s[j][k]);
				if(j!=ans[i])putchar(' ');
			}
			putchar('\n');
		}
		printf("--------------------\n");
	}
	return 0;
}

