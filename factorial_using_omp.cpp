#include <iostream>
#include <omp.h>    
using namespace std;

int main(){
    long input,fact=1;
    cout << "Enter number for calculation of factorial\n";
    cin >> input;
    #pragma omp parallel for reduction(*:fact)
    for(int i=input;i>=1;i--){
        cout << i << "\n";
        fact = i*fact;
    }
    cout << fact << "\n";
    return 0;
}