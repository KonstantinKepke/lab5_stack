#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

#include <ostream>
#include <iterator>


template <typename T>
class Point
{
private:
    T x;
    T y;
public:
    Point() : x{0}, y(0) { cout << "Point ctor 0\n"; };
    Point(const T &x_, const T &y_) : x{x_}, y(y_) { cout << "Point ctor 1\n"; };
    Point(const Point &pt) : x{pt.x}, y(pt.y) { cout << "Point(Point& pt) \n"; };
    Point(Point &&pt) = default;
    // Point(Point && pt) // WRONG
    // {
    //     cout << "Point(Point&& pt) \n";
    //     x = pt.x;
    //     y = pt.y;
    //     delete pt; // ERROR
    // };
    Point &operator=(Point& other) = default;
    Point &operator=(Point&& other) = default;
    // Point &operator=(Point &&other)
    // {
    //     cout << "Point(Point&& other) \n";
    //     x = other.x;
    //     y = other.y;
    //     delete other;
    // };
    void set(const T &x_, const T &y_)
    {
        x = x_;
        y = y_;
    }
    void print()
    {
        cout << "x=" << x << " y=" << y << endl;
    }
    template<typename U>
    friend ostream& operator << (ostream& s,  Point<U>& point);
};

template<typename U>
std::ostream& operator << (std::ostream& s,  Point<U>& point){
    s << "x="<< point.x << " y="  << point.y << "\n"; 
    return s;
}

int main()
{
	cout << "home work c++part2 1_5 - stack" << endl;

	Point p1(1, 1);
	p1.print();
	using T=Point<int>;

	void* mem = new char[sizeof(T)];
	new(mem) T(77, 99); 
	T * p_t = static_cast<T*>(mem);
	p_t->print();
	

	return 0;
}
