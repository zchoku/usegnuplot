#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

class EneDis
{
private:
  double t, tp, tpp;
public:
  EneDis(double t_, double tp_, double tpp_);
  double Enek(double kx, double ky);
};
EneDis::EneDis(double t_, double tp_, double tpp_)
{
  t = t_;
  tp = tp_;
  tpp = tpp_;
}
double EneDis::Enek(double kx, double ky)
{
  double E_k = - 2*t*(cos(kx) + cos(ky) ) - 4*tp*cos(kx) * cos(ky) -
    2*tpp*(cos(2*kx) + cos(2*ky) );
  return E_k;
}


int main(int argc, char *argv[])
{
  if(argc!=4) {
    cout << "a.out t t' t'' \n";
    return 1;
  }
  
  double t = atof(argv[1]);
  double tp = atof(argv[2]);
  double tpp = atof(argv[3]);

  int N = 100;//分割数
  
  EneDis ob(t, tp, tpp);

  // (0,0) to (0,PI)
  ofstream out1("GtoX");
  if(!out1){
    cout << "cannot open file. \n";
    return 1;
  }
  for(int i=0; i<N; i++)
    {
      double kx = M_PI/N*i;
      out1 << kx << " " << ob.Enek(kx, 0) << '\n';
    }
  out1.close();
    // (0,PI) to (PI,PI)
  ofstream out2("XtoM");
  if(!out2){
    cout << "cannot open file. \n";
    return 1;
  }
  for(int i=0; i<N; i++)
    {
      double ky = M_PI/N*i;
      out2 << ky << " " << ob.Enek(M_PI, ky) << '\n';
    }
  out2.close();
    // (PI,PI) to (0,0)
  ofstream out3("MtoG");
  if(!out3){
    cout << "cannot open file. \n";
    return 1;
  }
  for(int i=0; i<N; i++)
    {
      double kxy =M_PI - M_PI/N*i;
      out3 << kxy << " " << ob.Enek(kxy, kxy) << '\n';
    }
  out3.close();
    string t_st, tp_st, tpp_st;
    t_st = argv[1];
    tp_st = argv[2];
    tpp_st = argv[3];

    string FILE_NAME = t_st + "_" + tp_st + "_"+ tpp_st + ".eps";
    string OPEN_FILE_NAME = "open " + t_st + "_" + tp_st + "_"+ tpp_st + ".eps";
    string command = "gnuplot -e \"namae = \'" + FILE_NAME + "\';\" 2d_band.gp" ;
    
    
    const char *open_gnu = NULL;
    open_gnu = command.c_str();
//    cout << open_gnu;
    system(open_gnu);
    
    const char *open_eps = NULL;
    open_eps = OPEN_FILE_NAME.c_str();
    system(open_eps);
  return 0;
}
  
