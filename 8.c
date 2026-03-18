
//Problem: Given integers a and b, compute a^b using recursion without using pow() function.
# include <stdio.h>
double power(int a,int b){
    if(b<0){
        return 1.0/power(a,-b);
    }
    if(b==0){
        return 1;
    }
    return a*power(a,b-1);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%lf",power(a,b));
    return 0;
}
