#include <iostream>

template<class T>
bool Swap01(T& A, T& B) {//others
	{
		T X = A;
		A = B;
		B = X;
		X = T();
	}
	return true;
}

template<class T>
bool Swap02(T& A, T& B) {//mine
	T X = A;
	T Y = B;

	{//lock point
		A = Y;
		B = X;
	}
	X = T();
	Y = T();

	return true;
}

template <class T>
bool Swap03(T& A, T& B) {//sonu-
	{
		A ^= B;
		B ^= A;
		A ^= B;
	}
	return true;

}

int main() {

	int A = 0xff;
	int B = 0xff00;

	Swap01(A, B);
	std::cout << A << ',' << B << std::endl;

	Swap02(A, B);
	std::cout << A << ',' << B << std::endl;

	Swap03(A, B);
	std::cout << A << ',' << B << std::endl;

	return 0;
}