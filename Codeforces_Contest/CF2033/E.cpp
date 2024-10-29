#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],c,vis[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        c=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            vis[i]=0;
        }
        for(int i=1;i<=n;i++)if(!vis[i]&&a[i]!=i&&a[a[i]]!=i){
            int s=0,p=i;
            while(!vis[p])vis[p]=1,p=a[p],++s;
            c+=(s-1)/2;
        }
        printf("%d\n",c);
    }
    return 0;
}


