#ifndef BISECCION_H
#define BISECCION_H
#include <cmath>
#include <functional>
#include <string>

using std::function;
using std::string;

class biseccion {
public:
  biseccion(
            function<double(double)> p_func,
            string p_str
          ):func(p_func),str_func(p_str) {
  }
  bool raiz(double a, 
            double b, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    //TODO implementar biseccion!!
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
