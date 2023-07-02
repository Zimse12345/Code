#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m;
char s[N],l[N],r[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        cin>>m;
        n=strlen(s+1);
        scanf("%s %s",l+1,r+1);
        int p=0;
        for(int i=1;i<=m;i++){
            int mx=0;
            for(char c=l[i];c<=r[i];c++){
                int pos=n+1;
                for(int j=p+1;j<=n;j++)if(s[j]==c){
                    pos=j;
                    break;
                }
                mx=max(mx,pos);
            }
            p=mx;
        }
        if(p<=n)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}



