//  Created by Ethan Chee on 2/10/18.
//  I, Ethan Chee, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//  I did not copy code from anyone, student or otherwise.
//
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#include "Complex.h"

/**
 * Constructor of a Complex object, with default real and imaginary values of 0, should the user not initialize one or two of the values
 * @param realNumber The double value we will initialize our realNum variable with (if provided)
 * @param imaginaryNumber The double value we will initialize our imaginaryNum variable with (if provided)
 */
Complex::Complex(double realNumber, double imaginaryNumber): realNum(realNumber), imaginaryNum (imaginaryNumber) {}

/**
 * Adds a Complex object to another Complex object, saving the value to the left side variable (override of += operator)
 * @param addMe The Complex object on the right of our +=, we aren't modifying this so it's const
 * @return A Complex object by reference of our new left hand side of the += operator
 */
Complex& Complex::operator +=(const Complex& addMe)
{
    // Add real number from addMe to our implicit parameter's real number
    realNum += addMe.realNum;
    // Add imaginary number from addMe to our implicit parameter's imaginary number
    imaginaryNum += addMe.imaginaryNum;
    // Return our implicit parameter
    return *this;
}

/**
 * Override of unary + operator, returns a copy of our implicit parameter
 * @return A copy of our current Complex object (*this)
 */
Complex Complex::operator +() const
{
     // Return our implicit parameter
    return *this;
}

/**
 * Override of prefix ++ operator, will increment the real number value (realNum member variable) of our Complex object by 1
 * @return Reference to the Complex object it is called on
 */
Complex& Complex:: operator++()
{
    // Increment real number component by 1
    ++realNum;
    // Return the implicit parameter
    return *this;
}

/**
 * Override of postfix ++ operator, will increment the real number value (realNum member variable) of our Complex object by 1
 * @return A copy of our Complex object it is called on. This version is unchanged even though our realNum has been incremented by 1
 */
Complex Complex::operator ++(int unused)
{
    // Create a copy of our implicit parameter
    Complex numCopy(*this);
    // Increment real number component by 1 (for implicit parameter)
    ++realNum;
    // Return a copy of our implicit parameter before the incrementation
    return numCopy;
}

/**
 * Subtracts a Complex object to another Complex object, saving the value to the left side variable (override of -= operator)
 * @param subtractMe The Complex object on the right of our -=, we aren't modifying this so it's const
 * @return A Complex object by reference of our new left hand side of the -= operator
 */
Complex& Complex::operator -=(const Complex& subtractMe)
{
    // Subtract subtractMe's real num from our implicit real num
    realNum -= subtractMe.realNum;
    // Subtract subtractMe's imaginary num from our implicit imaginary num
    imaginaryNum -= subtractMe.imaginaryNum;
    // Return the implicit parameter
    return *this;
}

/**
 * Override of the unary - operator, multiplying both our real and imaginary components of our Complex object by -1
 * @return A Complex object by value with both real and imaginary components multiplied by -1
 */
Complex Complex::operator -() const
{
    // Return a Complex object with negated real and imaginary parts
    return Complex(-1.0*realNum, -1.0*imaginaryNum);
}

/**
 * Override of prefix -- operator, will decrement the real number value (realNum member variable) of our Complex object by 1
 * @return Reference to the Complex object it is called on
 */
Complex& Complex:: operator--()
{
    // Decrement real number component by 1
    --realNum;
    // Return the implicit parameter
    return *this;
}

/**
 * Override of postfix -- operator, will decrement the real number value (realNum member variable) of our Complex object by 1
 * @return A copy of the Complex object it is called on. This version is unchanged even though our realNum has been decremented by 1
 */
Complex Complex::operator --(int unused)
{
    // Create a copy of our implicit parameter
    Complex numCopy(*this);
    // Decrement real number component by 1 (for implicit parameter)
    --realNum;
    // Return a copy of our implicit parameter, before the change
    return numCopy;
}

/**
 * Multiplies a Complex object to another Complex object, saving the value to the left side variable (override of *= operator)
 * @param multiplyMe The Complex object on the right of our *=, we aren't modifying this so it's const
 * @return A Complex object by reference of our new left hand side of the *= operator
 */
Complex& Complex::operator *=(const Complex& multiplyMe)
{
    // newReal will store our new real component of Complex after the specified multiplication instructions
    double newReal = (realNum * multiplyMe.realNum) - (imaginaryNum * multiplyMe.imaginaryNum);
    // newImag will store our new imaginary component of Complex after the specified mulitplication
    double newImag = (imaginaryNum * multiplyMe.realNum) + (realNum * multiplyMe.imaginaryNum);
    //Assign newReal to our member variable realNum
    realNum = newReal;
    //Assign newImag to our member variable imaginaryNum
    imaginaryNum = newImag;
    // Return the implicit parameter
    return *this;
}

/**
 * Multiplies a Complex object to another Complex object, saving the value to the left side variable (override of *= operator)
 * @param divideMe The Complex object on the right of our /=, we aren't modifying this so it's const
 * @return A Complex object by reference of our new left hand side of the /= operator
 */
Complex& Complex::operator /=(const Complex& divideMe)
{
    //newReal will store our new real component of Complex after the specified division instruction
    double newReal = (realNum * divideMe.realNum + imaginaryNum * divideMe.imaginaryNum)/(divideMe.realNum * divideMe.realNum + divideMe.imaginaryNum * divideMe.imaginaryNum);
     //newImag will store our new imaginary component of Complex after the specified division instruction
    double newImag = (imaginaryNum * divideMe.realNum - realNum * divideMe.imaginaryNum)/(divideMe.realNum * divideMe.realNum + divideMe.imaginaryNum * divideMe.imaginaryNum);
    //Assign newReal to our member variable realNum
    realNum = newReal;
    //Assign newImag to our member variable imaginaryNum
    imaginaryNum = newImag;
    //Return implicit paramter
    return *this;
}

/**
 * Switch the sign of our imaginary component of our Complex object, returning the conjugate
 * @return A copy of the implicit parameter except with the imaginaryNum mulitplied by -1
 */
Complex Complex::operator ~() const
{
    // Create a new Complex object that shares the same realNum value and imaginaryNum value of -1 * former imaginaryNum value
    return Complex(realNum, -1.0*imaginaryNum);
}

/**
 * Override the call operator, reseting both real and imaginary components of a Complex object to 0 when () is called
 * @return A reference to our implicit parameter, with real and imaginary parts set to 0
 */
Complex& Complex::operator()()
{
    //Set realNum member variable to zero
    realNum = 0;
    //Set imaginaryNum member variable to zero
    imaginaryNum = 0;
    //Return implicit parameter
    return *this;
}


/**
 * Overrides subscript operator, if user enters "real" or "imag" in subscripts, we will return realNum or imaginaryNum respectively
 * @param index String that will let us know what member variable user is trying to access
 * @return A reference to a double that user is referencing with string index, otherwise throw an exception
 */
double& Complex::operator[](const std::string& index)
{
    // If index is equal to "real"
    if (index == "real")
    {
        // Return the value of our realNum member variable
        return realNum;
    }
    // Else if index is equal to "imag"
    else if (index == "imag")
    {
        // Return the value of our imaginaryNum member variable
        return imaginaryNum;
    }
    // Else we can't return anything else in our Complex object
    else
    {
        //Throw an out of range exception, that will print the invalid index if what() is called, ending the program
        throw std::out_of_range("invalid index: " + index);
    }
}


/**
 * Conversion operator that changes a Complex object into a std::string
 * @return A string of real and imaginary member variables formatted with our overridden << operator
 */
Complex::operator std::string() const
{
    //Create a new stringstream object called sOut
    std::ostringstream sOut;
    //Pass our implicit parameter into our stringstream, << changes it into proper format
    sOut << *this;
    //Return the contents of sOut in a string
    return sOut.str();
    
}


/**
 * Binary plus operator that adds real components and imaginary components of Complex objects
 * @param left Complex object on left side of the + symbol
 * @param right Complex object on right side of the plus symbol
 * @return A Complex object by copy of using our overloaded += on left and right
 */
Complex operator+(Complex left, const Complex& right)
{
    // Return the result of the left += the right complex number
    return left += right;
}

/**
 * Binary minus operator that subtracts real components and imaginary components of Complex objects
 * @param left Complex object on left side of the - symbol
 * @param right Complex object on right side of the - symbol
 * @return A Complex object by copy of using our overloaded -= on left and right
 */
Complex operator-(Complex left, const Complex& right)
{
    // Return the result of the left -= the right complex number
    return left -= right;
}

/**
 * Binary multiply operator that multiplies real components and imaginary components of Complex objects as defined in the homework specifications
 * @param left Complex object on left side of the * symbol
 * @param right Complex object on right side of the * symbol
 * @return A Complex object by copy of using our overloaded *= on left and right
 */
Complex operator* (Complex left, const Complex& right)
{
    // Return the result of the left *= the right complex number
    return left *= right;
}

/**
 * Binary divide operator that divides real components and imaginary components of Complex objects as defined in the homework specifications
 * @param left Complex object on left side of the / symbol
 * @param right Complex object on right side of the / symbol
 * @return A Complex object by copy of using our overloaded /= on left and right
 */
Complex operator/(Complex left, const Complex& right)
{
    // Return the result of the left /= the right complex number
    return left /= right;
}

/**
 * Output operator that defines how we want to format the output of our Complex objects, declared as friend to access our member variables
 * @param out ostream object that we are using to output
 * @param complexNum The Complex object that we want to output
 * @return A reference to the same output stream we passed in as an argument
 */
std::ostream& operator<<(std::ostream& out, const Complex& complexNum)
{
    // If real component is 0, we only have one number outputted
    if (complexNum.realNum == 0)
    {
        //If imaginary component is 0
        if (complexNum.imaginaryNum == 0)
        {
            //Output 0 into our ostream
            out << "0";
        }
        //Else if imaginary component is -1
        else if (complexNum.imaginaryNum == -1)
        {
            // Output -i into our ostream
            out << "-i";
        }
        //Else if imaginary component is 1
        else if (complexNum.imaginaryNum == 1)
        {
            //Output i into our ostream
            out << "i";
        }
        //Else i must be positive or negative and not equal to -1 or 1,
        else
        {
            //Output the imaginary component followed by an i to our ostream
            out << complexNum.imaginaryNum << "i";
        }
    }
    //Real component is not equal to zero
    else
    {
        //If imaginary component is 0
        if (complexNum.imaginaryNum == 0)
        {
            //Output our real component to our ostream
            out << complexNum.realNum;
        }
        //Else if imaginary component is -1
        else if (complexNum.imaginaryNum == -1)
        {
            //Output our real component followed by a -i
            out << complexNum.realNum << "-i";
        }
        //Else if imaginary component is 1
        else if (complexNum.imaginaryNum == 1)
        {
            //Output our real component followed by a i
            out << complexNum.realNum << "+i";
        }
        //Else if imaginary component is greater than 0 and not equal to 1
        else if (complexNum.imaginaryNum > 0 && complexNum.imaginaryNum != 1)
        {
            //Output our real component followed by a + and then our imaginary component followed by an i
            out << complexNum.realNum << "+" << complexNum.imaginaryNum << "i";
        }
        //Else our imaginary component must be less 0 and not equal to -1
        else
        {
            //Output our real component followed by our imaginary component with an i at the end
            out << complexNum.realNum << complexNum.imaginaryNum << "i";
        }
    }
    //Return our ostream object
    return out;
}

/**
 * Input operator that specifies how to input our Complex objects into a istream, declared as friend to access our member variables
 * @param complexIn istream object that we are using to input
 * @param complexNum The Complex object that we want to output
 * @return A reference to the same input stream we passed in as an argument
 */
std::istream& operator>>(std::istream& complexIn, Complex& complexNum)
{
    //Pass in our realNum and imaginaryNum member variables into the stream
    complexIn >> complexNum.realNum >> complexNum.imaginaryNum;
    //If the stream fails
    if (complexIn.fail())
    {
        //Throw a runtime error, notifying user it was a reading error
        throw std::runtime_error("reading error");
    }
    //Return our input stream object
    return complexIn;
}

/**
 * Definition on how we evaluate if one Complex object is less than the other, declared as friend to give operator access to member variables
 * @param leftSide Complex object on left side of the < symbol
 * @param rightSide Complex object on right side of the < symbol
 * @return True if leftSide is smaller than rightSide, otherwise returns false
 */
bool operator<(const Complex& leftSide, const Complex& rightSide)
{
    // If the left's real component is smaller than right's real component
    if (leftSide.realNum < rightSide.realNum)
    {
        //Left is less than right, return true
        return true;
    }
    //Else if the left's real component is greater than right's real component
    else if (leftSide.realNum > rightSide.realNum)
    {
        //Left is greater than right, return false
        return false;
    }
    //Else if real components are equal
    else
    {
        //If left's imaginary component is less than right's imaginary component
        if (leftSide.imaginaryNum < rightSide.imaginaryNum)
        {
            //Left is less than right, return true;
            return true;
        }
        //Else left's imaginary component is equal or greater than right's imaginary component
        else
        {
            //Left is greater than or equal to right, return false
            return false;
        }
    }
}

/**
 * Definition on how we evaluate if one Complex object is equal to the other
 * @param leftSide Complex object on left side of the == symbol
 * @param rightSide Complex object on right side of the == symbol
 * @return True if leftSide is equal than rightSide, otherwise returns false
 */
bool operator==(const Complex& leftSide, const Complex& rightSide)
{
    //Returns false if leftSide is greater than rightSide or vice versa (using our overloaded < operator)
    return !((leftSide < rightSide) || (rightSide < leftSide));
}

/**
 * Definition on how we evaluate if one Complex object is greater than the other
 * @param leftSide Complex object on left side of the > symbol
 * @param rightSide Complex object on right side of the > symbol
 * @return True if leftSide is greater than rightSide, otherwise returns false
 */
bool operator>(const Complex& leftSide, const Complex& rightSide)
{
    //Return true is right is less than left (using overloaded < we defined above), otherwise return false
    return (rightSide < leftSide);
}

/**
 * Definition on how we evaluate if one Complex object is less than or equal to the other
 * @param leftSide Complex object on left side of the <= symbol
 * @param rightSide Complex object on right side of the <= symbol
 * @return True if leftSide is less than or equal to the rightSide, otherwise returns false
 */
bool operator<=(const Complex& leftSide, const Complex& rightSide)
{
    //Return true if left is less than right or left is equal to right (using overloaded < and == we defined above), otherwise return false
    return (leftSide < rightSide || leftSide == rightSide);
}

/**
 * Definition on how we evaluate if one Complex object is greater than or equal to the other
 * @param leftSide Complex object on left side of the >= symbol
 * @param rightSide Complex object on right side of the >= symbol
 * @return True if leftSide is greater than or equal to the rightSide, otherwise returns false
 */
bool operator>=(const Complex& leftSide, const Complex& rightSide)
{
    //Return true if left is greater than right or left is equal to right (using overloaded > and == operators defined above), otherwise return false
    return (leftSide > rightSide || leftSide == rightSide);
}

/**
 * Definition on how we evaluate if one Complex object is not equal to the other
 * @param leftSide Complex object on left side of the != symbol
 * @param rightSide Complex object on right side of the != symbol
 * @return True if leftSide is not equal to the rightSide, otherwise returns false
 */
bool operator!=(const Complex& leftSide, const Complex& rightSide)
{
    //Return false if left equals right (using overloaded == defined above, otherwise return true)
    return !(leftSide == rightSide);
}

/**
 * Converts user defined literal into a Complex object
 * @param imagPart The double we want to change into the imaginary component of a Complex object
 * @return A Complex object by copy with realNum of 0 and imaginaryNum of imagPart
 */
Complex operator "" _i(long double imagPart)
{
    //Return a new Complex object with real part of 0 and imaginary part of imagPart
    return Complex(0,imagPart);
}
















