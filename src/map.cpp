#include "map.hpp"


void me::map::dims(pair<int, int> d) {
	if (d.first < 0 || d.second < 0) return;
	_dims = d;
	const pair<pair<int, int>, pair<int, int>> x11 {{0, 0}, {32, 32}};
	const pair<pair<int, int>, pair<int, int>> xT {{64, 0}, {32, 32}};
	const pair<pair<int, int>, pair<int, int>> x33 {{0, 32}, {96, 96}};
	 
}