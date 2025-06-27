#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6,P=1000003;
int T,n,m;
long long ans;
vector<int> a[N],b[N];

struct HashTable{
    int hd[P],nxt[N],tot,val1[N],val2[N],stk[N],top;

    inline void ins(const int p,const int v){
        int h1=p%P;
        if(h1<0)h1+=P;
        int h2=p;
        int pos=hd[h1];
        if(!pos)stk[++top]=h1;
        while(pos&&val1[pos]!=h2)pos=nxt[pos];
        if(pos&&val1[pos]==h2)val2[pos]+=v;
        else nxt[++tot]=hd[h1],hd[h1]=tot,val1[tot]=h2,val2[tot]=v;
        return;
    }

    inline int qry(const int p){
        int h1=p%P;
        if(h1<0)h1+=P;
        int h2=p;
        int pos=hd[h1];
        while(pos&&val1[pos]!=h2)pos=nxt[pos];
        if(val1[pos]==h2)return val2[pos];
        return 0;
    }

    inline void clear(){
        while(top)hd[stk[top--]]=0;
        tot=0;
        return;
    }
}ht;

signed main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i].resize(m+1);
            for(int j=1;j<=m;j++){
                char c=getchar();
                while(c!='.'&&c!='#')c=getchar();
                if(c=='.')a[i][j]=1;
                else a[i][j]=-1;
            }
        }
        if(n>m){
            for(int i=1;i<=m;i++){
                b[i].resize(n+1);
                for(int j=1;j<=n;j++)b[i][j]=a[j][i];
            }
            for(int i=1;i<=m;i++){
                a[i].resize(n+1);
                for(int j=1;j<=n;j++)a[i][j]=b[i][j];
            }
            swap(n,m);
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++)a[i][j]+=a[i-1][j];
        }
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                ht.clear();
                ht.ins(0,1);
                for(int i=1,s=0;i<=m;i++){
                    int v=a[r][i];
                    if(l>1)v-=a[l-1][i];
                    s+=v;
                    ans+=ht.qry(s);
                    ht.ins(s,1);
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}


