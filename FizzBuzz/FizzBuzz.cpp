// ----- Compile -----
// Windows:g++ -o FizzBuzz.exe FizzBuzz.cpp -s -O3
// Linux: g++ -o FizzBuzz FizzBuzz.cpp -s -O3

#include <iostream> 
#include <vector>
#include <math.h>

struct cnd {
    int n;
    std::string word;
};

bool check_and_print(const std::vector<cnd>& Cons, const int& i) {
    bool div = false;
    for (auto c : Cons)
        if (i % c.n == 0) {
            div = true;
            std::cout << c.word;
        }
    return div;
}

//-------------------------------------------------------
// For scallability, edit these -------------------------
const int BEGIN = 100;
const int END = 1;
const int PACE = -1;

void add_conditions(std::vector<cnd>& Cons) {   //add more if you will...
    Cons.push_back(cnd{3, "Fizz"});
    Cons.push_back(cnd{5, "Buzz"});
    Cons.push_back(cnd{7, "Bizz"});
    Cons.push_back(cnd{9, "Fuzz"});
}
//-------------------------------------------------------
//-------------------------------------------------------

void FizzBuzz() {
    std::vector<cnd> Conditions;
    add_conditions(Conditions);

//boundries set like this are always within the range of the loop
    for (int i = BEGIN; i != END+(PACE/abs(PACE)); i += PACE) {
        if (!check_and_print(Conditions, i)) std::cout << i;
        std::cout << '\n';
    }
}

int main(void) {
    FizzBuzz();
    std::cin.get();
    return 0;
}
