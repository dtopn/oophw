#include "datio.h"
#include "heure.h"

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
    
    long int time = conLheure(argv[1]);
    
    string todays;
//    long int time = queLheure();
    
    char buffc, buff1, buff2;
    buffc = getchar(); buff1 = buff2 = '\n';
    while (buffc != EOF && buffc != '\x04') {
        todays += buffc;
        
        if (buff1 == '\n' && buffc == '\n' && buff2 == '.') {
            break;
        }
        buff1 = buff2, buff2 = buffc;
        buffc = getchar();
    }
//    string buffs;
//    getline(cin, buffs);
//    while (buffs != "." && !buffs.empty()) {
//        todays += buffs;
//        todays += '\n';
//        getline(cin, buffs);
//    }
    
    da[time] = todays;
     
    oparse (da);
    return 0;
}
