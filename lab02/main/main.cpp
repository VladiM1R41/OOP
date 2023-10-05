#include <iostream>
#include "Binary.h"


int main(){

    Binary ds1 {'1','0','1'};
    std::cout << ds1 << std::endl;

    Binary ds2{'1','0','1'};
    std::cout << ds2 << std::endl;

    Binary ds5 = {'0','1','0','1',};
    if(ds5.equals(ds1.add(ds2))){
        std::cout << "==\n";
    }
    std::cout << ds5 << std::endl;
    std::cout << ds1.is_bigger(ds2) << "\n";
    Binary ds3(ds1.add(ds2));
    std::cout << ds3 << std::endl;

    Binary ds4(std::move(ds3));
    std::cout << ds4 << std::endl;

    try{

        Binary ds5 = ds4.remove(ds2);
        std::cout << ds5 << std::endl;

        Binary ds6 = ds2.remove(ds4);
        std::cout<< ds5 << std::endl;

    }catch(std::exception &ex){
        std::cerr << "exception:" << ex.what() << std::endl;
    }

    return 1;
}