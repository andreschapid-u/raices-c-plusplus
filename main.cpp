#include <iostream>
#include <functional>
#include <string>

#include "muller.h"
#include "newtonraphson.h"
#include "reglafalsa.h"
#include "secante.h"
#include "steffensen.h"

using std::function;

//Caso 1: x^2 - cos(x)
void raices_caso_1();

int main(int argc, char *argv[])
{
  raices_caso_1();

  return 0;
}

void raices_caso_1()
{
  //Funcion: x^4+2x^3-12x^2+14x-5
  function<double(double)> fun = [](double x) -> double {
    double x2 = x * x;
    double x3 = x * x * x;
    double x4 = x * x * x * x;
    return (x4 + 2*x3 - 12*x2 + 14*x - 5);
  };
  
  //Derivada de la funcion 4x^3 + 6x^2 - 24x + 14
  function<double(double)> dev_fun = [](double x) -> double {
    double x2 = x * x;
    double x3 = x * x * x;
    return (4*x3 + 6*x3 - 24*x + 14);
  };
  
  string str_fun = "X^4 + 2X^3 - 12X^2 + 14X - 5";
  double tolerancia = 0.00000001;
  double raiz = 0.0;
  int max_iter = 1000;
  
  //Regla falsa
  reglafalsa rf( fun, str_fun);
  cout << "\n\tRegla falsa" << "\t f(x)= " << str_fun << endl;
  double xi = -1.0;
  double xs = -7.0;
  if(rf.raiz(xi, xs, max_iter, tolerancia, raiz)){
    cout<<"La raiz de "<<rf.str() << " es => "<<std::setprecision(10)<<raiz<<endl;
  }else{
    cout << "\nNo se encontro la riaz!" << endl;
  }
  system("pause");
  system("cls");
  
  // Newton Raphson
  double p0 = -2.0;
  raiz = 0.0;
  newtonraphson n1(fun, dev_fun, str_fun);
  cout << "\n\tNewton Raphson" << "\t f(x)= " << str_fun << endl;
  if (n1.raiz(p0, max_iter, tolerancia, raiz)){
    cout<<"La raiz de "<<n1.str() << " es => "<<std::setprecision(10)<<raiz<<endl;
  }else{
    cout << "\nNo se encontro la riaz!" << endl;
  }
  system("pause");
  system("cls");
  
  //Secante
  secante s1(fun, str_fun);
  cout << "\n\tSecante" << "\t f(x)= " << str_fun << endl;
  double x0 = -4.0;
  double x1 = -2.0;
  raiz = 0.0;
  if (s1.raiz(x0, x1, max_iter, tolerancia, raiz)){
    cout<<"La raiz de "<<s1.str() << " es => "<<std::setprecision(10)<<raiz<<endl;
  }else{
    cout << "\nNo se encontro la riaz!" << endl;
  }
  system("pause");
  system("cls");
  
  
  //Muller
  muller m1(fun, str_fun);
  cout << "\n\tMuller" << "\t f(x)= " << str_fun << endl;
  double m_x0 = -7.0;
  double m_x1= -6.0; 
  double m_x2 = -5.5;
  raiz =0.0;
  
  if(m1.raiz(m_x0, m_x1, m_x2, max_iter, tolerancia, raiz)){
    cout<<"La raiz de "<<m1.str() << " es => "<<std::setprecision(10)<<raiz<<endl;
  }else{
    cout<<"\nNo se encontro la raiz de " <<m1.str() <<endl;
  }
  system("pause");
  system("cls");
  
  //Steffensen
  steffensen s(fun, str_fun);
  double s_x0 = 0.5;
  cout << "\n\tSteffensen" << "\t f(x)= " << str_fun << endl;
  if(s.raiz(s_x0, max_iter, tolerancia, raiz)){
    cout<<"La raiz de "<<s.str() << " es => "<<std::setprecision(10)<<raiz<<endl;
  }else{
    cout<<"\nNo se encontro la raiz de " <<m1.str() <<endl;
  }
  system("pause");
}
