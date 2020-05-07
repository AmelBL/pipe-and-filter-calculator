#include "calcul.h"
#include <string.h>
#include <stdio.h>


int main(){
    
    int choix,a,b;
    scanf( "%d",&choix );
    switch (choix){
         case 1: {
              scanf("%d",&a);
              scanf("%d",&b);
              printf("%d + %d = %ld \n",a,b,somme(a,b));
              break;
            }
         case 2: {
              scanf("%d",&a);
              scanf("%d",&b);
              printf("%d * %d = %ld\n",a,b,prod(a,b));
              break;
            }
         case 3: {
              scanf("%d",&a);
              printf("%d! = %ld \n",a,fact(a));
              break;
            }

        }
}


long int somme(int c, int d){

return c+d;
}
long int prod(int c, int d){

return c*d;
}

long int f(int n){
 long int r;
 if (n<=1) r=1;
    else r= n*f(n-1);
 return r;
}

long int fact(int n){
long int r;
r = f(n);

 return (r);
}
