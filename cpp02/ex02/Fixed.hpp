#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed 
{
	private:
		int _value;
		static const int _fractionalBits;
	
	public:
		Fixed();
		Fixed(const int intVal);
		Fixed(const float floatVal);
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();

		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif