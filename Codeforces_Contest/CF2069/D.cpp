#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,v[N],t[N];
char s[N]; 

signed main(){
    cin>>T;
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int l=1,r=n,ans=0;
        while(l<=r&&s[l]==s[r])++l,--r;
        if(l<r){
            for(char c='a';c<='z';c++)v[c]=t[c]=0;
            for(int i=l;i<=r;i++)++v[s[i]];
            ans=r-l;
            for(int i=l;i<=r;i++){
                ++t[s[i]];
                if(t[s[i]]*2>v[s[i]])break;
                ans=min(ans,r-i);
            }
            for(char c='a';c<='z';c++)t[c]=0;
            for(int i=r;i>=l;i--){
                ++t[s[i]];
                if(t[s[i]]*2>v[s[i]])break;
                ans=min(ans,i-l);
            }
            int pl=(l+r)/2,pr=pl+1;
            while(s[pl]==s[pr])--v[s[pl]],--v[s[pr]],--pl,++pr;
            if(s[(l+r)/2]==s[(l+r)/2+1]){
                int tag=1;
                for(char c='a';c<='z';c++)t[c]=0;
                for(int i=l;i<=pl;i++){
                    ++t[s[i]];
                    if(t[s[i]]*2>v[s[i]]){
                        tag=0;
                        break;
                    }
                }
                if(tag)ans=min(ans,pl-l+1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


