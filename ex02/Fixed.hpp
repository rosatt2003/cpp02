#ifndef Fixed_hpp
#define Fixed_hpp
#include <iostream>

class Fixed{

private:
    int _value;
    static const int _fractionalBits = 8;
public:
    Fixed();

    Fixed(int intValue);

    Fixed(float floatValue);

    Fixed(const Fixed &other); //copy constructor

    ~Fixed();

    Fixed & operator=(const Fixed &other); //copy assignment operator
    
    int getRawBits( void ) const;
    
    void setRawBits( int const raw );
    
    int toInt( void ) const;
    
    float toFloat( void ) const;
    //operatori di confronto
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const; //non modificano l'oggetto quindi const
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    //operatori aritmetici
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    //operatori di incremento
    Fixed & operator++();//pre
    Fixed operator++(int);//post , non e una variabile ma un nome fittizio per il compilatore
    Fixed & operator--(); //pre
    Fixed operator--(int);//post

    static Fixed & min(Fixed &a, Fixed &b);
    static const Fixed & min(const Fixed &a, const Fixed &b);    
    static Fixed & max(Fixed &a, Fixed &b);
    static const Fixed & max(const Fixed &a, const Fixed &b);    

};

std::ostream & operator<<(std::ostream &out, const Fixed &fixed);

#endif