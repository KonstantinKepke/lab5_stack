#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <algorithm>
#include <thread>
#include <array>
#include <string>
#include <cctype>
// #include <fmt>
#include <fmt/color.h>
using namespace std;

#include <ostream>
#include <iterator>

#define PRINT_for_each(x)             \
	{                                 \
		for (auto el : x)             \
		{                             \
			cout << " | el = " << el; \
		}                             \
		cout << endl                  \
			 << "==========\n";       \
	}

#define PrintExpression(Expression) \
	std::cout << "{ " #Expression " }: " << (Expression) << std::endl;

#include "my_stack.hpp"
#include "point.hpp"

int main()
{
	cout << "home work c++part2 1_5 - stack" << endl;

	Point p1(1, 1);
	p1.print();

	Point p2(p1);
	p2.print();
	p2.set(2, 2);
	p2.print();
	Point p3(Point(3, 3));
	p3.print();
	Point p4(move(p1));
	p4.print();
	// delete &p1;
	p1.print();
	cout << " p3 = " << p3;
	cout << "========" << endl;
	My_Stack<Point<int>> s{};
	s.push(p1);
	s.push(p2);
	s.push(Point(7, 7));
	s.push(Point(9, 9));
	
	s.print_stack();
	Point poi_from_stack{s.pop()};
	poi_from_stack.print();
	s.push_emplace(15, 15);
	s.push_emplace_placement_new(177, 177);
	cout << "\n\n---=================---\n";
	s.push(p1, Point(7,7), Point(7, 9), p1, p2, p3);
	//s.size();
	
	s.print_stack();

	s.pop();
	s.pop();
	p1 = s.pop();
	p1.print();
	try {
		s.pop();
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
	
	s.print_stack();

	return 0;
}
