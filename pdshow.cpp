#include "datio.h"
#include "heure.h"

#include <string>
using namespace std;

int main (int argc, const char * argv[] ) {
    DAT da;
	iparse (da);
    
	if ( argc != 2) {
        ostd("Wrong command\n");
        exit(1);
    }
    if ( (strlen(argv[1]) != 10) ) {
        ostd("Illeagal date\nEnter yyyy/mm/dd\n");
        exit(1);
    }
    
    long int day = conLheure(argv[1]);
    
    DAT::const_iterator map_i;
    map_i = da.find((DAT::key_type) day);
    if (map_i == da.end()) {
        ostd("No such entry.\n");
        exit(1);
    }
    ostd(map_i->second);
    //ostd("\n"); 
    return 0;
}
