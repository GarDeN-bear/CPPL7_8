#include <iostream>

template<class T>
class smart_pointer {
public:
	smart_pointer(T* ptr_) : ptr(ptr_) { }
	T& operator*() { return *ptr; }
	//smartpointer(const smart_pointer&) = delete;
	smart_pointer& operator=(const smart_pointer&) = delete;
	~smart_pointer() {
		std::cout << "destructor\n";
		delete[] ptr;
		ptr = nullptr;
	}
	T* release() {
		T* temp_buf = ptr;
		*temp_buf = *ptr;
		ptr = nullptr;
		return temp_buf;
	}
private:
	T* ptr;
};
int main() {
	smart_pointer<double> ptr(new double(5));
	std::cout << *ptr << "\n";
	double* ptr_1 = ptr.release();
	delete ptr_1;
}