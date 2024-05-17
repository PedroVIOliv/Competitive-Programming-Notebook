const int SZ = 1<<17;
// Dynamic Seg Tree
// Para inicializar: node<int> st
// É usada para os mesmos objetivos da seg tree normal, mas o query range e a quantidade de elementos é muito grande
// Apenas cria nodes quando necessário
template<class T> struct node {
	T val = 0; node<T>* c[2];
	node() { c[0] = c[1] = NULL; }
	// O(nlogn)
	void upd(int ind, T v, int L = 0, int R = SZ-1) { // add v
		if (L == ind && R == ind) { val += v; return; }
		int M = (L+R)/2;
		if (ind <= M) {
			if (!c[0]) c[0] = new node();
			c[0]->upd(ind,v,L,M);
		} else {
			if (!c[1]) c[1] = new node();
			c[1]->upd(ind,v,M+1,R);
		}
		val = 0; for (int i = 0; i < 2; ++i) if (c[i]) val += c[i]->val;
	}
	// Praticamente O(1)
	T query(int lo, int hi, int L = 0, int R = SZ-1) { // query sum of segment
		if (hi < L || R < lo) return 0;
		if (lo <= L && R <= hi) return val;
		int M = (L+R)/2; T res = 0;
		if (c[0]) res += c[0]->query(lo,hi,L,M);
		if (c[1]) res += c[1]->query(lo,hi,M+1,R);
		return res;
	}
	void UPD(int ind, node* c0, node* c1, int L = 0, int R = SZ-1) { // for 2D segtree
		if (L != R) {
			int M = (L+R)/2;
			if (ind <= M) {
				if (!c[0]) c[0] = new node();
				c[0]->UPD(ind,c0?c0->c[0]:NULL,c1?c1->c[0]:NULL,L,M);
			} else {
				if (!c[1]) c[1] = new node();
				c[1]->UPD(ind,c0?c0->c[1]:NULL,c1?c1->c[1]:NULL,M+1,R);
			}
		} 
		val = (c0?c0->val:0)+(c1?c1->val:0);
	}
};