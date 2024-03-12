#include <iostream>
#include "Astghik.h"
using namespace vhuk;

int main(){
	FrankList<int> ob = {5, 6, 7, 11, 8, 9};
	std::cout << ob << std::endl;
	ob.push_back(75);
	std::cout << ob << std::endl;
	ob.push_front(97);
	std::cout << ob << std :: endl;
	ob.insert(ob.begin(), 5ull, 11);
	std::cout << ob << std :: endl;
//	ob.remove(11);
	ob.rfind(6);
	ob.print(1);
	std::cout << ob << std :: endl;
}
