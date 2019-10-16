#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

class Complejo{

    public:
        float p_real;
        float p_imag;


        string toString(){
            stringstream ss;

            ss << "(" << p_real << "," << p_imag << ")";
            return ss.str();
        }

        Complejo (float r, float i ){
            p_real = r;
            p_imag = i;
            
        }

        Complejo(){}

        Complejo operator+ (Complejo segundo){
            float a1 = p_real;
            float b1 = p_imag;
            float a2 = segundo.p_real;
            float b2 = segundo.p_imag;

            Complejo resultado(a1+a2,b1+b2);
    
            return resultado;

        }

        Complejo operator- (Complejo segundo){
            float a1 = p_real;
            float b1 = p_imag;
            float a2 = segundo.p_real;
            float b2 = segundo.p_imag;

            Complejo resultado(a1-a2,b1-b2);
    
            return resultado;

        }

        void operator- (){
            p_real = -p_real;
            p_imag = -p_imag;

        }

        void operator+= (Complejo segundo){
    
            p_real=p_real+segundo.p_real;
            p_imag=p_imag+segundo.p_imag;
    

        }

        void operator<< (Complejo segundo){
            p_real=p_real+segundo.p_real;
            p_imag=p_imag+segundo.p_imag;

            segundo.p_real=0;
            segundo.p_imag=0;
    

        }

        bool operator> (Complejo segundo){

            float moduloSegundo = sqrt((segundo.p_real*segundo.p_real)+(segundo.p_imag*segundo.p_imag));
            float moduloPrimero = sqrt((p_real*p_real)+(p_imag*p_imag));
            
            if (moduloPrimero > moduloSegundo){
                return true;
            }else{
                return false;
            }
            

            

        }

        bool operator< (Complejo segundo){
            return !((*this) > segundo);
        }

        /*void operator++ (Complejo  num){
            num.p_imag=num.p_imag+1;
            num.p_real=num.p_real+1;
        }

        */


};

/*Complejo operator+ (Complejo primero, Complejo segundo){
    float a1 = primero.p_real;
    float b1 = primero.p_imag;
    float a2 = segundo.p_real;
    float b2 = segundo.p_imag;

    Complejo resultado(a1+a2,b1+b2);
    
    return resultado;

}

Complejo operator- (Complejo primero, Complejo segundo){
    float a1 = primero.p_real;
    float b1 = primero.p_imag;
    float a2 = segundo.p_real;
    float b2 = segundo.p_imag;

    Complejo resultado(a1-a2,b1-b2);
    
    return resultado;

}

Complejo operator- (Complejo num){
    

    Complejo resultado(-num.p_real,-num.p_imag);
    
    return resultado;

}

void operator<< (Complejo & primero, Complejo & segundo){
    primero.p_real=primero.p_real+segundo.p_real;
    primero.p_imag=primero.p_imag+segundo.p_imag;

    segundo.p_real=0;
    segundo.p_imag=0;
    

}

void operator+= (Complejo & primero, Complejo  segundo){
    
    primero.p_real=primero.p_real+segundo.p_real;
    primero.p_imag=primero.p_imag+segundo.p_imag;
    

}

void operator++ (Complejo & num){
    num.p_imag=num.p_imag+1;
    num.p_real=num.p_real+1;
}*/

int main(int argc, char *argv[]){
    
    Complejo a(-2,1);

    Complejo b(3,5);

    Complejo c(4,-3);

    //b += a;

    //c << a;

    //c++;

    //cout << c.toString() << endl;

    //cout << a.toString() << endl;

    /*a = b + c;

    a += b;

    a << b;

    a[1];

    if (a == b)
    if (a == 0)

    a = -b;
    */
    //cout << c.toString() << endl;

    if (a < b){
        cout << "a es menor que b" << endl;
    }else{
        cout << "a es mayor que b" << endl;
    }
    
}