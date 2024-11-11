#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,b[3][N],a[3][N],t[3][N],vis[N];
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
};
vector<node> p[N];
priority_queue<int> q;
int fv[N],fx[N],ansx[N],ansv[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            p[i].resize(0);
            vis[i]=0;
        }
        for(int i=0;i<3;i++){
            for(int j=1;j<=n;j++){
                cin>>b[i][j];
                a[i][b[i][j]]=j;
            }
            for(int j=1;j<=n;j++){
                t[i][j]=0;
                p[a[i][j]].push_back(node(i,j));
            }
        }
        q.push(-1),vis[1]=1;
        while(!q.empty()){
            int x=-q.top();
            q.pop();
            for(unsigned id=0;id<p[x].size();id++){
                int i=p[x][id].x,j=p[x][id].y;
                while(j>=1&&!t[i][j]){
                    if(!vis[a[i][j]]&&a[i][j]>x){
                        q.push(-a[i][j]);
                        vis[a[i][j]]=1;
                        fx[a[i][j]]=i;
                        fv[a[i][j]]=x;
                    }
                    t[i][j]=1,--j;
                }
            }
        }
        if(vis[n]){
            printf("YES\n");
            int x=n,m=0;
            while(x!=1){
                ++m;
                ansx[m]=fx[x],ansv[m]=x;
                x=fv[x];
            }
            printf("%d\n",m);
            for(int i=m;i>=1;i--){
                if(ansx[i]==0)printf("q ");
                if(ansx[i]==1)printf("k ");
                if(ansx[i]==2)printf("j ");
                printf("%d\n",ansv[i]);
            }
        }
        else printf("NO\n");
    }
    return 0;
}


