#include <iostream>
#include <cassert>

#define NDEBUG

//float div(float x, float y) {
//	assert(y != 0 && "Div on zero");
//	/*if (y == 0) {
//		std::cerr << "Div on zero";
//		std::exit(1);
//	}*/
//	return x / y;
//}

enum MEMORY_ERROR {OUT_OF_RANGE, EMPTY_DATA};
enum LOGIC_ERROR { UNCORRECT_DATA };

int getElem(int* mass, int arrsize, int index) {
	if (index >= arrsize || index < 0) {
		throw OUT_OF_RANGE;
	}
	if (mass == nullptr) {
		throw EMPTY_DATA;
	}
	if (mass[index] <= 0) {
		throw UNCORRECT_DATA;
	}
	return mass[index];
}

int main() {
	/*float a = 5, b = 0;
	float res = div(a, b);
	std::cout << res;*/

	int mass[5] = { 1,2,3,4,0 };
	int size = 5;
	try {
		std::cout << getElem(mass, size, 4);
	}
	catch (MEMORY_ERROR) {
		std::cerr << "Error in func getElem: try to get empty memory\n";
	}
	catch (LOGIC_ERROR) {
		std::cerr << "Error in func getElem: uncorrect logic data";
	}


}