struct SegmentTree {
	Node *stree;

	SegmentTree(int N){ //Tamaño de arreglo original
		stree = new Node[getSegmentTreeSize(N)];
		buildTree(1, 0, N - 1);
	}

	void buildTree(int nodo, int L, int R){
		if(L == R)
			stree[nodo].make_Node(arr[L]);
		else{
			int mid = (L + R)/2;
			int leftIdx = 2*nodo;
			int rightIdx = 2*nodo + 1;

			buildTree(leftIdx, L, mid);
			buildTree(rightIdx, mid+1, R);

			stree[nodo].merge(stree[leftIdx],tree[rightIdx]);
		}
	}

	Node query(int nodo, int L, int R, int i, int j){
		if(L >= i && R <= j)
			return stree[nodo];
		int mid = (L + R)/2;
		int leftIdx = 2*nodo;
		int rightIdx = 2*nodo + 1;

		if (j <= mid)
			return query(leftIdx, L, mid, i, j);
		if (i > mid)
			return query(rightIdx, mid+1, R, i, j);

		Node leftResult = query(leftIdx, L, mid, i, mid);
		Node rightResult = query(rightIdx, mid+1, R, mid+1, j);

		Node result;
		result.merge(leftResult, rightResult);
		return result;
	}

	void update(int nodo, int L, int R, int idx, int value){
		if(L == R){
			arr[idx] = value;
			stree[nodo].make_Node(value);
			return;
		}

		int mid = (L + R)/2;
		int leftIdx = 2*nodo;
		int rightIdx = 2*nodo + 1;

		if(idx <= mid)
			update(leftIdx, L, mid, idx, value);
		else
			update(rightIdx, mid+1, R, idx, value);
			stree[nodo].merge(stree[leftIdx], stree[rightIdx]);
	}

	int getSegmentTreeSize(int N){
		int size = 1;
		for(; size < N; size <<= 1);
			return size << 1;
	}
};
