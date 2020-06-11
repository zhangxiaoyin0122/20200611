#include <iostream>
using namespace std;

class Date {
public:
	//构造函数
	Date(int year, int month, int day) {
		if (year > 0 && month > 0 && month < 13 && day > 0 && getmonthdays(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else {
			cout << "日期不合法" << year << "-" << month << "-" << day << endl;
			cout << "日期重置" << endl;
			_year = 1;
			_month = 1;
			_day = 1;
		}
	}
	int getmonthdays(int year, int month) {
		int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int day = days[month];
		if ( (((year % 4 == 0) && (year % 100 == 0)) || (year % 400 == 0)) && (month == 2)) {
			++day;
		}
		return day;
	}
	Date& operator+=(int day) {
		_day += day;
		while (_day > getmonthdays(_year, _month)) {
			_day -= getmonthdays(_year, _month);
			++_month;
			if (_month == 13) {
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	//前置--
	Date& operator--() {
		return *this -= 1;
	}
	//后置--
	Date& operator--(int) {
		Date ret(*this);
		ret -= 1;
		return ret;
	}
	//前置++
	Date& operator++() {
		return *this += 1;
	}
	//后置++
	Date& operator++(int) {
		Date ret(*this);
		ret += 1;
		return ret;
	}
	Date& operator-=(int day) {
		_day -= day;
		while (_day < 0) {
			--_month;
			if (_month == 0) {
				_month = 12;
				--_year;
			}
			_day += getmonthdays(_year, _month);
		}
		return *this;

	}
	Date operator+(int day) {
		Date ret(*this);
		ret += day;
		return ret;
	}
	Date operator-(int day) {
		Date ret(*this);
		ret -= day;
		return ret;
	}
	bool operator==(const Date& d) {
		return _year == d._year&&_month == d._month&&_day == d._day;
	}
	bool operator>(const Date& d) {
		if (_year > d._year) {
			return true;
		}
		else if (_year == d._year) {
			if (_month > d._month)
				return true;
			else if (_month == d._month) {
				if (_day > d._day) {
					return true;
				}
			}

		}
		return false;
	}
	bool operator>=(const Date& d) {
		return (*this > d) || (*this == d);
	}

	bool operator<(const Date& d) {
		return !(*this >= d);
	}
	//拷贝构造函数
	Date(const Date& d)
		:_year (d._year)
		,_month(d._month)
		,_day(d._day)
	{}

private:
	int _year;
	int _month;
	int _day;
};