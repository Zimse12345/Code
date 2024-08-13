#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,a[N],m;
char s[N];
map<char,int> mp;
map<int,char> _mp;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==0)a[i]=1000000001;
        }
        cin>>m;
        while(m--){
            scanf("%s",s+1);
            if((int)strlen(s+1)!=n){
                printf("NO\n");
                continue;
            }
            mp.clear();
            _mp.clear();
            int tag=1;
            for(int i=1;i<=n;i++){
                if(!mp[s[i]]){
                    if(!_mp[a[i]])mp[s[i]]=a[i],_mp[a[i]]=s[i];
                    else tag=0;
                }
                else if(mp[s[i]]!=a[i])tag=0;
            }
            if(tag)printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}


