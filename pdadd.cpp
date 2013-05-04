#include "datio.h"
#include "heure.h"

using namespace std;
int main (int argc, char **agrv){
    DAT da;
	iparse (da);    
    
    string todays;
    long int time = queLheure();
    
    char buffc, buff1, buff2;
    int flag = 0;
    buffc = getchar(); buff1 = buff2 = '\n';
    while (buffc != EOF) {
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
