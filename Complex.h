//  Created by Ethan Chee on 2/10/18.
//  I, Ethan Chee, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//  I did not copy code from anyone, student or otherwise.
//
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef Complex_hpp
#define Complex_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdexcept>

/**
 * Class that represents a complex number
 */
class Complex
{
public:
    
    /**
     * Constructor of a Complex object, with default real and imaginary values of 0, should the user not initialize one or two of the values
     * @param realNumber The double value we will initialize our realNum variable with (if provided)
     * @param imaginaryNumber The double value we will initialize our imaginaryNum variable with (if provided)
     */
    Complex(double realNumber = 0, double imaginaryNumber = 0);
    
    /**
     * Adds a Complex object to another Complex object, saving the value to the left side variable (override of += operator)
     * @param addMe The Complex object on the right of our +=, we aren't modifying this so it's const
     * @return A Complex object by reference of our new left hand side of the += operator
     */
    Complex& operator +=(const Complex& addMe);
    
    /**
     * Override of unary + operator, returns a copy of our implicit parameter
     * @return A copy of our current Complex object (*this)
     */
    Complex operator +() const;
    
    /**
     * Override of prefix ++ operator, will increment the real number value (realNum member variable) of our Complex object by 1
     * @return Reference to the Complex object it is called on
     */
    Complex& operator++();
    
    /**
     * Override of postfix ++ operator, will increment the real number value (realNum member variable) of our Complex object by 1
     * @return A copy of our Complex object it is called on. This version is unchanged even though our realNum has been incremented by 1
     */
    Complex operator ++(int unused);
    
    /**
     * Subtracts a Complex object to another Complex object, saving the value to the left side variable (override of -= operator)
     * @param subtractMe The Complex object on the right of our -=, we aren't modifying this so it's const
     * @return A Complex object by reference of our new left hand side of the -= operator
     */
    Complex& operator -=(const Complex& subtractMe);
    
    /**
     * Override of the unary - operator, multiplying both our real and imaginary components of our Complex object by -1
     * @return A Complex object by value with both real and imaginary components multiplied by -1
     */
    Complex operator -() const;
    
    /**
     * Override of prefix -- operator, will decrement the real number value (realNum member variable) of our Complex object by 1
     * @return Reference to the Complex object it is called on
     */
    Complex& operator--();
    
    /**
     * Override of postfix -- operator, will decrement the real number value (realNum member variable) of our Complex object by 1
     * @return A copy of the Complex object it is called on. This version is unchanged even though our realNum has been decremented by 1
     */
    Complex operator --(int unused);
    
    /**
     * Multiplies a Complex object to another Complex object, saving the value to the left side variable (override of *= operator)
     * @param multiplyMe The Complex object on the right of our *=, we aren't modifying this so it's const
     * @return A Complex object by reference of our new left hand side of the *= operator
     */
    Complex& operator *=(const Complex& multiplyMe);
    
    /**
     * Multiplies a Complex object to another Complex object, saving the value to the left side variable (override of *= operator)
     * @param divideMe The Complex object on the right of our /=, we aren't modifying this so it's const
     * @return A Complex object by reference of our new left hand side of the /= operator
     */
    Complex& operator /=(const Complex& divideMe);
    
    /**
     * Switch the sign of our imaginary component of our Complex object, returning the conjugate
     * @return A copy of the implicit parameter except with the imaginaryNum mulitplied by -1
     */
    Complex operator ~() const;
    
    /**
     * Override the call operator, reseting both real and imaginary components of a Complex object to 0 when () is called
     * @return A reference to our implicit parameter, with real and imaginary parts set to 0
     */
    Complex& operator()();
    
    /**
     * Overrides subscript operator, if user enters "real" or "imag" in subscripts, we will return realNum or imaginaryNum respectively
     * @param index String that will let us know what member variable user is trying to access
     * @return A reference to a double that user is referencing with string index, otherwise throw an exception
     */
    double& operator[](const std::string& index);
    
    /**
     * Output operator that defines how we want to format the output of our Complex objects, declared as friend to access our member variables
     * @param out ostream object that we are using to output
     * @param complexNum The Complex object that we want to output
     * @return A reference to the same output stream we passed in as an argument
     */
    friend std::ostream& operator<<(std::ostream& out, const Complex& complexNum);
    
    /**
     * Input operator that specifies how to input our Complex objects into a istream, declared as friend to access our member variables
     * @param complexIn istream object that we are using to input
     * @param complexNum The Complex object that we want to output
     * @return A reference to the same input stream we passed in as an argument
     */
    friend std::istream& operator>>(std::istream& complexIn, Complex& complexNum);
    
    /**
     * Definition on how we evaluate if one Complex object is less than the other, declared as friend to give operator access to member variables
     * @param leftSide Complex object on left side of the < symbol
     * @param rightSide Complex object on right side of the < symbol
     * @return True if leftSide is smaller than rightSide, otherwise returns false
     */
    friend bool operator<(const Complex& leftSide, const Complex& rightSide);
    
    /**
     * Conversion operator that changes a Complex object into a std::string
     * @return A string of real and imaginary member variables formatted with our overridden << operator
     */
    operator std::string() const;
    
private:
    //realNum represents the real component of a complex number, imaginaryNum represents the imaginary component of a complex number
    double realNum, imaginaryNum;
    
};


/**
 * Binary plus operator that adds real components and imaginary components of Complex objects
 * @param left Complex object on left side of the + symbol
 * @param right Complex object on right side of the plus symbol
 * @return A Complex object by copy of using our overloaded += on left and right
 */
Complex operator+(Complex left, const Complex& right);

/**
 * Binary minus operator that subtracts real components and imaginary components of Complex objects
 * @param left Complex object on left side of the - symbol
 * @param right Complex object on right side of the - symbol
 * @return A Complex object by copy of using our overloaded -= on left and right
 */
Complex operator-(Complex left, const Complex& right);

/**
 * Binary multiply operator that multiplies real components and imaginary components of Complex objects as defined in the homework specifications
 * @param left Complex object on left side of the * symbol
 * @param right Complex object on right side of the * symbol
 * @return A Complex object by copy of using our overloaded *= on left and right
 */
Complex operator* (Complex left, const Complex& right);

/**
 * Binary divide operator that divides real components and imaginary components of Complex objects as defined in the homework specifications
 * @param left Complex object on left side of the / symbol
 * @param right Complex object on right side of the / symbol
 * @return A Complex object by copy of using our overloaded /= on left and right
 */
Complex operator/(Complex left, const Complex& right);

/**
 * Definition on how we evaluate if one Complex object is equal to the other
 * @param leftSide Complex object on left side of the == symbol
 * @param rightSide Complex object on right side of the == symbol
 * @return True if leftSide is equal than rightSide, otherwise returns false
 */
bool operator==(const Complex& leftSide, const Complex& rightSide);

/**
 * Definition on how we evaluate if one Complex object is greater than the other
 * @param leftSide Complex object on left side of the > symbol
 * @param rightSide Complex object on right side of the > symbol
 * @return True if leftSide is greater than rightSide, otherwise returns false
 */
bool operator>(const Complex& leftSide, const Complex& rightSide);

/**
 * Definition on how we evaluate if one Complex object is less than or equal to the other
 * @param leftSide Complex object on left side of the <= symbol
 * @param rightSide Complex object on right side of the <= symbol
 * @return True if leftSide is less than or equal to the rightSide, otherwise returns false
 */
bool operator<=(const Complex& leftSide, const Complex& rightSide);

/**
 * Definition on how we evaluate if one Complex object is greater than or equal to the other
 * @param leftSide Complex object on left side of the >= symbol
 * @param rightSide Complex object on right side of the >= symbol
 * @return True if leftSide is greater than or equal to the rightSide, otherwise returns false
 */
bool operator>=(const Complex& leftSide, const Complex& rightSide);

/**
 * Definition on how we evaluate if one Complex object is not equal to the other
 * @param leftSide Complex object on left side of the != symbol
 * @param rightSide Complex object on right side of the != symbol
 * @return True if leftSide is not equal to the rightSide, otherwise returns false
 */
bool operator!=(const Complex& leftSide, const Complex& rightSide);

/**
 * Converts user defined literal into a Complex object
 * @param imagPart The double we want to change into the imaginary component of a Complex object
 * @return A Complex object by copy with realNum of 0 and imaginaryNum of imagPart
 */
Complex operator "" _i(long double imagPart);

#endif /* Complex_hpp */
