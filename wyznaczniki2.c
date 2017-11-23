/*
	Program do obliczania ukladu rownan
	a1x+b1x=c1
	a2x+b2=c2
	
	autor:  Michal Jarzynski
	data:   23.11.2017r
	wersja: 2.0 (z CLion)
*/

#include <stdio.h>
#include <stdlib.h>

// funkcja pokazujaca informacje na poczatku
void pokaz_info()
{
	system("clear");	// czysci ekran, rozwiazanie tylko dla systemu rodziny linux
	puts("Program do rozwiazywania ukladu rownan:");
	puts(" / a1x+b1y=c1");
	puts(" \\ a2x+b2y=c2");
	puts("");
}

// funkcja pobierajaca pojedyncze dane od uzytkownika
double pobierz(char* tekst)
{
	double z;
	printf("%s",tekst);
	if(!scanf("%lf",&z)) z=0;
	while(getchar()!='\n');
	return z;
}

// funkcja pobierająca komplet danych od uzytkownika
void pobierz_zmienne(double *a1, double *b1, double *c1, double *a2, double *b2, double *c2)
{
	*a1 = pobierz("Podaj a1 = ");
	*b1 = pobierz("Podaj b1 = ");
	*c1 = pobierz("Podaj c1 = ");
	*a2 = pobierz("Podaj a2 = ");
	*b2 = pobierz("Podaj b2 = ");
	*c2 = pobierz("Podaj c2 = ");
	puts("");	// dla lepszej czytelności wstaw pusta linie
}

// funkcja liczaca wyznaczniki i rozwiazujaca uklad rownan
void oblicz(double a1,double b1, double c1, double a2, double b2, double c2)
{
	double x,y,w,wx,wy;
	puts("Obliczam równanie postaci:");
	printf(" / %gx%+gy=%g\n",a1,b1,c1);
	printf(" \\ %gx%+gy=%g\n",a2,b2,c2);
	puts("");
	w=(a1*b2)-(b1*a2);
	wx=(c1*b2)-(b1*c2);
	wy=(a1*c2)-(c1*a2);
	if(w==0)
	{
		if((wx==0)&&(wy==0)) puts("Uklad rownan jest nieoznaczony - posiada nieskonczenie wiele rozwiazan");
		else puts("Uklad jest sprzeczny - nie posiada rozwiazan");
	}
	else
	{
		x=wx/w;
		y=wy/w;
		printf("Uklad posiada rozwiazanie: x=%g oraz y=%g\n",x,y);
	}
	puts("");
}

// glowna funkcja programu
int main()
{
	double a1,b1,c1,a2,b2,c2;
	pokaz_info();
	pobierz_zmienne(&a1,&b1,&c1,&a2,&b2,&c2);
	oblicz(a1,b1,c1,a2,b2,c2);
	return 0;
}
