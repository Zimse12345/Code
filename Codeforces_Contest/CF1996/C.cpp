#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,q,pre[N][27];
char a[N],b[N];

inline int _abs(int x){
    return x<0?-x:x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>q;
        scanf("%s",a+1);
        scanf("%s",b+1);
        for(int i=1;i<=n;i++){
            for(int j=0;j<26;j++)pre[i][j]=pre[i-1][j];
            ++pre[i][a[i]-'a'];
            --pre[i][b[i]-'a'];
        }
        while(q--){
            int l,r,ans=0;
            cin>>l>>r;
            for(int j=0;j<26;j++)ans+=_abs(pre[r][j]-pre[l-1][j]);
            printf("%d\n",ans/2);
        }
    }
    return 0;
}


