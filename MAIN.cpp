#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

//interval
#define a -7
#define b 1

//min accuracy
#define min_eps 1e-15 

//Storage for making tables
//Arguments: Absolute Error, Reminder Term
struct storage {
	int n;
	double AbsErr;
	double RemTerm;
};
//Initial
storage DB[6];
int DBcount = 1;

double ch(double eps) {

	double X = (a + b)/2;
	cout << X*X;
	printf("\n");
	cout << " X VALUE : " << X;
	printf("\n");
	double res = 1;//at first pass, the result variable(res) will store U1 value
	double prev = 1;
	int k = 1;
	while (abs(prev) > eps) {
		printf("\n%i", k);
		printf("\n");
		prev = (X*X*prev)/( 2 * k*(2 * k - 1));
		cout << " PREV : " << prev;
		printf("\n");
		res = res + prev;
		//char c = getchar();
		cout << " RESULT : " <<res;
		printf("\n");
		k++;
	}
	DB[DBcount].n = k-1;
	DB[DBcount].AbsErr = prev = (X*X*prev) / (2 * k*(2 * k - 1));
	DB[DBcount].RemTerm = cosh(X) - res;
	return res;

}

int main() {
	
	double answer = ch(0.01);

	double eps = 0.01;
	printf("	eps	|	n	| Absolute error | Remainder term|");
	/*for (eps; eps*0.001; eps < 0.0000000000001) {
		//printf("	",eps,"		|	",n,"	| ",Absolute error" | ",Remainder term"	|");
		ch(eps);
	}*/
	printf("\n%f", answer);
	printf("\n%i ", DB[1].n);
	printf("\n%d ", DB[1].AbsErr);
	printf("\n%d ", DB[1].RemTerm);
	char count = getchar();

}