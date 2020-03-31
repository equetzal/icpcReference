//nCk n<=10^5

#include <iostream>

using namespace std;

typedef long long int lli;

lli fact[100005];

void calcFact(lli M){ //Factorial Modulo M
	fact[0] = 1;
	for(lli i=1; i<100001; i++){
		fact[i] = (fact[i-1] * (i%M))%M;
	}
	return;
}

lli inv(lli b, lli M){
	lli u = 1, x = 0, s = b, t = M;
	while(s){
		lli q = t/s;
		swap(x -= u * q, u);
		swap(t -= s * q, s);
	}
	return (x %= M) >= 0 ? x : x + M;
}

lli combinatoria(lli n, lli k, lli M){ //nCk % M
	lli denom = (fact[k] * fact[n-k])%M;
	return (fact[n] * inv(denom,M))%M;
}

int main(){
	//M Tiene que ser primo para que tenga inverso modular. 
	calcFact(986444689);
	cout << combinatoria(9,3,986444689) << endl;
	
	return 0;
}
