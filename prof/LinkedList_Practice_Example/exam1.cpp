#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_DEGREE 101 // 다항식의 최대차수 + 1

typedef struct { 
	int degree;
	float coef[MAX_DEGREE];
} polynomial;
//polynomial a = { 5, {10, 0, 0, 0, 6, 3} };

void print_poly(polynomial p){
    for(int i = p.degree; i >= 1; i--){
        if(p.coef[i])
            cout << p.coef[i] << "x^" << i << " + ";
    }
    if(p.coef[0]) cout << p.coef[0];
    cout << endl;
}

polynomial add_poly(polynomial p1, polynomial p2){
    polynomial p3;
    p3.degree = p1.degree < p2.degree ? p2.degree : p1.degree;

    for(int i = 0; i <= p3.degree; i++){
        p3.coef[i] = p1.coef[i] + p2.coef[i];
    }
    return p3;
}

polynomial sub_poly(polynomial p1, polynomial p2){
    polynomial p3;
    p3.degree = p1.degree < p2.degree ? p2.degree : p1.degree;

    for(int i = 0; i <= p3.degree; i++){
        p3.coef[i] = p1.coef[i] - p2.coef[i];
    }
    return p3;
}

polynomial mult_poly(polynomial p1, polynomial p2){
    polynomial p3;
    p3.degree = p1.degree + p2.degree;

    for(int i = 0; i <= p3.degree; i++){
        p3.coef[i] = 0;
    }
    for(int i = 0; i <= p1.degree; i++){
        for(int j = 0; j <= p2.degree; j++){
            p3.coef[i+j] += p1.coef[i] * p2.coef[j]; // 곱한 것을 누적해 나가야하는 것이 point.
        }
    }
    return p3;
}

int main(){
    cout << "----------------------" << endl;
    polynomial a = { 5,{ 3, 6, 0, 0, 0, 10, 0, 0, 0 } };
	polynomial b = { 4,{ 7, 0, 5, 0, 1,0, 0, 0,0,0  } };
	print_poly(a);
	print_poly(b);

    cout << "----------------------" << endl;
	print_poly(add_poly(a,b));
    print_poly(sub_poly(a,b));
    print_poly(mult_poly(a,b));

    return 0;
}