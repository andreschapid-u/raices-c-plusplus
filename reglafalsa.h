#ifndef REGLAFALSA_H
#define REGLAFALSA_H

#include <cmath>
#include <functional>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::function;
using std::ios;
using std::string;

class reglafalsa {
public:
  reglafalsa(
            function<double(double)> p_func,
            string p_str
            ):func(p_func),str_func(p_str) {
  }
  
  string str(){
    return str_func;
  }
  bool raiz(double xi, 
            double xs, 
            int max_iter, 
            double tolerancia,
            double &valor_raiz) {
    //TODO implementar regla falsa!!
    
    double xr=0.0, xra=0.0, fxi=0.0 , fxs=0.0, fxr=0.0 ;
    double validadorHayRaiz=0.0, exr=0.0, er=0.0, A=0.0 , B=0.0, C=0.0, D=0.0;
    int i = 1;
    /*cout.precision(10);
    cout.width(15);
    cout.fill('_');*/
    fxi=f(xi);
    fxs=f(xs);
    A = xi - xs;
    B = fxs * A;
    C = fxi - fxs;
    D = B/C;
    xr = xs - D;
    fxr = f(xr);
    
    cout<<"\n XR : "<<xr;
    cout<<"\n\tITER"<<"\t"<<"Raiz"<<"\t\t\t"<<"f(Raiz)"<<"\t\t\t"<<"Err"<< endl;
    
    while(i <= max_iter)
    {
      xra = xr;
      validadorHayRaiz = fxi * fxr;
      
      if(validadorHayRaiz < 0){
        xs=xr;
      }else{
        xi=xr;
      }  //todo esto para reajustar el intervalo
      
      fxi=f(xi);
      fxs=f(xs);
      A = xi - xs;
      B = fxs * A;
      C = fxi - fxs;
      D = B/C;
      xr = xs - D;
      fxr=f(xr);
      
      //Calculo del error relativo
      exr = xr - xra;  er = exr/xr;
      if(er<0){
        er=er*(-1);
      }
      
      //presentacion de resultados iteracion a iteracion 
      cout <<"\t" << i << "\t"<< cout.precision(10) << xr;
      cout << "\t\t" << cout.precision(10) << fxr <<"\t\t" << cout.precision(10) << er << endl;
      
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
            
private:
  function<double(double)> func;
  string str_func;
  
  double f(double x){
    return func(x);
  }
};

#endif
