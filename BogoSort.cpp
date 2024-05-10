#include <iostream>
#include <windows.h>	//Sleep	
#include <time.h>	//random -> time
#include <stdlib.h>	//random
#include <vector>

typedef std::vector<double> dvec;


namespace BogoSort {

	void print_elements(dvec& v) {
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << ' ';
		std::cout << '\n';
	}

	int is_sorted(dvec& v) {
		for (int i = 1; i<v.size(); i++) 
			if (v[i-1] > v[i]) return 0;
		return 1;
	}

	void mix_elements(dvec& v) {

		int i1, i2;
		srand(time(NULL));

		for (int i = 0; i < v.size(); i++) {
			
			i1 = rand()%v.size();	//index of the first chosen element
			i2 = rand()%v.size();	//index of the second chosen element
			
			std::swap(v[i1], v[i2]);
		}
	}

//----------------------------------------------------------------------------
// You can choose to just sort, or sort verbosely

	void Sort_Verbose(dvec& v, int& i) {
		while(!is_sorted(v)) {
			mix_elements(v);
			i++;
			print_elements(v);
			Sleep(300);
		}
	}

	void Sort_Quiet(dvec& v, int& i) {
		while(!is_sorted(v)) {
			mix_elements(v);
			i++;
		}
	}
}


int main(void) {
	
	dvec nums = {
		1, 8, 4, 3
	};
	
	int iterations = 0;

	BogoSort::Sort_Verbose(nums, iterations);
	//BogoSort::Sort_Quiet(nums, iterations);
	
	std::cout << "\nDone in " << iterations << " iteration(s).\n ";
	std::cin.get();
	return 0;
}
