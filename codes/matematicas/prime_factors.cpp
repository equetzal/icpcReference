#include <map>
#include <cmath>

map<lli,lli>  primeFactors(lli n){
    map<lli,lli> primeFrec;
    
    while(!(n&1)){ 
    	primeFrec[2]++;
        n = n/2; 
    } 

    lli sq = sqrt(n);
    for(lli i = 3; i <= sq+2; i += 2){ 
        while (n%i == 0){
        	primeFrec[i]++; 
            n = n/i; 
        } 
    } 

    if(n > 2)
    	primeFrec[n]++; 
    
    return primeFrec;
}
