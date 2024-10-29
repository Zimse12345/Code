#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;

class fhqTreap{
public:
    struct node{
        int l,r,v,ky,siz;
        node(int l=0,int r=0,int v=0,int ky=0,int siz=0):
            l(l),r(r),v(v),ky(ky),siz(siz){}
    };
    vector<node> t;
    int Root,Siz;
    
    inline void init(){
        srand(time(0));
        Root=Siz=0;
        t.push_back(node());
        return;
    }
    
    inline void update(int id){
        t[id].siz=t[t[id].l].siz+t[t[id].r].siz+1;
        return;
    }
    
    inline void split(int id,int x,int& l,int& r){
    	if(!id){l=r=0;return;}
    	if(t[id].v<=x){
    	    l=id;
            split(t[id].r,x,t[id].r,r);
        }
    	else{
    	    r=id;
            split(t[id].l,x,l,t[id].l);
        }
    	update(id);
        return;
    }
    
    inline void split_size(int id,int x,int& l,int& r){
    	if(!id){l=r=0;return;}
    	if(t[t[id].l].siz+1<=x){
    	    l=id;
            split(t[id].r,x-t[t[id].l].siz-1,t[id].r,r);
        }
    	else{
    	    r=id;
            split(t[id].l,x,l,t[id].l);
        }
    	update(id);
        return;
    }
    
    inline int merge(int l,int r){
    	if(!l||!r)return l+r;
    	if(t[l].ky<t[r].ky){
            t[l].r=merge(t[l].r,r),update(l);
            return l;
        }
    	t[r].l=merge(l,t[r].l),update(r);
        return r;
    }
    
    inline int kth(int id,int k){
    	if(k<=t[t[id].l].siz)return kth(t[id].l,k);
    	if(k>t[t[id].l].siz+1)return kth(t[id].r,k-t[t[id].l].siz-1);
    	return id;
    }
    
    inline int kth(int k){
    	return t[kth(Root,k)].v;
    }
    
    inline void insert(int x){
        int l,r;
        t.push_back(node(0,0,x,rand(),1)),++Siz;
        split(Root,x,l,r);
        Root=merge(merge(l,Siz),r);
        return;
    }
    
    inline void erase(int x){
        int l,r,mid;
        split(Root,x,l,r);
        split(l,x-1,l,mid);
        Root=merge(merge(l,t[mid].l),merge(t[mid].r,r));
        return;
    }
    
    inline int rank(int x){
        int l,r,res;
        split(Root,x-1,l,r);
        res=t[l].siz+1;
        Root=merge(l,r);
        return res;
    }
    
    inline int pre(int x){
        int l,r,res;
        split(Root,x-1,l,r);
        res=t[kth(l,t[l].siz)].v;
        Root=merge(l,r);
        return res;
    }
    
    inline int nxt(int x){
        int l,r,res;
        split(Root,x,l,r);
        res=t[kth(r,1)].v;
        Root=merge(l,r);
        return res;
    }
};
fhqTreap tree;

signed main(){
    tree.init();
	int n;
	cin>>n;
	for(int i=1,op,x;i<=n;i++){
		cin>>op>>x;
		if(op==1)tree.insert(x);
		if(op==2)tree.erase(x);
		if(op==3)printf("%d\n",tree.rank(x));
		if(op==4)printf("%d\n",tree.kth(x));
		if(op==5)printf("%d\n",tree.pre(x));
		if(op==6)printf("%d\n",tree.nxt(x));
	}
    return 0;
}


