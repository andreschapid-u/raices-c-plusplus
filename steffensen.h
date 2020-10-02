#ifndef STEFFENSEN_H
#define STEFFENSEN_H

#include <cmath>
#include <functional>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::function;
using std::ios;
using std::string;

class steffensen {
public:
  steffensen(
             function<double(double)> p_func,
             string p_str
             ):func(p_func),str_func(p_str) {
  }
  
  string str(){
    return str_func;
  }
    bool raiz(double x0, 
              int max_iter, 
              double tolerancia,
              double &valor_raiz) {
      //TODO implementar regla steffensen!!
      cout.precision(10);
     // cout.width(12);
     // std::scientific;
      
      double x1=0.0, err=0.0;
      cout<<"\n X0 : "<<x0;
      cout<<"\n"<<"n"<<"\t"<<"x1"<<"\t\t\t"<<"f(X1)";
      int i = 1;
      while(i <= max_iter && fabs(f(x0)) > tolerancia)
      {
        x1= x0 - ((f(x0)*f(x0))/ ( f(x0 + f(x0)) - f(x0)));
       
        cout<<"\n"<<i<<"\t";
        cout << x1;
        cout<<"\t"; cout << f(x1);
        x0=x1;
        i++;
      }
      
      if(fabs(f(x1))<=tolerancia){
        cout<<"\nProcedimiento completado satisfactoriamente\n";
        
        cout<<"\nX1 : " << x1 << "\tf(" << x1 << ") = " << f(x1) << endl;
        valor_raiz = x1;
        cout<<"\nNumero de Iteraciones: " <<i << endl;
        return true;
      }      
      cout<<"\nEl metodo fracaso despues de "<<max_iter<<" iteraciones";
      return false;
    }
              
private:
  function<double(double)> func;
  string str_func;
  
  double f(double x){
    return func(x);
  }
};

#endif

