#include <cstring>
#include <string>

void leerarchivo(string archivo){
	string line;
  ifstream myfile (archivo.c_str());
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line; 
      
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  }
