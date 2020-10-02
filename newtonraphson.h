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
  
  string str(){
    return str_func;
  }
    
  bool raiz(double p0, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    //TODO implementar Newton Raphson!!
    
    cout.precision(10);
    // cout.width(12);
    // std::scientific;
    
    double Er=0.0 , p=0.0 , c=0.0;
    int i = 1 ; //el "paso 1"
    cout<<"\n"<<"\t -- p -- "<<"\t\t -- f(p) -- "<<"\t\t-- Er -- ";
    
    //el "paso 2"
    while(i <= max_iter)
    {
      c = f(p0) / df(p0) ; //   f(po) / f'(po)
      p = p0 - c;    //el "paso 3"
      Er = fabs((p - p0)/p);   
      if(Er<0)
        Er=Er*(-1); //esto es para ayudar al paso 4
      
      
      //presentacion de resultados iteracion a iteracion 
      cout<<"\n"<<i<<"\t";
      std::cout << p;
      std::cout<<"\t\t"; std::cout << f(p);
      std::cout<<"\t\t"; std::cout << Er;
      
      //el "paso 4"
      if(Er<tolerancia){
        cout<<"\n\nProcedimiento completado satisfactoriamente\n";
        valor_raiz = p0;
        cout<<"\nNumero de Iteraciones: " <<i << endl;
        return true;
      }
      
      //el "paso 5"
      i = i + 1;
      
      //el "paso 6"  redefinicion de p0
      p0 = p;
    }
    
    //el "paso 7"
    if((i>max_iter)||(Er>tolerancia)) {
      cout<<"\nEl metodo fracaso despues de "<<max_iter<<" iteraciones";
    }
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
