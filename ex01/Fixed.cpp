#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(){
    std::cout <<"Default constructor called"<< std::endl;
    _value = 0;
};

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