#include <iostream>
#include <cmath>

#define LIMIT 1e-15

using namespace std;

/**Variables**/
    int p, q, r, s, t, u;
    
double f(double x){
        return (p*exp(-1 * x)+q*sin(x) + r*cos(x)+s*tan(x)+t*pow(x, 2) + u);
}

int main(){
    
    //Reading data until EOF
    while(cin>>p>>q>>r>>s>>t>>u){
        
        /** Binary search **/
        //Variables
        double x_inf = 0, x_sup = 1, x = -1, y = 0, result = -1;
        //Number of tests
        int n = 100;
        
        //We iterate to get more precision
        while(n--){
            
            x = (x_inf + x_sup) / 2;
            //We eavuate the function
            y = f(x);
            
            //We verify if y it's a too little number
            if(fabs(y) < LIMIT){
                break;
            } 
            
            //We check if y it's a positive value
            if(y > 0)
                x_inf = x;
            else
                x_sup = x;
        }
        
        if(x == 1)
            cout<<"No solution"<<endl;
        else
            printf("%.4f\n",x);
        
        
    }
    return 0;
}
