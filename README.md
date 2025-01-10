# BigNumbers_benchmark

This library benchmarks the execution time for different operations with different algorithms for calculating big numbers.

This document references cherubin library which is located here:

https://github.com/julienlargetpiet/Cherubin/

## Add Integers

Input:

- std::string x = "21685454520057057454344565656454";
- std::string x2 = "816854545200570574354534343";

Result:

"21686271374602258024918920190797"

For 100000 iterations:

- cherubin::addint is **8 ms** (uses only string and calculates unit by unit)

- addint1 is **45ms** (uses std::vector<unsigned int> and calculates 1000000000 by 1000000000)




