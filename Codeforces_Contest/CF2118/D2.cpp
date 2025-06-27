#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6,inf=1e18;
int T,n,k,p[N],d[N],q,m1,m2,f[N],P[N],len;
map<int,int> mp1,mp2,mp;
set<int> L[N],R[N];

inline int Mod(int x){
    x%=k;
    if(x<0)x+=k;
    return x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>p[i];
        for(int i=1,x=0;i<=n;i++){
            cin>>d[i];
            mp[p[i]]=i;
            x=Mod(d[i]+p[i]);
            if(!mp1[x]){
                mp1[x]=++m1;
                L[m1].insert(-inf);
                L[m1].insert(inf);
            }
            L[mp1[x]].insert(p[i]);
//            printf("L(%lld %lld)\n",x,p[i]);
            x=Mod(d[i]-p[i]);
            if(!mp2[x]){
                mp2[x]=++m2;
                R[m2].insert(-inf);
                R[m2].insert(inf);
            }
            R[mp2[x]].insert(p[i]);     
//            printf("R(%lld %lld)\n",mp2[x],p[i]);
        }
        cin>>q;
        while(q--){
            int x=0,t=0,o=1,ans=0;
            cin>>x;
            --x,--t;
            len=0;
            while(1){
//                printf("    %lld %lld %lld\n",x,t,o);
                if(o){
                    int y=Mod(t-x);
                    
                    if(!mp2[y]){
                        ans=1;
                        break;
                    }
                    y=mp2[y];
                    set<int>::iterator it=R[y].upper_bound(x);
//                    printf("y=%lld *it=%lld\n",y,*it);
                    if(*it==inf){
                        ans=1;
                        break;
                    }
                    t+=*it-x,x=*it,o^=1;
                    int u=mp[*it]*2+o;
                    P[++len]=u;
                    if(f[u]!=0)break;
                    f[u]=-1;
                }
                else{
                    int y=Mod(t+x);
                    if(!mp1[y]){
                        ans=1;
                        break;
                    }
                    y=mp1[y];
                    set<int>::iterator it=L[y].lower_bound(x);
                    --it;
                    if(*it==-inf){
                        ans=1;
                        break;
                    }
                    t+=x-*it,x=*it,o^=1;
                    int u=mp[*it]*2+o;
                    P[++len]=u;
                    if(f[u]!=0)break;
                    f[u]=-1;
                }
            }
//            for(int i=1;i<=len;i++)printf("  %lld %d\n",P[i],f[P[len]]==-1?-1:1);
            if(f[P[len]]!=-1||ans==1){
                for(int i=1;i<=len;i++)f[P[i]]=1;
                printf("YES\n");
            }
            else{
                for(int i=1;i<=len;i++)f[P[i]]=-1;
                printf("NO\n");
            }
        }
        for(int i=1;i<=m1;i++)L[i].clear();
        for(int i=1;i<=m2;i++)R[i].clear();
        m1=m2=0;
        mp1.clear(),mp2.clear(),mp.clear();
        for(int i=1;i<=n*2;i++)f[i]=0;
//        printf("\n\n\n\n");
    }
    return 0;
}


