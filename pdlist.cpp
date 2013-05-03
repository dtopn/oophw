#include "datio.h"
#include "heure.h"

#include <string>
using namespace std;

int main (int argc, const char * argv[] ) {
    DAT da;
	iparse (da);
    
	if ( argc != 1 && argc != 3) {
        ostd("Wrong command\n");
        exit(1);
    }
    DAT::const_iterator map_begin = da.begin();
    DAT::const_iterator map_end = da.end();
    DAT::const_iterator map_i;
    if ( argc == 3 ) {
    	long int day1, day2;
        if ( (strlen(argv[1]) != 10) && (strlen(argv[2]) != 10) ) {
            ostd("Illeagal date\n");
            exit(1);
        }
        
        day1 = conLheure(argv[1]);
        day2 = conLheure(argv[2]);
        if (day1 > day2) {
            day1 ^= day2 ^= day1 ^= day2;
        }

        map_i = map_begin;
        while ( map_i->first > day1 && (map_i != map_end) ) {
            map_i++;
        }
        ///Users/yuanzhanghao/Nutstore/wkspace/oophw/pdlist.cpp:36:45: Invalid operands to binary expression ('DAT::const_iterator' (aka '__map_const_iterator<typename __base::const_iterator>') and 'DAT::const_iterator')
        map_begin = map_i;
        while (map_i->first < day2 && map_i != map_end) {
            map_i++;
        }
        map_end = map_i;
	}
    
    map_i = map_begin;
    while (map_i != map_end) {
        ostd(map_i->first);
        ostd("\n");
        
        
        map_i ++;
    }
    return 0;
}
