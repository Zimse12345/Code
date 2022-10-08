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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int T,n,t[30],nd[30],p[30];
char s[N],ans[N];

int main(){
	T=read();
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		int c=0,Y=1,tot=0;
		for(int i=0;i<=27;i++)t[i]=0,nd[i]=0;
		for(int i=1;i<=n;i++)++t[s[i]-'a'+1];
		for(int i=0;i<=27;i++)if(t[i])++c;
		int L1=0,L2=0,R1=0,R2=0;
		
		for(int i=1;i<=c;i++){
			for(int i=1;i<=26;i++)p[i]=0;
			int d=i,y=1,ad=0;R1=n;
			while(n){
				int a=s[n]-'a'+1;;
				if((!ad)&&(!nd[a])){
					if((t[a]%(c-i+1))!=0){y=0;break;}
					nd[a]=t[a]/(c-i+1),ans[i]=s[n],ad=1,tot+=nd[a];
				}--n;
				++p[a];
				if(p[a]>nd[a]){y=0;break;}
				if(p[a]==nd[a])--d;
				if(d==0)break;
			}L1=n+1;
			
			if(i>1){
//				printf("[%d %d] {%d %d}\n",L1,R1,L2,R2);
				int e=L1;
				for(int i=L2;i<=R2;i++){
					while(e<=R1&&s[e]!=s[i])++e;
					if(i==R2&&e<=R1)break;
					++e;
					if(e>R1){y=0;break;}
				}
			}
			
			if(d&&n==0)y=0;
			if(y==0){Y=0;break;}
			
			L2=L1,R2=R1;
		}
		
		if(!Y){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=tot;i++)printf("%c",s[i]);
		printf(" ");
		for(int i=c;i>=1;i--)printf("%c",ans[i]);
		printf("\n");
	}
	return 0;
}

