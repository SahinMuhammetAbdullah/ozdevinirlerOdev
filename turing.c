#include <stdio.h>

#define DIZI_MAX 100000

enum durumlar{
    q0,
    q1,
    q2,
    q3,
    q4,
    q5,
    q6,
    q7,
    q8,
    q9,
    F
};

int sayiHesapla(char* dizi) {
    int sayac = 0;
    for (int i = 0; dizi[i] != '\0'; i++) {
        sayac++;
    }
    return sayac;
}


void turingMachine ( char* inputString ) {
    enum durumlar durum = q0;
    char kaset[DIZI_MAX];
    kaset[0] = 'c';

    int sayac = sayiHesapla(inputString);

    for (size_t i = 1; i <= sayac; i++)
    {
        kaset[i] = inputString[i-1];
    }
    
    kaset[sayac + 1] = '$';
    kaset[sayac + 2] = 'B';
    for (int i = sayac + 3; i < ((sayac + 3) + (sayac*sayac) - 1) ; i++)
    {
        kaset[i] = '0';
    }

    kaset[((sayac + 3) + (sayac*sayac) - 1)] = '$';
    kaset[(sayac + 3) + (sayac*sayac)] = 'B';
    int olay = 0;
    int kafaDurumu = 1;
    printf("durum q0. Makine basliyor... ---> Giris kaset durumu: %s\n", kaset);
   
    while (durum != F) {
        switch (durum) {
            case q0:
                if (kaset[kafaDurumu] == '0') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu++; // kafaDurumu++: R
                    printf("%d durum q0 da '0' iken (q1,1,R), kaset: %s\n",olay++, kaset);
                    durum = q1;
                } else if (kaset[kafaDurumu] == '\0') {
                    kaset[kafaDurumu] = 'B';
                    kafaDurumu;
                    printf("%d durum q0 de '\\0' iken (q9,B,S), kaset: %s\n",olay++, kaset);
                    durum = q9;
                } else {
                    printf("Hata q0, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q1:
                if (kaset[kafaDurumu] == '0') {
                    kaset[kafaDurumu] = '0';
                    kafaDurumu++;
                    printf("%d durum q1 de '0' iken (q1,0,R), kaset: %s\n",olay++, kaset);
                    durum = q1;
                } else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu--; // kafaDurumu--: L
                    printf("%d durum q1 de '$' iken (q2,$,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else {
                    printf("Hata q1, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q2:
                if (kaset[kafaDurumu] == 'c') {
                    kaset[kafaDurumu] = 'c';
                    kafaDurumu++;
                    printf("%d durum q2 de 'c' iken (q6,c,R), kaset: %s\n",olay++, kaset);
                    durum = q6;
                } else if (kaset[kafaDurumu] == '0') {
                    kaset[kafaDurumu] = 'X';
                    kafaDurumu++;
                    printf("%d durum q2 de '0' iken (q3,X,R), kaset: %s\n",olay++, kaset);
                    durum = q3;
                }  else if (kaset[kafaDurumu] == '1') {
                    kaset[kafaDurumu] = 'Y';
                    kafaDurumu++;
                    printf("%d durum q2 de '1' iken (q3,Y,R), kaset: %s\n",olay++, kaset);
                    durum = q3;
                } else if (kaset[kafaDurumu] == 'X')  {
                    kaset[kafaDurumu] = 'X';
                    kafaDurumu--;
                    printf("%d durum q2 de 'X' iken (q2,X,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else if (kaset[kafaDurumu] == 'Y') {
                    kaset[kafaDurumu] = 'Y';
                    kafaDurumu--;
                    printf("%d durum q2 de 'Y' iken (q2,Y,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu++;
                    printf("%d durum q2 de 'Y' iken (q6,Y,R), kaset: %s\n",olay++, kaset);
                    durum = q6;
                } else {
                    printf("Hata q2, kaset: %s\n", kaset);
                    return;
                }
                break;   
            case q3:
                if (kaset[kafaDurumu] == 'X') {
                    kaset[kafaDurumu] = 'X';
                    kafaDurumu--;
                    printf("%d durum q3 de 'X' iken (q2,X,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else if (kaset[kafaDurumu] == 'Y') {
                    kaset[kafaDurumu] = 'Y';
                    kafaDurumu++;
                    printf("%d durum q3 de 'Y' iken (q3,Y,R), kaset: %s\n",olay++, kaset);
                    durum = q3;
                } else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu++;
                    printf("%d durum q3 de '$' iken (q4,$,R), kaset: %s\n",olay++, kaset);
                    durum = q4;
                } else {
                    printf("Hata q3, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q4:
                if (kaset[kafaDurumu] == '1') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu--;
                    printf("%d durum q4 de '1' iken (q4,1,L), kaset: %s\n",olay++, kaset);
                    durum = q4;
                } else if (kaset[kafaDurumu] == 'B') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu--;
                    printf("%d durum q4 de 'B' iken (q5,1,L), kaset: %s\n",olay++, kaset);
                    durum = q5;
                }else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu--;
                    printf("%d durum q4 de '$' iken (q2,$,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else {
                    printf("Hata q4, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q5:
                if (kaset[kafaDurumu] == '1') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu--;
                    printf("%d durum q5 de '1' iken (q5,1,L), kaset: %s\n",olay++, kaset);
                    durum = q5;
                } else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu--;
                    printf("%d durum q5 de '$' iken (q2,$,L), kaset: %s\n",olay++, kaset);
                    durum = q2;
                } else {
                    printf("Hata q5, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q6:
                if (kaset[kafaDurumu] == 'X') {
                    kaset[kafaDurumu] = '0';
                    kafaDurumu++;
                    printf("%d durum q6 de 'X' iken (q6,0,R), kaset: %s\n",olay++, kaset);
                    durum = q6;
                } else if (kaset[kafaDurumu] == 'Y') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu++;
                    printf("%d durum q6 de 'Y' iken (q6,1,R), kaset: %s\n",olay++, kaset);
                    durum = q6;
                } else if (kaset[kafaDurumu] == '$') {
                    kaset[kafaDurumu] = '$';
                    kafaDurumu--;
                    printf("%d durum q6 de '$' iken (q7,$,L), kaset: %s\n",olay++, kaset);
                    durum = q7;
                } else {
                    printf("Hata q6, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q7:
                if (kaset[kafaDurumu] == '0') {
                    kaset[kafaDurumu] = '0';
                    kafaDurumu--;
                    printf("%d durum q7 de '0' iken (q7,0,L), kaset: %s\n",olay++, kaset);
                    durum = q7;
                } else if (kaset[kafaDurumu] == '1') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu++;
                    printf("%d durum q7 de '1' iken (q8,1,R), kaset: %s\n",olay++, kaset);
                    durum = q8;
                } else {
                    printf("Hata q7, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q8:
            if (kaset[kafaDurumu] == '0') {
                kaset[kafaDurumu] = '1';
                kafaDurumu++;
                printf("%d durum q8 de '0' iken (q1,1,R), kaset: %s\n",olay++, kaset);
                durum = q1;
            } else if (kaset[kafaDurumu] == '$') {
                kaset[kafaDurumu] = '$';
                kafaDurumu++;
                printf("%d durum q8 de '$' iken (q9,$,R), kaset: %s\n",olay++, kaset);
                durum = q9;
            } else {
                printf("Hata q8, kaset: %s\n", kaset);
                    return;
                }
                break;
            case q9:
                if (kaset[kafaDurumu] == '1') {
                    kaset[kafaDurumu] = '1';
                    kafaDurumu++;
                    printf("%d durum q9 de '1' iken (q0,1,R), kaset: %s\n",olay++, kaset);
                    durum = q0;
                } else if (kaset[kafaDurumu] == 'B') {
                    printf("durum q9. Makine sonlaniyor... ---> Cikis kaset durumu: %s\n", kaset);
                    durum = F;
                } else {
                    printf("Hata q9, kaset: %s\n", kaset);
                    return;
                }
                break;
        }
    }
}


int main()
{
    char dizi[DIZI_MAX] = "00000";
    turingMachine(dizi);
    return 0;
}
