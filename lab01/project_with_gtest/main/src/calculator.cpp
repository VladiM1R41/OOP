#include "calculator.h"

bool calculator(int num){
    int right_figure, left_figure;
    if (num < 0){
        num = -num;
        while(num > 99){
            right_figure = num % 10;
            num = num / 10;
            left_figure = num % 10;
            if (right_figure < left_figure){
                return false;
            }
        }   
        return true;
    }
    else{
        while(num > 0){
            right_figure = num % 10;
            num = num / 10;
            left_figure = num % 10;
            if (right_figure < left_figure){
                return false;
            }
        }
        return true;
    }
}
