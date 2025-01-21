#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n;
char s[N],t[N];

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        scanf("%s",t+1);
        n=strlen(s+1);
        s[0]=t[1];
        int p=1,pc=0,ans=0;
        for(int l=1;l<=n;){
            int r=l;
            while(r<n&&t[r+1]==t[l])++r;
            int len=r-l+1;
            int c=0;
            while(p<=n&&pc<len){
                if(s[p]==t[l]){
                    ++pc;
                    if(s[p-1]!=t[l]&&p!=l)++ans;
                }
                else ++c;
                ++p;
            }
            if(pc<len||s[p]==t[l]){
                ans=-1;
                break;
            }
            pc=c;
            if(pc)s[p-1]=t[r+1];
            l=r+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}


