#include <cstdio>
#include <cstring>

using namespace std;

int len[2000000];
char s[2000000][128];
char str[2000000];

bool InvisablE(char c){
	return c=='\n'||c=='\r'||c=='\t'||c==' ';
}

void dfs(int dep){
	int tag=0;
	while(1){
		char c;
		if(tag)c='<',tag=0;
		else c=getchar();
		while(InvisablE(c))c=getchar();
		if(c=='<'){
			c=getchar();
			if(c=='/'){
				while(c!='>'){
					if(c=='"'){
						c=getchar();
						while(c!='"')c=getchar();
					}
					c=getchar();
				}
				return;
			}
			else{
				++dep,len[dep]=0;
				while(!InvisablE(c)&&c!='>')s[dep][++len[dep]]=c,c=getchar();
				while(c!='>'){
					if(c=='"'){
						c=getchar();
						while(c!='"')c=getchar();
					}
					c=getchar();
				}
				if(s[dep][1]!='i')dfs(dep);
				--dep;
			}
		}
		else{
			int sz=0;
			while(c!='<')str[++sz]=c,c=getchar();
			while(sz&&InvisablE(str[sz]))--sz;
			if(sz&&(!(s[dep][1]=='s'&&(s[dep][2]=='c'||s[dep][2]=='t')))){
				for(int i=1;i<=dep;i++){
					if(i!=1)putchar('>');
					for(int j=1;j<=len[i];j++)putchar(s[i][j]);
				}
				putchar(':');
				for(int i=1;i<=sz;i++)putchar(str[i]);
				putchar('\n');
			}
			tag=1;
		}
		if(!dep)return;
	}
	return;
}

int main(){
//	freopen("1.in","r",stdin);
	dfs(0);
	return 0;
}

