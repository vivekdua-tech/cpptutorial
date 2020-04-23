#include <iostream>
#include <vector>
#include <map>

using namespace std;

int foo(double d, char c) {return 0;}
//typedef int PlaneId;
using PlaneId = int;

//typedef int(*PtrFunc)(double, char);
using PtrFunc = int(*)(double, char);

template<typename T, typename V> 
using lookup = map<T, vector<vector<V>>>;

int main() {
	PlaneId test;

	lookup<string, int> nameLookup;
}