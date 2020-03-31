#include <cmath>

using namespace std;

typedef long long int lli;

lli inv(lli b, lli M){
	lli u = 1, x = 0, s = b, t = M;
	while (s){
		lli q = t/s;
		swap(x -= u * q, u);
		swap(t -= s * q, s);
	}
	return (x %= M) >= 0 ? x : x + M;
}

lli pow(lli a, lli b, lli M){
	lli x = 1;
	for (; b > 0; b >>= 1)
	{
		if (b & 1)
			x = (a * x) % M;
		a = (a * a) % M;
	}
	return x;
}

lli c1(lli n, lli p, lli pk){
	if(n == 0)
		return 1;
	
	lli i, k, ans = 1;
	for(i = n%pk, i = 2; i <= k; i++){
		if(i%p)
			ans = ans*i%pk;
	}
	
	ans = pow(ans, n/pk, pk);
	
	for(k = n%pk, i=2; i <= k; i++){
		if(i%p)
			ans = ans*i%pk;
	}
	
	return ans*c1(n/p, p, pk)%pk;
}

lli cal(lli n, lli m, lli p, lli pi, lli pk){
	lli i, k=0, a, b, c, ans;
	
	a = c1(n, pi, pk);
	b = c1(m, pi, pk);
	c = c1(n-m, pi, pk);
	
	 for(i=n; i; i/=pi)
		 k += i/pi;
	 for(i=m; i; i/=pi)
		 k -= i/pi;
	 for(i=n-m; i; i/=pi)
		 k -= i/pi;
	 
	 ans = a*inv(b,pk)%pk * inv(c,pk)%pk * pow(p,k,pk)%pk;
	 return ans*(p/pk)%p * inv(p/pk, pk)%p;
}

lli comb(lli n, lli m, lli p){ //nCm %p
	lli ans=0, x,i,k;
	for(x = p, i=2; x>1; i++){
		if(x%i == 0){
			for(k=1; x%i == 0; x/=i)
				k *= i;
			ans = (ans + cal(n, m, p, i, k))%p;
		}
	}
	
	return ans;
}
