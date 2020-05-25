#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <map>

int main(int arc, char* argv[]){
    using namespace std;
    map<string, int> m;
    
    m["sample"]++; // Added without checking, lets see

    cout << m["sample"] << "\n"; 
    return 0;
}
