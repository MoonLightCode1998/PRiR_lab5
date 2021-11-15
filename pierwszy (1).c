#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "err.h"
#include <time.h>
#include <math.h>
double randfrom(double min, double max){
double range = max-min;
double div = RAND_MAX / range;
return min+(rand()/div);
}
int randomx(int min, int max){
int tmp;
if(max>=min)
max-=min;
else{
tmp=min-max;
min=max;
max=tmp;
}
return max ? (rand()%max+min):min;
}

double funkcja(double x){
	return 4*x*x-6*x+5;
}    


 double kwadratury(double poczatekPrzedzialu, double koniecPrzedzialu, int n) {
    	//waga/t1
   double n2[2][2] = {{1.0, 1.0}, {-0.57735, 0.57735}};
   double n4[4][4] = {{0.347855, 0.652145, 0.652145, 0.347855}, {-0.861136, -0.339981, 0.339981, 0.861136}};
	double n6[6][6] = {{0.171324, 0.360762, 0.467914, 0.467914, 0.360762, 0.171324},
            {-0.932469, -0.661209, -0.238619, 0.238619, 0.661209, 0.932469}};
   double n8[8][8] = {{0.101229, 0.222381, 0.313707, 0.362684, 0.362684, 0.313707, 0.222381, 0.101229},
            {-0.96029, -0.796667, -0.525532, -0.183435, 0.183435, 0.525532, 0.796667, 0.96029}};
   double n10 [10][10]= {{0.0666713, 0.149451, 0.219086, 0.269267, 0.295524, 0.295524, 0.269267, 0.219086, 0.149451, 0.0666713},
            {-0.973907, -0.865063, -0.67941, -0.433395, -0.148874, 0.148874, 0.433395, 0.67941, 0.865063, 0.973907}};
     double n16 [16][16]= {{0.0271525, 0.0622535, 0.0951585, 0.124629, 0.149596, 0.169157, 0.182603, 0.189451, 0.189451, 0.182603, 0.169157,
            0.149596, 0.124629, 0.0951585, 0.0622535, 0.0271525},
            {-0.989401, -0.944575, -0.865631, -0.755404, -0.617876, -0.458017, -0.281604, -0.0950125, 0.0950125, 0.281604, 0.458017,
                    0.617876, 0.755404, 0.865631, 0.944575, 0.989401}};
    
        double wynik = 0;
        double xz[n][n];

    
       	if(n==2){
            for (int x = 0; x < n; x++) {
                wynik += n2[0][x] * funkcja((((koniecPrzedzialu - poczatekPrzedzialu) * xz[1][x]) / 2) + ((koniecPrzedzialu + poczatekPrzedzialu) / 2));
            }}

       	if(n==4){
            for (int x = 0; x < n; x++) {
                wynik += n4[0][x] * funkcja((((koniecPrzedzialu - poczatekPrzedzialu) * xz[1][x]) / 2) + ((koniecPrzedzialu + poczatekPrzedzialu) / 2));
            }}

       	if(n==8){
            for (int x = 0; x < n; x++) {
                wynik += n8[0][x] * funkcja((((koniecPrzedzialu - poczatekPrzedzialu) * xz[1][x]) / 2) + ((koniecPrzedzialu + poczatekPrzedzialu) / 2));
            }}


       	if(n==10){
            for (int x = 0; x < n; x++) {
                wynik += n10[0][x] * funkcja((((koniecPrzedzialu - poczatekPrzedzialu) * xz[1][x]) / 2) + ((koniecPrzedzialu + poczatekPrzedzialu) / 2));
            }}
       	if(n==16){
            for (int x = 0; x < n; x++) {
                wynik += n16[0][x] * funkcja((((koniecPrzedzialu - poczatekPrzedzialu) * xz[1][x]) / 2) + ((koniecPrzedzialu + poczatekPrzedzialu) / 2));
            }}

            wynik = wynik * ((koniecPrzedzialu - poczatekPrzedzialu) / 2);
	printf("Wynik kwadratury %f\n",wynik);
            if (wynik < 0)
                return wynik * (-1);
            else
            return wynik;
       


    }

double trapezy(double poczatekPrzedzialu, double koniecPrzedzialu,int iloscOdcinkow){
double h = (koniecPrzedzialu-poczatekPrzedzialu)/iloscOdcinkow;
double wynik =0;
for(int x = 0;x<iloscOdcinkow;x++){
	wynik+=(funkcja(poczatekPrzedzialu+x*h) + funkcja(poczatekPrzedzialu
	+(x+1)*h))*(h/2);
}
	printf("Wynikiem calki mtrapezow jest: %f\n",wynik);
	if(wynik<0){
	return wynik*(-1);}
	else{
	return wynik;}
}
int main(){
time_t tt;
int zarodek = time(&tt);
srand(zarodek);
//if(fork()!=0){
//printf("jestem rodzicem, moj pid = %d\n",getpid());}
//else{
//printf("ja potomek,mj pid = %d\n",getpid());
//printf("moj rodzic to = %d\n",getppid());
//}
int procNum;
printf("podaj ilosc procesow");
scanf("%d",&procNum);
printf("\n");
for(int x = 1; x<=procNum;x++){
	if(fork()!=0){
//	printf("%d\n",rand());
//printf("%d\n",rand());
//		printf("proces macierzysty %d\n",getpid());
	}else{
	//	printf("proces potomny %d\n",getpid());
	//	printf("rodzic %d\n",getppid());

	double poczatekPrzedzialu;
	double koniecPrzedzialu;
	int odcinki;
int numbers[]={2,4,8,10,16};
int len = sizeof(numbers)/sizeof(int);	
int odcinkiGauss;
	
	srand(time(NULL) ^(getpid()<<14));
	poczatekPrzedzialu = randfrom(0,200);
	koniecPrzedzialu = randfrom(0,200);
	odcinki = rand()%100 +1;
	odcinkiGauss = numbers[rand()%len];
	//printf("%f %f %d", poczatekPrzedzialu,koniecPrzedzialu,odcinki);
	if(koniecPrzedzialu>poczatekPrzedzialu){
	double calka = trapezy(poczatekPrzedzialu,koniecPrzedzialu, odcinki);
	double calka2 = kwadratury(poczatekPrzedzialu,koniecPrzedzialu,odcinkiGauss);
	}else{
	double calka = trapezy(koniecPrzedzialu,poczatekPrzedzialu,odcinki);
	double calka2 = kwadratury(koniecPrzedzialu,poczatekPrzedzialu,odcinkiGauss);
	}
//	double calka = trapezy();
	// KOLEJNY ALGORYTM
	int N = randomx(100,5000);
	printf("%d\n", N);
	double petlaWynik=0;
	for(int y =1;y<N;y++){
	if(y==1){petlaWynik=1;}
	else{
	petlaWynik+=((pow(-1,y-1))/(2.0*y-1.0));
//	printf("%f\n",((pow(-1,y-1))/(2.0*y-1.0)));
	}

	}
	printf("Przyblizenie pi = %f\n",4*petlaWynik);
	return 0;
	}
}

for(int i=0;i<procNum;i++){
	if(wait(0)==-1)
		printf("karamba");
}

return 0;
}
	
