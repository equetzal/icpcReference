#include <iostream>
#include <cstring>

using namespace std;
typedef long long int lli;

//nC2 con triangulo de pascal

lli c2[1000010];
lli mxN = 2;
lli comb2(lli n){
	c2[0] = 0;
	c2[1] = 0;
	c2[2] = 1;
	if(c2[n] != -1)
		return c2[n];
	for(lli i=mxN; i<n; i++){
		c2[i+1] = c2[i] + i;
	}
	mxN = n;
	return c2[n];
}

int main(){
	memset(c2,-1,1000010);

	cout << comb2(4) << endl;
	cout << comb2(6) << endl;
	cout << comb2(19) << endl;
}
