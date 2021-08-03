#include "MyMultiply.h"
#include <chrono>
#include <fstream>
#include <iomanip>
int main()
{
      string str1;
	  string str2;
	  string result;
	  string Kartsuba_res;
	  string Iterative_Kartsuba_res;
	  char* res; 
	  string n;
	  int size;
	  cin >> n;
	  size = Is_Size_Valid(n);
	  cin >> str1;
	  cin >> str2;
	  Kartsuba_res = Pow_Ten(Kartsuba_res, 2 * size);
	  Iterative_Kartsuba_res = Pow_Ten(Iterative_Kartsuba_res, 2 * size);
	  if (!Is_Valid_Input(str1, str2, size))
		  exit(0);

	  //***************************************************************
	  //*            measure complexity of 3 algorithems              *
	  //***************************************************************

	  auto start = chrono::high_resolution_clock::now();
	  // unsync the I/O of C and C++.
	  ios_base::sync_with_stdio(false);
	  res = Long_Multiply(str1, str2);
	  auto end = chrono::high_resolution_clock::now();
	  // Calculating total time taken by the program.
	  double time_taken =
	 chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	  time_taken *= 1e-9;
	  ofstream myfile("Measure.txt"); // The name of the file
	  myfile << "Time taken by function Long_Multiply is : " << fixed
		  << time_taken << setprecision(9);
	  myfile << " sec" << endl;
	 
	  result = CharArrToString(res, 2 * size);
	
	  start = chrono::high_resolution_clock::now();
	  // unsync the I/O of C and C++.
	  ios_base::sync_with_stdio(false);
	  Kartsuba(str1, str2, size, Kartsuba_res);
	 end = chrono::high_resolution_clock::now();
	  // Calculating total time taken by the program.
	   time_taken =
		  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	  time_taken *= 1e-9;
	 
	  myfile << "Time taken by function Kartsuba is : " << fixed
		  << time_taken << setprecision(9);
	  myfile << " sec" << endl;
	
	   start = chrono::high_resolution_clock::now();
	  // unsync the I/O of C and C++.
	  ios_base::sync_with_stdio(false);
	  Iterative_Kartsuba(str1, str2, size, Iterative_Kartsuba_res);
	   end = chrono::high_resolution_clock::now();
	  // Calculating total time taken by the program.
	   time_taken =
		  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	  time_taken *= 1e-9;
	  myfile << "Time taken by function Iterative_Kartsuba is : " << fixed
		  << time_taken << setprecision(9);
	  myfile << " sec" << endl;
	  myfile.close();

	  //Print the results
	  cout << "Long multiplication : x * y = ";
	  Print_result(result);
	  cout << "Karatsuba(recursive) : x * y = ";
	  Print_result(Kartsuba_res);
	  cout << "Karatsuba(iterative) : x * y = ";
	  Print_result(Iterative_Kartsuba_res);
	  delete[] res;
	  return 0;

}