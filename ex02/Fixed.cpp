#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
    std::cout <<"Default constructor called"<< std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &other){
    std::cout <<"Copy constructor called"<< std::endl;
    _value = other._value;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed &other){
    std::cout <<"Copy assignment operator called" << std::endl;
    if(this != &other)
        _value = other._value;
    return(*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout <<"getRawBits member function called"<<std::endl;
    return(_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    _value = raw;
}
int Fixed::toInt( void ) const
{
    return(_value/256);
}
Fixed::Fixed(int intValue)
{
    std::cout<< "Int constructor called"<< std::endl;
    _value = intValue * 256;
}
Fixed::Fixed(float floatValue)
{
    std::cout<<"Float constructor called"<< std::endl;
    _value = roundf(floatValue * 256.0f);
}
float Fixed::toFloat( void ) const
{
    return(_value / 256.0f);
}
std::ostream & operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return(out);
}
bool Fixed::operator>(const Fixed &other) const
{
    if(_value > other._value)
        return(true);
    return(false);
}
bool Fixed::operator<(const Fixed &other) const
{
    if(_value < other._value)
        return(true);
    return(false);
}
bool Fixed::operator>=(const Fixed &other) const
{
    if(_value >= other._value)
        return(true);
    return(false);
}
bool Fixed::operator<=(const Fixed &other) const
{
    if(_value <= other._value)
        return(true);
    return(false);
}
bool Fixed::operator==(const Fixed &other) const
{
    if(_value == other._value)
        return(true);
    return(false);
}
bool Fixed::operator!=(const Fixed &other) const
{
    if(_value != other._value)
        return(true);
    return(false);
}
Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed a;
    a._value = (_value + other._value);
    return(a);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed a;
    a._value = (_value - other._value);
    return(a);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed a;
    a._value = (_value * other._value / 256);
    return(a);
}
Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed a;
    a._value = (256 * _value / other._value);
    return(a);
}
Fixed & Fixed::operator++()
{
    _value = _value + 1;
    return(*this);
}
Fixed & Fixed::operator--()
{
    _value = _value - 1;
    return(*this);
}
Fixed Fixed::operator++(int)
{
    Fixed a;
    a._value = _value;
    _value = _value + 1;
    return(a);
}
Fixed Fixed::operator--(int)
{
    Fixed a;
    a._value = _value;
    _value = _value - 1;
    return(a);
}
Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if(a < b)
        return(a);
    return(b);
}
const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
    if(a < b)
        return(a);
    return(b);   
}
Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if(a > b)
        return(a);
    return(b);
}
const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if(a > b)
        return(a);
    return(b);
}