#pragma once

#include <iostream>
#include <string>

using std::string;

// Declair a function in 3 different syntax
// direct declairation
string(&func1(string(&)[5]))[5];

// type alias declaration 1: 'typedef'
typedef string(&sa)[5];
sa func2(sa);

// type alias declaration 2: 'using' keyword
using saref = string(&)[5];
saref func3(saref);

// trailing return type declaration
auto func4(string(&)[5])->string(&)[5];

// actual definition
string(&func1(string(&ref)[5]))[5] {
	return ref;
}

sa func2(sa ref) {
	return ref;
}

saref func3(saref ref) {
	return ref;
}

auto func4(string(&ref)[5])->string(&)[5]{
	return ref;
}
