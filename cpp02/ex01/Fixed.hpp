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

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif