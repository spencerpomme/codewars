#pragma once
#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::endl;



// Sales_data 类
struct Sales_data {
	// 构造函数
	Sales_data() = default;
	Sales_data(const string& s) : bookNo(s), units_sold(0), revenue(0.0) {}
	Sales_data(const string& s, unsigned u, double p) : bookNo(s), units_sold(u), revenue(p* u) {}
	Sales_data(istream& is) {
		double price = 0;
		is >> bookNo >> units_sold >> price;
		revenue = price * units_sold;
	}

	// 类内初始值
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
	// 成员函数
	string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);

Sales_data& Sales_data::combine(const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const {
	return revenue / units_sold;
}

istream& read(istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}












//-------------------------------------------------| 分割线 |------------------------------------------------//
// Person 类
struct Person {
	string name;
	string address;
	Person(string name_, string address_) : name(name_), address(address_) {}; // struct constructor syntax...
	string getName() const;
	string getAddress() const;
};

string Person::getName() const {
	return name;
}

string Person::getAddress() const {
	return address;
}

ostream& pprint(ostream&, const Person&);
istream& pread(istream&, Person&);

istream& pread(istream& is, Person& p) {
	double price = 0;
	is >> p.name >> p.address;
	return is;
}

ostream& pprint(ostream& os, const Person& p) {
	os << p.name << " " << p.address << endl;
	return os;
}
