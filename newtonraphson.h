#ifndef NEWTONRAPHSON_H
#define NEWTONRAPHSON_H
#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

class newtonraphson {
public:
  newtonraphson(
             function<double(double)> p_func,
             function<double(double)> p_dfunc, 
             string p_str
             ):func(p_func),d_func(p_dfunc), str_func(p_str) {
  }
  bool raiz(double p0, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    //TODO implementar Newton Raphson!!
    return false;
  }
            
private:
              function<double(double)> func;
              function<double(double)> d_func;
              string str_func;
              
              double f(double x) {
                return func(x);
              }
              
              double df(double x) {
                return d_func(x);
              }
};

#endif
