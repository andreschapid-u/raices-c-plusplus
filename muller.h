#ifndef MULLER_H
#define MULLER_H

#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

using std::function;
using std::string;
using std::cout;
using std::endl;

class muller{
public:
  muller(
         function<double(double)>p_func,
         string p_str
         ): func(p_func), str_func(p_str){
    
  }
  
  bool raiz(double x0,
            double x1,
            double x2,
            int max_iter,
            double tolerancia,
            double &valor_raiz){
    
    bool encontrada = false;
    
    cout.precision(10);
    // cout.width(12);
    // std::scientific;
    //paso 1
    double h1 = x1- x0;
    double h2 = x2- x1;
    
    double d1= (f(x1) - f(x0))/h1;
    double d2= (f(x2) - f(x1))/h2;
    double a= (d2 - d1)/(h2 + h1);
    int iter =2;
    //paso 2 
    while(iter<=max_iter && encontrada == false){
      //paso 3
      double b = d2+(h2 * a);
      double c = f(x2);
      
      //hallar la solucion a la ecuacion cuadratica 
      double D = sqrt(b*b -4*a*c);
      //paso 4
      double E = b - D;
      if(fabs(b-D)< fabs(b+D)){
        E= b + D;
      }
      //paso 5
      double h= (-2.0 * c)/E;
      //hallar el siguiente punto (aproximacion)
      double x3 = x2 +h;
      //paso 6
      double er= fabs((x3 - x2)/x3);
      
      cout<< a << "(x - "<< x2 << ")^2 + "
        << b << "(x - "<< x2 << ") + "
        << c <<" err: " << er << "   iter: " << iter << endl;
      
      //verificacion 
      if(fabs(er)<tolerancia){
        encontrada = true;
        valor_raiz = x3;
        cout<<"\nNumero de Iteraciones: " <<iter << endl;
      }
      else{
        //siguiente aproximacion 
        x0 = x1;
        x1 = x2;
        x2 = x3;
        h1 = x1 - x0;
        h2 = x2 - x1;
        
        d1 = (f(x1)-f(x0))/h1;
        d2 = (f(x2)-f(x1))/h2;
        
        a = (d2 - d1)/(h2+h1);
        iter++;
      }
    }
    return encontrada;
  }
    
    double f(double x){
      return func(x);
    }
      string str(){
        return str_func;
      }
private:
          function<double(double)> func;
          string str_func;
};
#endif
