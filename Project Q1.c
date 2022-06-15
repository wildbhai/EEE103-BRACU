#include <stdio.h>

int main(){
int n=9;// n represents the value of number of movies, in this case there are 9 movies.
char name[9][50]={"CODA","Belfast","Don't Look Up","Drive My Car","Dune","King Richard","Licorice Pizza","Nightmare Alley","The Power of the Dog"};// declaring a 2D array
float rate[n];//rating can be both integer and floating so the variable is float.
for(int i=0;i<n;i++){
printf("%s\nRate:",name[i]);
scanf("%f",&rate[i]);
} //input of rating for each movies



float rate2[n][2];
for(int i=0;i<n;i++){
    rate2[i][0]=rate[i];
    rate2[i][1]=i;
}//  storing position.
for(int i=0;i<n;i++){
    for(int j=0;j<n-1-i;j++){
        if(rate2[j][0]<rate2[j+1][0]){
            int temp=rate2[j][0];
            rate2[j][0]=rate2[j+1][0];
            rate2[j+1][0]=temp;
            temp=rate2[j][1];
            rate2[j][1]=rate2[j+1][1];
            rate2[j+1][1]=temp;
        }
    }
}// sorting the ratings in an ascending order. we needed temp as an extra variable as it was necessary to hold the value of previous element.
printf("\n-------------\nResult:\n");
for(int i=8;i>=0;i--){
printf("%s\nRate:%.2f\n",name[(int)rate2[i][1]],rate2[i][0]);
}// this loop will print the ratings and the movies in an ascending order.


}
