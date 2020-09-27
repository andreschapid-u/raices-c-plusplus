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
    
    double ef=0.0 , edf=0.0, Er=0.0 , p=0.0 , c=0.0 , efp=0.0;
    int i = 1 ; //el "paso 1"
    cout<<"\n"<<"\t -- p -- "<<"\t\t -- f(p) -- "<<"\t\t-- Er -- ";
    
    //el "paso 2"
    while(i <= max_iter)
    {
      ef = f(p0);
      edf = df(p0);
      c = ef / edf ; //   f(po) / f'(po)
      p = p0 - c;    //el "paso 3"
      efp = f(p);
      Er = (p - p0)/p;    if(Er<0) Er=Er*(-1); //esto es para ayudar al paso 4
      
      
      //presentacion de resultados iteracion a iteracion 
      cout<<"\n"<<i<<"\t";
      std::cout.setf( std::ios::fixed, std:: ios::floatfield );
      std::cout << p;
      std::cout.unsetf( std::ios::floatfield );
      std::cout.precision(10);
      std::cout<<"\t\t"; std::cout << efp;
      std::cout<<"\t\t"; std::cout << Er;
      
      //el "paso 4"
      if(Er<tolerancia) {cout<<"\n\nProcedimiento completado satisfactoriamente\n"; system("pause"); exit(1);}
      
      //el "paso 5"
      i = i + 1;
      
      //el "paso 6"  redefinicion de po
      p0 = p;
    }
    
    //el "paso 7"
    if((i>max_iter)||(Er>tolerancia)) {cout<<"\nEl metodo fracaso despues de "<<max_iter<<" iteraciones";}
    cout<<"\n"; system("pause");
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
