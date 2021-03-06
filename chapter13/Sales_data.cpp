#include "Sales_data.h"

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo), units_sold(orig.units_sold), revenue(orig.revenue){}

//std::string isbn() const
Sales_data& Sales_data::combine(const Sales_data &trans)
{
	if(bookNo == trans.bookNo)
	{
		units_sold += trans.units_sold;
		revenue += trans.revenue;
	}
	else
		std::cerr << "Not same book ..." << std::endl;

	return *this;
}

double Sales_data::avg_price() const
{
	double avg = 0;
	avg = revenue / units_sold;

	return avg;
}

std::istream &read(std::istream &is, Sales_data &trans)
{
	std::cout << "enter a sale_data class..." << std::endl;
	double price = 0;
	is >> trans.bookNo >> trans.units_sold >> price;
	trans.revenue = trans.units_sold * price;

	return is;
}

std::ostream &print(std::ostream &os, const Sales_data &trans)
{
	os << trans.bookNo << " " << trans.units_sold << " " <<  trans.revenue << std::endl;

	return os;
}

/*
void read(Sales_data &trans)
{
	double price = 0;
	std::cin >> trans.bookNo >> trans.units_sold >> price;
	trans.revenue = trans.units_sold * price;
}

void print(const Sales_data &trans)
{
	std::cout << trans.bookNo << " " << trans.units_sold << " " <<  trans.revenue << std::endl;
}
*/

Sales_data add(const Sales_data &A, const Sales_data &B)
{
	Sales_data sum = A;
	sum.combine(B);

	return sum;
}

Sales_data& Sales_data::operator=(const Sales_data &rhs)
{
	bookNo = rhs.bookNo;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
}
