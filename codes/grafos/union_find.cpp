#include <iostream>

using namespace std;

//Tambien conocido como Disjoin Sets
struct UnionFind{
	int numSets, *padres, *numVer;

	UnionFind(int N) : numSets(N){//Numero de nodos
		padres = new int[N + 1];
		numVer = new int[N + 1];
		for(int i=0; i<=N; i++){
			padres[i] = i;
			numVer[i] = 1;
		}
	}

	int findSet(int x){
		if(x == padres[x])
			return x;
		return (padres[x] = findSet(padres[x]));
	}

	bool isSameSet(int x, int y){
		return findSet(x) == findSet(y);
	}

	void unionSet(int x, int y){
		int xRoot = findSet(x);
		int yRoot = findSet(y);
		if(!isSameSet(xRoot, yRoot)){
			numVer[yRoot] += numVer[xRoot];
			padres[xRoot] = yRoot;
			numSets--;
		}
	}

	int sizeOfSet(int x){
		return numVer[findSet(x)];
	}
};
