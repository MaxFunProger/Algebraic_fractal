#include "mycomplex.h"


Complex::Complex(double a, double b){
    a_ = a;
    b_ = b;
}

double Complex::Norm(){
    return std::sqrt(a_ * a_ + b_ * b_);
}

Complex Complex::operator+(Complex other){
    other.a_ += a_;
    other.b_ += b_;
    return other;
}

Complex Complex::operator*(Complex other){
    Complex tmp = other;
    other.a_ = a_ * tmp.a_ - b_ * tmp.b_;
    other.b_ = a_ * tmp.b_ + b_ * tmp.a_;
    return other;
}

Complex& Complex::operator=(Complex rhs){
    this->a_ = rhs.a_;
    this->b_ = rhs.b_;
    return *this;
}
