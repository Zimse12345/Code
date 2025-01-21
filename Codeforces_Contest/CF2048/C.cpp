#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,ans[N],a[N];
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        for(int i=1;i<=n;i++)ans[i]=0;
        s[n+1]='0';
        int L=1,R=1;
        for(int i=1;i<=n;i++){
            int f=n-i;
            for(int j=1;j<=n;j++){
                if(s[j]=='0')a[j]=0;
                else a[j]=1;
                if(j>f&&s[j-f]=='1')a[j]^=1;
            }
            int p=1;
            for(int j=f+1;j<n;j++){
                if(a[j]==1&&s[j-f]=='1')break;
                if(s[j-f]=='1')a[j]^=1;
                ++p;
            }
            int tag=0;
            for(int j=1;j<=n;j++){
                if(a[j]>ans[j]){
                    tag=1;
                    break;
                }
                if(a[j]<ans[j])break;
            }
            if(tag){
                for(int j=1;j<=n;j++)ans[j]=a[j];
                L=p,R=i;
            }
        }
        printf("%d %d %d %d\n",1,n,L,R);
    }
    return 0;
}


