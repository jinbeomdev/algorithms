#include <iostream>
#include <cstdio>

#define __min(a,b) (((a) < (b)) ? (a) : (b))

using namespace std;
int RGB[3], n, r, g, b;
enum { R, G, B };
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int ir = RGB[R], ig = RGB[G], ib = RGB[B];
		cin >> r >> g >> b;
		RGB[R] = r + __min(ig, ib);
		RGB[G] = g + __min(ir, ib);
		RGB[B] = b + __min(ir, ig);
	}
	cout << __min(RGB[R], __min(RGB[G], RGB[B])) << endl;
	return 0;
}