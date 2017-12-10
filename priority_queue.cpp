#include <vector>
#include <iostream>

#include "priority_queue.hpp"

template <typename T>
void priority_queue<T>::sift_down(size_type i) {
	size_type l = i*2;
	size_type r = l + 1;
	auto size = this->v.size();
	while (l < size) {
		if (r < size && v[r] < v[l])
			l=r;

		if (v[i] < v[l])
			break;

		swap(l, i);
		i = l;
		l = i*2;
		r = l+1;
	}
}

template <typename T>
void priority_queue<T>::sift_up(size_type i) {
	size_type p = i/2;
	while (p >= 1) {
		if (v[i] > v[p])
			break;

		swap(i, p);
		i = p;
		p = i/2;
	}
}

template <typename T>
void priority_queue<T>::build() {
	v.push_back(v[0]);
	for(int i = v.size()/2; i >= 1; i--)
		sift_down(i);
}

template <typename T>
void priority_queue<T>::push(T i) {
	v.push_back(i);
	sift_up(v.size() - 1);
}

template <typename T>
void priority_queue<T>::pop() {
	v[1] = v.back();
	v.pop_back();
	sift_down(1);
}

/********************** Test code **************************/

template <typename>
class Foo;
template <typename T>
bool operator <(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
bool operator >(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
bool operator ==(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
bool operator <=(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
bool operator >=(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
bool operator !=(const Foo<T> &foo1, const Foo<T> &foo2);
template <typename T>
std::ostream& operator<<(std::ostream &os, const Foo<T> &foo);

template <typename T>
class Foo {
public:
	Foo() = default;
	Foo(T t):t(t){}
	friend bool operator < <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend bool operator > <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend bool operator == <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend bool operator <= <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend bool operator >= <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend bool operator != <T>(const Foo<T> &foo1, const Foo<T> &foo2);
	friend std::ostream& operator << <T>(std::ostream &os, const Foo<T> &foo);
private:
	T t;
};

template <typename T>
inline bool operator<(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return foo1.t < foo2.t;
}

template <typename T>
inline bool operator>(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return foo1.t > foo2.t;
}

template <typename T>
inline bool operator==(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return foo1.t == foo2.t;
}

template <typename T>
inline bool operator<=(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return foo1 < foo2 || foo1 == foo2;
}

template <typename T>
inline bool operator>=(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return foo1 > foo2 || foo1 == foo2;
}

template <typename T>
inline bool operator!=(const Foo<T> &foo1, const Foo<T> &foo2) 
{
	return !(foo1 == foo2);
}

template <typename T>
inline std::ostream& operator<<(std::ostream &os, const Foo<T> &foo) {
	return os<<foo.t;
}

int main() 
{
	priority_queue<Foo<double>> pq{2,4,5,1,6,1.2,9.7,3.45,2.222};
	pq.push(2);
	pq.push(2.22);
	pq.push(0);
	pq.push(0.1);
	pq.push(-0.1);

	while (pq.size()) {
		std::cout<<pq.top()<<" ";
		pq.pop();
	}
}