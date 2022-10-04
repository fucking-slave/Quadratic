#include <stdio.h>
#include <math.h>
#include <string.h>





const double zero = 0.00000001;

//test: checks if the solutions of equation equal y1 and y2
int test(double a, double b, double c, double y1, double y2);

//tester: prints result of all tests
void tester();

void printInfo();

void scanArg(double* a, double* b, double* c);

//Solver: returns number_of_roots, returning -1 means infinite number of roots
//SOlver: x1 - maxRoot x2 - minRoot(if number_of_roots is 2)
int Solver(double a, double b, double c, double* x1, double* x2);

int SolveQuadratic(double a, double b, double c, double* x1, double* x2);

int SolveLinear(double b, double c, double* x1);


int main()
{
    tester();//Comment this to use autotesting
    printInfo();
    char comand[5];
    char YES[5] = "YES";
    do
    {
        printf("\n");
        double a = 0, b = 0, c = 0;
        scanArg(&a, &b, &c);

        double x1 = NAN, x2 = NAN;
        int num_of_roots = Solver(a, b, c, &x1, &x2);
        if(num_of_roots == -1) {printf("This equation has infinite number of roots\n\n");}
        else if(num_of_roots == 0) {printf("This equation has no roots\n\n");}
        else
        {
            printf("This equation has %d root(-s)\n", num_of_roots);
            if(num_of_roots == 1){printf("The root is %lf\n\n", x1);}
            else{printf("The roots are: %lf, %lf\n\n", x1, x2);}
        }
        printf("Do you want to solve another?(YES/NO)\n");
        scanf("%s", comand);
    } while(!strcmp(comand, YES));
    return 0;
}

int Solver(double a, double b, double c, double* x1, double* x2)
{
    if(fabs(a) > zero){return SolveQuadratic(a, b, c, x1, x2);}
    else
    {
        if(fabs(b) > zero){return SolveLinear(b, c, x1);}
        else
        {
            if(fabs(c) > zero){return 0;}
            else {return -1;} //returning -1 means infinite number of roots
        }
    }
}

int SolveQuadratic(double a, double b, double c, double* x1, double* x2)
{
    if(fabs(a) < zero){return SolveLinear(b, c, x1);}

    double discr = b*b - 4*a*c;
    if(fabs(discr) > discr){return 0;} //check
    if(fabs(discr) < zero){*x1 = (-b) / (2*a); return 1;}
    *x1 = (-b + sqrt(discr)) / (2*a);
    *x2 = (-b - sqrt(discr)) / (2*a);
    return 2;
}

int SolveLinear(double b, double c, double* x1)
{
    if(fabs(b) < zero)
    {
        if(fabs(c) > zero){return 0;}
        else{return -1;}
    }

    *x1 = (-c) / b;
    return 1;
}



//later


void scanArg(double* a, double* b, double* c)    //óïðîñòèòü
{
    printf("Enter a: ");
    while(scanf("%lf", a) != 1)
    {
        printf("\nERROR, the value is wrong\n");
        printf("Enter a: ");
        fflush(stdin);
    }

    printf("Enter b: ");
    while(scanf("%lf", b) != 1)
    {
        fflush(stdin);
        printf("\nERROR, the value is wrong\n");
        printf("Enter b: ");
    }

    printf("Enter c: ");
    while(scanf("%lf", c) != 1)
    {
        fflush(stdin);
        printf("\nERROR, the value is wrong\n");
        printf("Enter c: ");
    }
}

void printInfo()
{
    printf("Hello, I'm Dima\nThis function solves the quadratic equation\nQuadratic equation looks like:\n\ax^2 + bx + c = 0\n");
}


//TESTING SYSTEM
//Remove comments below to use autotesting

void tester()
{
    if(test(0, 0, 0, NAN, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(0, 0, 1, NAN, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(0, 1, 0, 0, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(0, 1, 1, -1, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 0, 0, 0, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 0, 1, NAN, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 1, 0, 0, -1)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 1, 1, NAN, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 0, -1, 1, -1)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 3, 2, -1, -2)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}

    if(test(1, 2, 1, -1, NAN)){printf("YES\n");}
    else{printf("NO, FUCK YOU\n");}
}


int test(double a, double b, double c, double y1, double y2)
{
    double x1 = NAN, x2 = NAN;
    Solver(a, b, c, &x1, &x2);

    if(isfinite(x1) && isfinite(x2))
    {
        if(fabs(x1 - y1) < zero && fabs(x2 - y2) < zero){return 1;}
        else{return 0;}
    }

    if(isnan(x1) && isnan(x2) && isnan(y1) && isnan(y1)){return 1;}
    else if(isnan(x1) && isnan(y1) && isfinite(x2) && isfinite(y2) && (fabs(x2 - y2) < zero)){return 1;}
    else if(isfinite(x1) && isfinite(y1) && isnan(x2) && isnan(y2) && (fabs(x1 - y1) < zero)){return 1;}
    else{return 0;}
}
