#include <iostream>
#include "reglafalsa.h"
#include "newtonraphson.h"
#include "secante.h"
#include <functional>

using std::function;

//Caso 1: x^2 - cos(x)
void raices_caso_1();

int main(int argc, char *argv[])
{

  //Caso 1: x^2 - cos(x)
  function<double(double)> f = [](double x) -> double {
    double x2 = x * x;
    double x3 = x * x * x;
    double x4 = x * x * x * x;
    return (x4 + 2 * x3 - 12 * x2 + 14 * x - 5);
  };

  reglafalsa rf(
      f, "X^4 + 2X^3 - 12X^2 + 14X - 5");

  double xi = -6.0;
  double xs = -4.0;
  double raiz = 0.0;
  double tolerancia = 0.00001;
  int max_iter = 1000;
  cout << "f(x): " << rf.str() << endl;
  rf.raiz(xi, xs, max_iter, tolerancia, raiz);

  //raices_caso_1();

  return 0;
}

void raices_caso_1()
{
  double a = 0.0;
  double b = 2.5;
  double raiz = 0.0;
  int max_iter = 100;
  double tolerancia = 0.00001;
  /* x^2 - cos(x) */
 
  //Regla falsa
  reglafalsa r1(
      [](double x) -> double {
        return ((x * x) - cos(x));
      },
      "x^2 - cos(x)");

  double xi = 0.0;
  double xs = 2.0;
  if (r1.raiz(xi, xs, max_iter, tolerancia, raiz))
  {
  }
  double p0 = 1.0;
  newtonraphson n1(
      [](double x) -> double {
        return ((x * x) - cos(x));
      },
      [](double x) -> double {
        return ((2 * x) + sin(x));
      },
      "x^2 - cos(x)");

  if (n1.raiz(p0, max_iter, tolerancia, raiz))
  {
  }

  //Secante
  secante s1(
      [](double x) -> double {
        return ((x * x) - cos(x));
      },
      "x^2 - cos(x)");

  double x0 = 0.0;
  double x1 = 2.0;
  if (s1.raiz(x0, x1, max_iter, tolerancia, raiz))
  {
  }
}
