//9
lli power(lli b, lli e){
	lli ans = 1;
	while(e){
		if(e & 1) ans *= b;
		e >>= 1;
		b *= b;
	}
	return ans;
}

//14
lli powerMod(lli b, lli e, lli m){
	lli ans = 1;
	b %= m;
	if(e < 0){
		b = modularInverse(b, m);
		e *= -1;
	}
	while(e){
		if(e & 1) ans = (ans * b) % m;
		e >>= 1;
		b = (b * b) % m;
	}
	return ans;
}
