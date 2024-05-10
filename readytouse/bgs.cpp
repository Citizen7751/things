#include <time.h>
#include <stdlib.h>

#include "bgs.hpp"

namespace BogoSort {

	int is_sorted(dvec& v) {
		for (int i = 1; i<v.size(); i++)
			if (v[i-1] > v[i]) return 0;
		return 1;
	}

	void mix(dvec& v) {

		int i1, i2;
		srand(time(NULL));

		for (int i = 0; i < v.size(); i++) {
			i1 = rand()%v.size();
			i2 = rand()%v.size();
			std::swap(v[i1], v[i2]);
		}
	}

	void Sort(dvec& v) {
		while(!is_sorted(v)) mix(v);
	}
}