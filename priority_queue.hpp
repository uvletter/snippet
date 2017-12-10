#include <vector>
#include <initializer_list>

template <typename T>
class priority_queue {
public:
	typedef typename std::vector<T>::size_type size_type;
	priority_queue(const std::vector<T> v);
	priority_queue(const std::initializer_list<T> l);
	void push(T i);
	void pop();
	T top();
	size_type size();
private:
	std::vector<T> v;
	void sift_down(size_type i);
	void sift_up(size_type i);
	void build();
	void swap(size_type a, size_type b);
};

template <typename T>
inline priority_queue<T>::priority_queue(const std::vector<T> v):v(v) {
	build();
}

template <typename T>
inline priority_queue<T>::priority_queue(const std::initializer_list<T> l): v(l.begin(), l.end()){
	build();
}

template <typename T>
inline void priority_queue<T>::swap(size_type a, size_type b) {
	T temp = v[a];
	v[a] = v[b];
	v[b] =temp;
}

template <typename T>
inline T priority_queue<T>::top() {
	return v[1];
}

template <typename T>
inline typename priority_queue<T>::size_type priority_queue<T>::size() {
	return v.size()-1;
}