#include <iostream>

double sqrt(int n, int precision = 2){
    int s = 0;
    int e = n;

    float ans = 0;
    while(s <= e){
        int m = (e + s)/2;
        int curr = m * m;
        if(curr == n){
            ans = m;
            break;
        }

        if(curr < n ){
            s = m + 1;
            ans = m;
        }
        else{
            e = m - 1;
        }
    }
    // For computing the fractional part
    // of square root upto given precision
    float increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= n) {
            ans += increment;
        }

        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

int main(){

    std::cout<<"Sqrt of 10 is: "<< sqrt(10)<< std::endl;
    return 0;
}
