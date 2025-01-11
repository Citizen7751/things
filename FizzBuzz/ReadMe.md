# Scallable FizzBuzz

I saw a fairy scallable way to implement the famous Fizzbuzz game, so I decided to hop on the train myself as well.
This implementation has configurations for:
- **Conditions** (*number* and *word* like: *3* and *"Fizz"*)
- **Upper** and **Lower Boundries**
- **Pace** - how many numbers should be skipped in one step

Also, you can choose which direction you want to iterate in.

I implemented it in both C and C++, but I find the C version to be much cleaner.

---
### Compile with GCC

Windows
```
g++ -o FizzBuzz.exe FizzBuzz.cpp -s -O3
```

Linux
```
g++ -o FizzBuzz FizzBuzz.cpp -s -O3
```

(Both programs are can be compiled with ```g++```, so this is why I showed only the C++ compile command.)
