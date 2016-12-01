#include <iostream>
#include <string>
#include <cmath>
#include <climits>

class solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
	std::string result;
	result += std::to_string(numerator/denominator);
	int rest = numerator%denominator;
	if (rest == 0)
	    return result;
	else {
	    result += ".";
	    int n = 1;
	    const int maxN = 8;
	    while (n <= maxN && rest*int(pow(10,n))%denominator != 0)
		n++;
	    if (n <= maxN) {
		int q = rest*int(pow(10,n))/denominator;
		result += std::to_string(q);
	    }
	    else if (n > maxN) {
		n = 1;
		while ((int(pow(10,n))-1)%denominator != 0)
		    n++;
		int q = (int(pow(10,n))-1)/denominator*rest;
		result += "(";
		result += std::to_string(q);
		result += ")";
	    }
	}
	return result;
    }
};

int main() {
    // int num = 1, den = 2;
    // int num = 2, den = 1;
    // int num = 2, den = 3;
    int num = 2, den = 15;

    solution soln;
    std::string frac = soln.fractionToDecimal(num, den);
    std::cout << num << "/" << den << " = "
	      << frac << std::endl;
}
