# Test driven development : Group2

## part 1: (pair A)

Driver: Joshua Gomes (jgomes14@umd.edu) 

Navigator: Venkata sai ram polina (sairamp@umd.edu)

# Instructions in running main.cpp, test.cpp and coverage report
```
git clone --recursive https://github.com/joshuag1214/test_driven_developoment
cd <path to repository>
mkdir build
cd build
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
cmake ..
make
make code_coverage
Run tests: ./test/cpp-test
Run program: ./app/shell-app



