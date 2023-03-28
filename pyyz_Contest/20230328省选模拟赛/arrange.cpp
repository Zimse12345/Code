#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

#define int long long

using namespace std;

inline int read(){
    int x=0,y=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')y=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
    return x*y;
}

const int N=100007;
int n,q;
int A[N],P[N],vis[N],pos[N],lcm[N],cnt;
char opt[16];
vector<int> s[N];

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

void rebuild(){
    cnt=0;
    for(int i=1;i<=n;i++)vis[i]=0,s[i].resize(0);
    for(int i=1;i<=n;i++)if(!vis[i]){
        int t=i;
        while(!vis[t])vis[t]=1,s[i].push_back(t),t=P[t];
        pos[++cnt]=i;
        int sz=s[i].size();
        if(cnt==1)lcm[cnt]=sz;
        else{
            int g=gcd(sz,lcm[cnt-1]);
            if(2000000000000000000/(lcm[cnt-1]/g)<sz)lcm[cnt]=2000000000000000000;
            else lcm[cnt]=lcm[cnt-1]/g*sz;
        }
    }
    return;
}

signed main(){
    // freopen("arrange.in","r",stdin);
    // freopen("arrange.out","w",stdout);
    
    n=read(),q=read();
    for(int i=1;i<=n;i++)A[i]=i,P[i]=i;
    int tag=0;
    while(q--){
        scanf("%s",opt+1);
        int x=read(),y=read();
        if(opt[1]=='s'){
            if(opt[6]=='a')swap(A[x],A[y]);
            else swap(P[x],P[y]);
            tag=0;
        }
        else{
            if(!tag){
                rebuild();
                tag=1;
            }
            int L=1,R=cnt,m=0;
            while(L<=R){
                int M=(L+R)/2;
                if(x%lcm[M]==y%lcm[M])L=M+1;
                else m=M,R=M-1;
            }
            if(!m)putchar('='),putchar('\n');
            else{
                int p=pos[m],sz=s[p].size();
                if(A[s[p][(x-1)%sz]]<A[s[p][(y-1)%sz]])putchar('<'),putchar('\n');
                else putchar('>'),putchar('\n');
            }
        }
    }
    return 0;
}


