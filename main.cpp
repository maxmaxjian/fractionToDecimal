#include <iostream>
#include <string>
// #include <cmath>
// #include <climits>
#include <vector>
#include <algorithm>

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
	    // int n = 1;
	    // const int maxN = 8;
	    // while (n <= maxN && rest*int(pow(10,n))%denominator != 0)
	    //     n++;
	    // if (n <= maxN) {
	    //     int q = rest*int(pow(10,n))/denominator;
	    //     result += std::to_string(q);
	    // }
	    // else if (n > maxN) {
	    //     n = 1;
	    //     while ((int(pow(10,n))-1)%denominator != 0)
	    //         n++;
	    //     int q = (int(pow(10,n))-1)/denominator*rest;
	    //     result += "(";
	    //     result += std::to_string(q);
	    //     result += ")";
	    // }
            
            std::vector<int> remainders{rest};
            int r = rest*10%denominator;
            while(r != 0 && find(remainders.begin(), remainders.end(), r) == remainders.end())
            {
                remainders.push_back(r);
                r = r*10%denominator;
            }
            std::vector<int> qs;
            std::transform(remainders.begin(), remainders.end(), std::inserter(qs, qs.end()),
                           [&](int i){
                               return i*10/denominator;
                           });
            if (r == 0)
                result += std::accumulate(qs.begin(), qs.end(), std::string(), [](const std::string &s, int i){
                    return s+std::to_string(i);
                });
            else {
                auto it = find(remainders.begin(), remainders.end(), r);
                int dist = std::distance(remainders.begin(), it);
                std::string temp = std::accumulate(qs.begin(), qs.end(), std::string(), [](const std::string &s, int i){
                    return s+std::to_string(i);
                });
                temp.insert(dist,"(");
                temp.append(")");
                result += temp;
            }
	}
	return result;
    }
};

int main() {
    // int num = 1, den = 2;
    // int num = 2, den = 1;
    // int num = 2, den = 3;
    int num = 1, den = 3;

    solution soln;
    std::string frac = soln.fractionToDecimal(num, den);
    std::cout << num << "/" << den << " = "
	      << frac << std::endl;
}
