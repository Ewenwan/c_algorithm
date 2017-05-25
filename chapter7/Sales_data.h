#include <iostream>

class Sales_data{
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream &print(std::ostream&, const Sales_data&);
	friend std::istream &read(std::istream&, Sales_data&);
public:
	/*
	Sales_data() = default;
	Sales_data(std::string s):bookNo(s){}
	Sales_data(std::string s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n * p){}
	Sales_data(std::istream &);
	*/
	Sales_data(std::string s1, unsigned units, double rev):bookNo(s1), units_sold(units), revenue(rev){}
	Sales_data():Sales_data(" ", 0, 0){}
	//explicit Sales_data(std::string s):Sales_data(s, 0, 0){}
	Sales_data(std::string s):Sales_data(s, 0, 0){}
	//Sales_data(std::istream& is):Sales_data(" ", 0, 0);
	Sales_data(std::istream& is);

	std::string isbn() const {return bookNo;}
	Sales_data& combine(const Sales_data &);
	double avg_price() const;

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
//void print(const Sales_data&);
//void read(Sales_data&);

