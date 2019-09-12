/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Meghan Elyse Hom
 * Date        : September 3rd, 2019
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit) : is_prime_{new bool[limit + 1]}, limit_{limit} {
        sieve();
    }

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    inline int num_primes() const {
        return num_primes_;
    }
	
	// Can have up to 80 characters on a line
	// Code to display the primes in the format specified in the document
    void display_primes() const {
        cout << endl << "Number of primes found: " << num_primes_ << endl;
		cout << "Primes up to " << limit_ << ":" << endl;
		
		// To find the width of the maximum prime value and how many primes you can fit on a row
		const int maximum_prime_width = num_digits(max_prime_);
		const int number_of_primes_per_row = 80 / (maximum_prime_width + 1);
		
		if(num_primes_ <= number_of_primes_per_row){
			for(int n = 0; n <= limit_; n++){
				if(is_prime_[n]){
					if(n != max_prime_){
						cout << n << " ";
					}
					else cout << n << endl;
				}
			}
		}
		else{
			for(int p = 0, counter = 1; p <= limit_; p++){
				if(is_prime_[p] == true){
					if(counter != number_of_primes_per_row)
						if(p != max_prime_){
							cout << setw(maximum_prime_width) << p << " ";
							counter = counter + 1;
						}
						else{
							cout << setw(maximum_prime_width) << p;
							counter++;
						}
						else{
							cout << setw(maximum_prime_width) << p << endl;
							counter = 1;
						}
					
				}
			}			
		}
    }

private:
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;
	
	// Count the number of primes found
    int count_num_primes() const {
        int m = 0;
		for(int i = 2; i <= limit_; i++){
			if(is_prime_[i]){
				m++;
			}
		}
		return m;
    }
	
	// Determine how many digits are in an integer
    int num_digits(int num) const {
        int _digits_ = 0;
		while(num != 0){
			num = num / 10;
			_digits_++;
		}
		return _digits_;
    }

    void sieve() {
        for(int i = 2; i <= limit_; i++){
			is_prime_[i] = true;
        	for(int i = 2; i < sqrt(limit_); i++){
				if(is_prime_[i]){
        			for(int j = pow(i, 2.0); j <= limit_; j = j + i){
        				is_prime_[j] = false;
        			}
        		}
        	}
        }
		num_primes_ = count_num_primes();
		
		for(int k = limit_; k >= 2; k--){
			if(is_prime_[k]){
				max_prime_ = k;
				break;
			}
		}
    }
};

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }
	
	// Produces the desired output
    PrimesSieve m(limit);
	m.display_primes();
    return 0;
}
