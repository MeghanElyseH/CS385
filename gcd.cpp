/***********************
* Name : gcd.cpp
* Author : Meghan Elyse Hom
* Version : 1.0
* Date : August 29, 2019
* Description : Computes the GCD of two command-line arguments
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
************************/
#include <iostream>
#include <sstream>
using namespace std;



int gcd_iterative(int m, int n){
	//If one number is 0, return the other number
	if(m == 0){
		return n;
	}
	if(n == 0){
		return m;
	}
	//account for negative integers
	if(m < 0){
		m = abs(m);
	}
	if(n < 0){
		n = abs(n);
	}
	//while loop
	while(m != n){
		if(m > n){
			m = m-n;
		}
		else{
			n = n-m;
		}
	}
	return m;
	}

int gcd_recursive(int m, int n){
	//Both numbers are the same so you can return either m or n
	if(m == n){
		return n;
	}
	//If one number is 0, return the other number
	if(m == 0){
		return n;
	}
	if(n == 0){
		return m;
	}
	//account for negative integers
	if(m < 0){
		m = abs(m);
	}
	if(n < 0){
		n = abs(n);
	}
	//The recursive call
	if(m > n){
		return(gcd_recursive(m-n, n));	
	}
	return(gcd_recursive(m, n-m));		
}
int main(int argc, char* argv[]) {
    int m, n;
    istringstream iss;
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer m> <integer n>" << endl;
        return 1;
    }
    iss.str(argv[1]);
    if ( !(iss >> m) ) {
        cerr << "Error: The first argument is not a valid integer." << endl;
        return 1;
    }
    iss.clear();
    iss.str(argv[2]);
    if ( !(iss >> n) ) {
        cerr << "Error: The second argument is not a valid integer." << endl;
        return 1;
    }
    cout << "Iterative: gcd(" << m << ", " << n << ") = " << gcd_iterative(m, n) << endl;
    cout << "Recursive: gcd(" << m << ", " << n << ") = " << gcd_recursive(m, n) << endl;
    return 0;
}