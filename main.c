#include <stdio.h>

int lenHelper(unsigned x) {
    if (x >= 1000000000) return 10;
    if (x >= 100000000)  return 9;
    if (x >= 10000000)   return 8;
    if (x >= 1000000)    return 7;
    if (x >= 100000)     return 6;
    if (x >= 10000)      return 5;
    if (x >= 1000)       return 4;
    if (x >= 100)        return 3;
    if (x >= 10)         return 2;
    return 1;
}

float absolute_val(float a){
    if(a < 0){
        return -1 * a;
    }
    else return a;
}

float cal_accuracy(float base, float attained){
    if (base > attained){
        return (1-((base-attained)/base))*100;
    }
    else{
        return (1-((attained-base)/base))*100;
    }
}

float bab_sq_root_helper(int a, float x){
    return (0.5*(x + (a/x)));
}

float bab_sq_root(int a){

    int len_a = lenHelper(a);
    
    float x = len_a * 10^2;

    for(int i=0;i<=len_a;i++){
        x = bab_sq_root_helper(a, x);
    }
    return x;
}

int main () {
    int num = 100;

    float sq_val = bab_sq_root(num);
    float percent_accuracy = cal_accuracy(num, sq_val*sq_val);

    printf("the square root of %i is %f, which is %f percent accurate(square is %f)\n", num, sq_val, percent_accuracy, sq_val*sq_val);

    return 1;
}