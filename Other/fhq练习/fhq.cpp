struct fhq{
	int rt,cnt;
	fhq(int rt=0,int cnt=0):rt(rt),cnt(cnt){}
	struct node{
		int l,r,v,ky,siz;
		node(int l=0,int r=0,int v=0,int ky=0,int siz=0):l(l),r(r),v(v),ky(ky),siz(siz){}
	}tree[N];
	void update(int id){tree[id].siz=tree[tree[id].l].siz+tree[tree[id].r].siz+1;}

	void split(int id,int x,int& l,int& r){
		if(!id){l=r=0;return;}
		if(tree[id].v<=x)l=id,split(tree[id].r,x,tree[id].r,r);
		if(tree[id].v>x)r=id,split(tree[id].l,x,l,tree[id].l);
		update(id);return;
	}

	int merge(int l,int r){
		if(l==0||r==0)return l+r;
		if(tree[l].ky<=tree[r].ky){tree[l].r=merge(tree[l].r,r),update(l);return l;};
		tree[r].l=merge(l,tree[r].l),update(r);return r;
	}

	int kth(int id,int k){
		if(k<=tree[tree[id].l].siz)return kth(tree[id].l,k);
		if(k>tree[tree[id].l].siz+1)return kth(tree[id].r,k-tree[tree[id].l].siz-1);
		return id;
	}
	
	void insert(int x){
		int l,r,p;
		split(rt,x,l,r),tree[++cnt]=node(0,0,x,rand(),1),rt=merge(l,merge(cnt,r));
		return;
	}
	
	void del(int x){
		int l,r,p;
		split(rt,x,l,r),split(l,x-1,l,p),p=merge(tree[p].l,tree[p].r),rt=merge(l,merge(p,r));
		return;
	}
	
	void rank(int x){
		int l,r,p;
		split(rt,x-1,l,r),printf("%d\n",tree[l].siz+1),rt=merge(l,r);
		return;
	}
	
	void pre(int x){
		int l,r,p;
		split(rt,x-1,l,r),printf("%d\n",tree[kth(l,tree[l].siz)].v),rt=merge(l,r);
		return;
	}
	
	void nxt(int x){
		int l,r,p;
		split(rt,x,l,r),printf("%d\n",tree[kth(r,1)].v),rt=merge(l,r);
		return;
	}
}A,B,C;
