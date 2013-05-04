#include "datio.h"


#include <fstream>
using std::ofstream;
using std::ifstream;

int outdat(char *a){
	ofstream fout ("dat");
    int i = 0;
	while (a[i] != EOF) {
        fout << a[i];
        i++;
    }
    fout << a[i];
	return 0;
}

int indat(char *a){
    ifstream fin ("dat");
    int i = 0;
    char buff;
    fin >> buff;
    while (buff != EOF) {
        a[i] = buff;
        i++;
        fin >> buff;
    }
    a[i] = EOF;
	return 0;
}

int iparse (DAT &da) {
    ifstream fin ("dat");
    long int date;
	string buffs;

	fin >> date;
    while (1) {
		if (date > 19900000 &&
			date < 20990000 ) {
			getline (fin, buffs, '\x1f');
			da[date] = buffs;	
		}
		else {
			break;
		}
		//else {
		//	ostd ("dat File parse Err");
		//	exit (1);
		//}
        date = 0;
		fin >> date;
	}
	
	return 0;
}

int oparse (DAT da) {
	ofstream fout ("dat");
    DAT::const_iterator map_i = da.begin();
	while (map_i != da.end()) {
        fout << map_i->first << endl
            << map_i->second << '\x1f';
        map_i++;
    }
    return 0;
}
