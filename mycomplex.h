#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <cmath>

class Complex{

  public:

  Complex(double, double);

  double Norm();

  Complex operator+(Complex);
  Complex operator*(Complex);
  Complex& operator=(Complex);

  private:
      double a_, b_;

};


#endif // MYCOMPLEX_H
