//Lowest Common Ancestor

#define maxn 100000

struct node{
	int val;
	int lvl;
	int padres[log2(maxn)];
}node;

*nodo emparejar(*nodo n1, *nodo n2){
	int dif = n1->lvl - n2->lvl;
	int k = log2(dif)+1;
	for(int i=1; i<=k; i=<<1){
		if(i&dif){
			n2 = n2->padres[i];
		}
	}
	return n2;
}

*nodo lca(*nodo n1, *nodo n2){
	n1 = emparejar(n1,n2);
	if(n1 == n2)
		return n1;
	int k = log2(maxn);
	for(int i=1; i<k; i++){
		if(n1->padres[i] == n2->padreS[i])
			return lca(n1->padres[i-1], n2->padres[i-1]);
	}
}


