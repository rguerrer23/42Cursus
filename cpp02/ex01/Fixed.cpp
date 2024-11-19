#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	_value = intVal << _fractionalBits;
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatVal * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignation operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}