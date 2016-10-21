#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

template<class Type>
class use_gnuplot
{
private:
  string PARA_VAL;
  string FILE_NAME;
  string PARA_NAME;
  string GP_FILENAME;
public:
  void setprm(const char *parameter_name_, Type parameter_);
  void get_fn(const char *file_name);
  void plot(const char *gp_filename);
//  void plot(char *file_name);
  void open_pdf();

};

template<class Type>
void use_gnuplot<Type>::setprm(const char *parameter_name, Type parameter_)
{
  double test = 5;
  stringstream ss;
  ss << test;
  PARA_VAL = ss.str(); // http://marycore.jp/prog/cpp/convert-number-to-string/を参考にした。

  PARA_NAME = parameter_name;
//  PARA_VAL = to_string(parameter_);
  FILE_NAME = PARA_NAME + "_is_" + PARA_VAL + ".eps";
}

template<class Type>
void use_gnuplot<Type>::get_fn(const char *file_name)
{
  file_name = FILE_NAME.c_str();
}

template<class Type>
void use_gnuplot<Type>::plot(const char *gp_filename)
{
  GP_FILENAME = gp_filename;
  string COMMAND_TO_GNUPLOT;
  COMMAND_TO_GNUPLOT = "gnuplot -e \"set term postscript eps enhanced color 24; set output \'" + FILE_NAME + "\'; \" " + GP_FILENAME;
  system(COMMAND_TO_GNUPLOT.c_str());
//  cout << COMMAND_TO_GNUPLOT << endl;
  cout << "gogo" << endl;
}

template<class Type>
void use_gnuplot<Type>::open_pdf()
{
  string OPEN_FILE_COMMAND;
  OPEN_FILE_COMMAND = "open " + FILE_NAME;
  system(OPEN_FILE_COMMAND.c_str());
//  cout << OPEN_FILE_COMMAND << endl;
}
/*
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
*/
  
