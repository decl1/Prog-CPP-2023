#include <iostream>
#include <math.h>

using namespace std;

class point {
private:
	int x, y;
public:
	point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	point(const point& _point) : x(_point.x), y(_point.y) {}
	float dist(const point& a) {
		return sqrt(pow((a.x-x), 2) + pow((a.y-y), 2));
	}
};

void main() {
	point a;
	point b(4,3);
	cout << a.dist(b);
}