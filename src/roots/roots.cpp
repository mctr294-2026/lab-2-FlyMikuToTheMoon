#include "roots.hpp"
#include <cmath>

double precision = 1e-6; // specified precision required for the root to satisfy

bool bisection(std::function<double(double)> f, double a, double b, double *root) {
   
    double c = (a+b)/2;
    
    if (f(a) * f(b) > 0) { // checking if f(a) and f(b) have opposite signs

        return false; // no root exists if they don't have opposite signs

    } else {

        while (std::abs(f(c)) > precision) { // checking if the root has a high enough precision
            
            c = (a + b)/2;

            if (f(a) * f(c) < 0) {

                b = c;

            } else if (f(b) * f(c) < 0) {

                a = c;

            } else {

                return false;
            }
        }

        *root = c;
        return true;
    } 
    
}

bool regula_falsi(std::function<double(double)> f, double a, double b, double *root) {

    double c = a - (f(a) * (b - a)) / (f(b) - f(a));
    
    if (f(a) * f(b) > 0) {

        return false;

    } else {

        while (std::abs(f(c)) > precision) {
            
            c = a - (f(a) * (b-a)) / (f(b) - f(a));

            if (f(a) * f(c) < 0) {

                b = c;

            } else if (f(b) * f(c) < 0) {

                a = c;

            }
        }

        *root = c;
        return true;
    }    
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
    
    if (f(a) * f(b) > 0) {

        return false;

    } else if (g == 0) {

        return false;

    } else {

        for (int i = 0; std::abs(f(c)) > precision; i++) {

            c = c - f(c) / g(c);

            if (a > c || c > b) {

                return false;

            }

        }

        *root = c;
        return true;
    }
}

bool secant(std::function<double(double)> f, double a, double b, double c, double *root) {

    if (f(a) * f(b) > 0) {

        return false;

    } else {

        while (std::abs(f(c)) > precision) {

            c = b - ((b - a) / (f(b) - f(a))) * f(b);
            
            a = b; // make sure to update a's value first before updating b, or you may end up
                   // dividing by zero
            b = c;

        }
        
        *root = c;

        return true;

    }
}

