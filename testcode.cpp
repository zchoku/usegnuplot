#include <iostream>
#include "use_gnuplot.hpp"
using namespace std;

int main()
{
  
  //double型でパラメータを与える
  double t = 10;
  use_gnuplot<double> ob;
  ob.setprm("t",t);
  char *FILE_NAME = NULL;
  ob.get_fn(FILE_NAME);
  cout << FILE_NAME << endl;
//  ob.plot(FILE_NAME);
  //or
  ob.plot("sin.gp");

  //charでパラメータを与える
  const char *para = "3";
  use_gnuplot<const char*> ob2;
  ob2.setprm("para", para);
  ob2.plot("sin.gp");
  
  //pdfファイルを開く機能も実装する
//  ob.open_pdf();

  return 0;
}
