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
    
    
    double xr=0.0, xra=0.0, fx0=0.0 , fx1=0.0, fxr=0.0 ;
    double er=0.0, A=0.0 , B=0.0, C=0.0, D=0.0;
    int i = 1;
    cout.precision(10);
    // cout.width(12);
    // std::scientific;
    fx0=f(x0);    
    fx1=f(x1);
    A = x0 - x1;    
    B = fx1 * A;     
    C = fx0 - fx1;    
    D = B/C;   
    xr = x1 - D;
    
    cout<<"\n XR : "<<xr;    fxr = f(xr);
    cout<<"\n"<<"n"<<"\t"<<"Raiz"<<"\t\t\t"<<"f(raiz)"<<"\t\t\t"<<"Er";
    
    while(i <= max_iter)
    {
      xra = xr;
      x0 = x1;   
      x1 = xr;  //reajuste
      fx0=f(x0);  
      fx1=f(x1);
      A = x0 - x1;     
      B = fx1 * A;
      C = fx0 - fx1;
      D = B/C;  
      xr = x1 - D;
      fxr=f(xr);
      
      //Calculo del error relativo
      er = (xr - xra)/xr;
      er = fabs(er);
      
      //presentacion de resultados iteracion a iteracion 
      cout<<"\n"<<i<<"\t";
      std::cout << xr<<"\t";
      std::cout<<"\t\t"; std::cout << fxr;
      std::cout<<"\t\t"; std::cout << er;
      
      //si se tiene exito:
      if((fxr==0)||(er<tolerancia)){
        cout<<"\nProcedimiento completado satisfactoriamente\n";
        valor_raiz = xr;
        return true;
      }
      
      i++;
    }
    
    if( (i>max_iter) && (er>tolerancia) ){
      cout<<"\nEl metodo fracaso despues de "<<max_iter<<" iteraciones";
    }
    
    return false;
  }
            
  string str(){
    return str_func;
  }
private:
  function<double(double)> func;
  string str_func;
  
  double f(double x) {
    return func(x);
  }
};


#endif
