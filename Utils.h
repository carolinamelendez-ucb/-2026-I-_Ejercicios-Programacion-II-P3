#pragma once
#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

void assertEquals(double a, double b) {
	double difference = a - b;
	if (difference < 0) difference = difference * -1;
	if (difference < 0.002) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << a << " != " << b << endl;
	}
}

void assertEquals(const string& a, const string& b) {
	if (a == b) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << a << " != " << b << endl;
	}
}

template <class T>
void assertEquals(T a, T b) {
	if (a == b) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << endl;
		cout << " - Actual:   [" << a << "]" << endl;
		cout << " - Esperado: [" << b << "]" << endl;
	}
}

template <typename T>
typename enable_if<is_enum<T>::value, void>::type assertEnumEquals(T a, T b) {
	if (a == b) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << endl;
		cout << " - Actual enum:   [" << static_cast<int>(a) << "]" << endl;
		cout << " - Esperado enum: [" << static_cast<int>(b) << "]" << endl;
	}
}

void assertTrue(bool value) {
	if (value) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << value << " should be true" << endl;
	}
}

void assertTrue(bool value, const string& failMessage) {
	if (value) {
		cout << "ASSERT PASS :)" << endl;
	}
	else {
		cout << "ASSERT FAILS: " << failMessage << endl;
	}
}

void assertFalse(bool value) {
	assertTrue(!value);
}