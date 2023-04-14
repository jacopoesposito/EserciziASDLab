using namespace std;

#include <unordered_map>
#include <iostream>
#include <string>


unordered_map<int, int> solmap;

int fib(int n);

int main(int argc, char* argv[]){

    int val;
    if(argc > 1){
        val = stoi(argv[1]);
    }
    else
        return -1;
    
    cout << "Il numero di fibonacci di " << val << " ->" << fib(val) << endl;

}

int fib(int n){
    if( n <= 1)
        return n;
    if(solmap.count(n))
        return solmap[n];
    int res = fib(n-1) + fib(n-2);
    solmap[n] = res;
    return res;
}