#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

const int N=1e2+7;
int n,t[N][N];
char s[N][N],ss[N];

bool sol(){
	int len=strlen(ss+1);
	for(int a=1;a<=4;a++)for(int b=1;b<=4;b++)if(b!=a){
		for(int c=1;c<=4;c++)if(c!=a&&c!=b){
			for(int d=1;d<=4;d++)if(d!=a&&d!=b&&d!=c){
				int k[5]={0,a,b,c,d},tag=1;
				for(int w=1;w<=len;w++)if(!t[k[w]][ss[w]-'a']){tag=0;break;}
				if(tag)return true;
			}
		}
	}
	return false;
}

signed main(){
	n=read();
	for(int i=1;i<=4;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=6;j++)t[i][s[i][j]-'a']=1;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",ss+1);
		if(sol())printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

