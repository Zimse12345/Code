#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,k,a[N],tag;

signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    tag=1;
    for(int i=1;i<=n;i++)if(a[i]>m)tag=0;
    if(tag){
        printf("0\n");
        return 0;
    }
    
    tag=0;
    for(int x=1;x<=m;x++){
        int tx=0,p=1;
        for(int i=1;i<=n;i++){
            if(a[i]>=x)(tx+=1)%=k;
            if(!tx)continue;
            if(a[i]>m)p=0;
        }
        if(p){
            tag=1;
            break;
        }
    }
    if(tag){
        printf("1\n");
        return 0;
    }
    
    tag=0;
    for(int x=1;x<=m;x++){
        for(int y=x+1;y<=m;y++){
            int tx=0,ty=0,p=1;
            for(int i=1;i<=n;i++){
                if(a[i]>=x)(tx+=1)%=k;
                if(!tx)continue;
                if(a[i]>=y)(ty+=1)%=k;
                if(!ty)continue;
                if(a[i]>m)p=0;
            }
            if(p)tag=1;
        }
    }
    if(tag){
        printf("2\n");
        return 0;
    }
    
    tag=0;
    for(int x=1;x<=m;x++){
        for(int y=x+1;y<=m;y++){
            for(int z=y+1;z<=m;z++){
                int tx=0,ty=0,tz=0,p=1;
                for(int i=1;i<=n;i++){
                    if(a[i]>=x)(tx+=1)%=k;
                    if(!tx)continue;
                    if(a[i]>=y)(ty+=1)%=k;
                    if(!ty)continue;
                    if(a[i]>=z)(tz+=1)%=k;
                    if(!tz)continue;
                    if(a[i]>m)p=0;
                }
                if(p)tag=1;
            }
        }
    }
    if(tag)printf("3\n");
    else printf("Zombies are on your lawn\n");
    return 0;
}


