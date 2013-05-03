#include "datio.h"
#include "heure.h"

using namespace std;
int main (int argc, char *agrv[]){
    DAT da;
	iparse (da);    
    
    string todays, buffs;
    long int time = queLheure();
    cin >> buffs;
    while (buffs != "." && !buffs.empty()) {
        todays += buffs;
        buffs.erase();
        cin >> buffs;
    }    
    da[time] = todays;
     
    oparse (da);
    return 0;
}
