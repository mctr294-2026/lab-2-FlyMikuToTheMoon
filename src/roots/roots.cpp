#include "roots.hpp"
#include <cmath>

double precision = 1e-6;

bool bisection(std::function<double(double)> f, double a, double b, double *root) {
   
    double c = (a+b)/2;
    
    if (f(a)*f(b) > 0) {

        return false;

    } else {

        while (std::abs(f(c)) > precision) {
            
            c = (a+b)/2;

            if (f(a)*f(c) < 0) {

                b = c;

            } else if (f(b)*f(c) < 0) {

                a = c;

            } else {

                return false;
            }
        }

        *root = c;
        
        return true;
    } 
    
}

bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {

    double c = a - (f(a)*(b-a))/(f(b)-f(a));
  
    if (f(c) == 0) {

    return true;

   } else {

    return false;
   }    
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
    if (g == 0) {

        return false;

    } else {

        c = b;

        while (f(c) != 0) {
            c = c - f(c)/g(c);
        }

        return true;
    }
        
}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {
    
    if (f(a) != 0) {
        return false;
    } else {
        return true;
    }
}

