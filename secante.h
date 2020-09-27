#ifndef SECANTE_H
#define SECANTE_H

#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

class secante {
public:
  secante(
             function<double(double)> p_func,
             string p_str
             ):func(p_func),str_func(p_str) {
  }
  bool raiz(double x0, 
            double x1, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    //TODO implementar secante!!
    return false;
  }
            
private:
              function<double(double)> func;
              string str_func;
              
              double f(double x) {
                return func(x);
              }
};


#endif
