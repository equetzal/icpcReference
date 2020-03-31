#include <iostream>

using namespace std;

double f(double x){
	double ans;

	//ans = x*x*x-x-1.0;

	return ans;
}

double f_p1(double x){ //Primera derivada de x
	double ans;

	//ans = 3.0*x*x-1.0;

	return ans;
}

double newton_raphson(int it, double sol_prev){
	if(it == 100) //100 iteracion de aproximacion
		return sol_prev;

	double new_sol = sol_prev - (f(sol_prev)/f_p1(sol_prev));
	return newton_raphson(it+1, new_sol);
}

int main(){

	cout << newton_raphson(1, 1.0) << endl;

}
