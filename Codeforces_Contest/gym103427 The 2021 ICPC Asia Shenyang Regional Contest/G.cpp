#include <bits/stdc++.h>
using namespace std;

const int N=1024;
int n,m,M,a[N],lst[N*N],mp[N],sum[N][32],pre[N][32],T;
char str[N];

struct Str{
    vector<int> v;
    int pos;
    Str(int pos=0):pos(pos){}
    bool operator < (const Str& _)const{
        if(!v.size())return true;
        for(unsigned i=0;i<v.size();i++){
            if(v[i]<_.v[i])return true;
            if(v[i]>_.v[i])return false;
        }
        if(T)return pos>_.pos;
        return false;
    }
}f[N*N];

signed main(){
    cin>>n;
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)a[i]=str[i]-'a';
    sort(a+1,a+n+1);
    a[0]=-1;
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1])mp[a[i]]=m++;
    M=(1<<m);
    for(int i=1;i<=n;i++){
        a[i]=mp[str[i]-'a'];
        for(int j=0;j<m;j++)pre[i][j]=pre[i-1][j],sum[i][j]=sum[i-1][j];
        pre[i][a[i]]=i,++sum[i][a[i]];
    }
    lst[0]=n+1;
    for(int i=n,z=0;i>=1;i--){
        z|=(1<<a[i]);
        if(!lst[z])lst[z]=i;
    }
    for(int i=M-1;i>=0;i--){
        for(int j=0;j<m;j++)lst[i]=max(lst[i],lst[i|(1<<j)]);
    }
    for(int i=1;i<M;i++){
        Str F;
        int J=m,p=lst[M-1-i]-1;
        for(int j=0;j<m;j++)if(i&(1<<j)){
            int z=i^(1<<j);
            if(j==m||F<f[z])F=f[z],J=j;
            else if(!(f[z]<F)){
                int s1=sum[p][j]-sum[f[z].pos][j],s2=sum[p][J]-sum[f[i^(1<<J)].pos][J];
                if(s1>s2||(s1==s2&&pre[p][j]<pre[p][J]))F=f[z],J=j;
            }
        }
        F.v.push_back(sum[p][J]-sum[f[i^(1<<J)].pos][J]),F.pos=pre[p][J];
        f[i]=F;
    }
//    for(int i=0;i<M;i++){
//        for(int j=0;j<m;j++)if(!(i&(1<<j))){
//            int z=i|(1<<j),p=lst[M-1-z]-1;
//            Str F=f[i];
//            F.v.push_back(sum[p][j]-sum[f[i].pos][j]),F.pos=pre[p][j];
//            if(f[z]<F)f[z]=F;
//        }
//    }
    for(int i=0;i<m;i++){
        for(int j=0;j<f[M-1].v[i];j++)printf("%c",'a'+(m-i-1));
    }
    printf("\n");
    return 0;
}


