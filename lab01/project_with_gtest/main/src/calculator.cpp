#include "calculator.h"

bool calculator(int num){
    int right_figure, left_figure;
    while(abs(num) > 0){
        right_figure = num % 10;
        num = num / 10;
        left_figure = num % 10;
        if (right_figure < left_figure){
            return false;
        }
    }
    return true;
}
