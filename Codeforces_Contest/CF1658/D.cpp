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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=8e6+7,Mod=998244353,INF=1e9+7;
int T,l,r,a[N],n;
int ch[N][2],tot,s[N];

void add(int x,int t){
	int id=0;
	for(int i=18;i>=0;i--){
		s[id]+=t;
		if(x&(1<<i))id=ch[id][1];
		else id=ch[id][0];
	}
	s[id]+=t;
	return;
}

signed main(){
	T=read();
	while(T--){
		for(int i=0;i<=tot;i++)ch[i][0]=ch[i][1]=s[i]=0;
		tot=0;
		int ans=0;
		l=read(),r=read();
		n=r-l+1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			int id=0;
			for(int j=18;j>=0;j--){
				
				++s[id];//printf("{{%d %d}}\n",id,s[id]);
				if(a[i]&(1<<j)){
//					printf("   {%d %d %d}\n",a[i],j,1);
//					printf("R");
					if(!ch[id][1])ch[id][1]=++tot;
					id=ch[id][1];
				}
				else{
//					printf("L");
//					printf("   {%d %d %d}\n",a[i],j,0);
					if(!ch[id][0])ch[id][0]=++tot;
					id=ch[id][0];
				}
			}
			++s[id];
//			printf("\n");
		}
		for(int i=1;i<=n;i++){
			int x=a[i]^r;
//			add(a[i],-1);
			int p=0,id=0,p2=0;
			for(int j=18;j>=0;j--){
//				printf("   {%d %d %d %d %d}\n",j,s[ch[id][0]],s[ch[id][1]],ch[id][0],ch[id][1]);
				if(!(x&(1<<j))){
//					printf("<%d %d>\n",j,s[ch[id][0]]);
					if(ch[id][0]&&s[ch[id][0]]>0)id=ch[id][0];//printf("A");
					else p|=(1<<j),id=ch[id][1];//printf("B");
				}
				else{
					if(ch[id][1]&&s[ch[id][1]]>0)id=ch[id][1];//printf("C");
					else p|=(1<<j),id=ch[id][0];//printf("D");
				}
			}
			id=0;
			for(int j=18;j>=0;j--){
//				printf("   {%d %d %d %d %d}\n",j,s[ch[id][0]],s[ch[id][1]],ch[id][0],ch[id][1]);
				if((x&(1<<j))){
//					printf("<%d %d>\n",j,s[ch[id][0]]);
					if(ch[id][0]&&s[ch[id][0]]>0)p2|=(1<<j),id=ch[id][0];//printf("A");
					else id=ch[id][1];//printf("B");
				}
				else{
					if(ch[id][1]&&s[ch[id][1]]>0)p2|=(1<<j),id=ch[id][1];//printf("C");
					else id=ch[id][0];//printf("D");
				}
			}
//			printf("[%d %d %d %d]\n",i,x,p,p2);
			if(p==l&&p2==r){
				printf("%d\n",x);ans=x;
				break;
			}
//			add(a[i],1);
		}
		for(int i=1;i<=n;i++)a[i]^=ans;
		sort(a+1,a+n+1);
//		for(int i=1;i<=n;i++)printf("%d ",a[i]);
//		printf("\n");
	}
	return 0;
}

