//3
lli lcm(lli a, lli b){
	return b * (a / gcd(a, b));
}

//5
lli lcm(vector<lli> & nums){
	lli ans = 1;
	for(lli & num : nums) ans = lcm(ans, num);
	return ans;
}
