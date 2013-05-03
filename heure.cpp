#include "heure.h"


#include <ctime>
#include <sstream>
#include <iostream>
using namespace std;

long int queLheure() {
//fetch time
    time_t rawtime;
    time ( &rawtime );
    const tm* timeinfo = localtime ( &rawtime );    
    char yyyymmddc[11];
    strftime( yyyymmddc, sizeof(yyyymmddc), "%Y/%m/%d", timeinfo );
	return conLheure(yyyymmddc);    
}

long int conLheure(char* yyyymmddc) {
	//convert to long int
    string  yyyymmdds = yyyymmddc;
    istringstream strstrm(yyyymmdds);
    long int yeari, monthi, dayi;
    char ignore;
    strstrm >> yeari >> ignore >> monthi >> ignore >> dayi;
    if (!( yeari > 1970 && yeari < 2100 && monthi > 0
          && monthi < 13 && dayi > 0 && dayi < 32)) {
        cout << "illeagal date";
        exit(1);
    }
	return yeari * 10000 + monthi * 100 + dayi;
}
