#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex():real(0.0),imaginary(0.0) {}
	Complex(double r,double i):real(r),imaginary(i) {}

    
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imaginary * other.imaginary,
                       real * other.imaginary + imaginary * other.real);
    }

    
    Complex(int integer) : real(static_cast<double>(integer)), imaginary(0.0) {}

    
    Complex(double realPart) : real(realPart), imaginary(0.0) {}

    
    operator double() const {
        return real;
    }

    void display() {
        if (imaginary >= 0)
            std::cout << real << " + " << imaginary << "i" << std::endl;
        else
            std::cout << real << " - " << -imaginary << "i" << std::endl;
    }
};

int main() {
    Complex a(3, 2);
    Complex b(1, -1);

    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;

    c.display();
    d.display();
    e.display();

    int integer = 5;
    Complex f = integer;
    double realNumber = 2.5;
    Complex g = realNumber;
    double realPart = static_cast<double>(a);

    f.display();
    g.display();
    std::cout << "Real part of a: " << realPart << std::endl;

    return 0;
}
