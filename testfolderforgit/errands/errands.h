#include <sstream>
using namespace std;
template <class T>
string ttostring(T var){
	ostringstream sstream;
	sstream << var;
	string stri = sstream.str();
	return stri;
}