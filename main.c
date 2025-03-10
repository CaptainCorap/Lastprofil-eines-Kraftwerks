#include <stdio.h>

// Festlegung der Anzahl der Leistungsmessungen, die verarbeitet werden sollen
#define POWER_LENGTH 96

int main() {

     // Array, das die Leistungswerte speichert
    double power[POWER_LENGTH] = {
            7.0, 7.3, 7.7, 8.0, 8.3, 8.3, 8.3, 8.3, 8.8, 9.2, 
            9.7, 10.1, 10.8, 10.8, 10.8, 11.3, 11.7, 13.1, 13.6, 13.6,
            13.6, 15.7, 16.3, 17.8, 21.8, 25.3, 25.3, 30.6, 38.8, 39.2,
            44.3, 44.3, 51.2, 52.6, 58.1, 55.3, 50.2, 42.0, 38.8, 37.2,
            25.8, 26.1, 26.1, 26.1, 26.1, 26.1, 27.3, 26.1, 25.4, 22.3,
            20.9, 18.3, 18.3, 18.1, 18.1, 18.1, 17.5, 17.3, 19.3, 20.5,
            28.3, 28.3, 35.7, 44.2, 38.2, 32.1, 27.8, 26.3, 25.1, 25.1,
            25.1, 25.1, 22.3, 20.8, 18.7, 16.9, 16.9, 16.9, 15.8, 13.9,
            13.2, 12.8, 12.6, 12.3, 12.0, 10.8, 10.4, 12.0, 10.8, 9.8,
            9.2, 9.0, 7.8, 7.2, 7.1, 6.8
    };

   // Variablen zur Berechnung der statistischen Daten
    double p, pmin, pmax, mittelwert, summe;          // Variable zur Speicherung der Summe initialisieren
    int stunde, minute, s1, m1, s2, m2, mwstd,s3;    //stunde ,minute, s1=stunde ,m1=minute,mwstd=mittelwert stunde
    minute = 0;
    stunde = 0;
    s3 = 0;
    pmin = power[0];                                                         //pmin wird auf null gesetzt
   // Kopfzeile der Ausgabe
    printf("\n\nProgramm zur Analyse eines Lastprofils\n");
    printf("--------------------------------------------------------\n");





     // Schleife zur Verarbeitung jeder Messung
    for (int i = 0; i < POWER_LENGTH; i++)
    {
        summe = summe + power[i]; //Summe aller werte von power
        p = power[i];
        mwstd = mwstd + power[i];


    printf("Gelesener Wert: %lf     uhrzeit:%d:%d\n", p, stunde, minute);

    if(i% 4 == 3)            // Berechnung und Ausgabe des Mittelwerts alle vier Messungen
    {
        mwstd = mwstd /4.0 ;
        printf("Mittelwert der letzten 4 Gelesenen Werte: %.2f  \n",mwstd);
        printf("mittelwert fuer %d Uhr",s3);
        for(int j = 0; j <= mwstd ;j++)
        {
            printf("*");
        }
        s3=s3+1;
        printf("\n\n");
        mwstd = 0;
    }

        // Überprüfung und Speicherung des maximalen und minimalen Leistungswerts
        if (p > pmax) // operator < zu // Hoechstlast für pmax
        {
        pmax = p;
        s1 = stunde;
        m1 = minute;
        }

    if (p < pmin)// operator > zu < // Grundlast für pmin

        {
        pmin = p;
        s2 = stunde;
        m2 = minute;
        }

        minute = minute + 15;  // minute alle 15

    if (minute == 60)  // minute geht bis 60
        {

            minute = 0;
            stunde = stunde + 1; // stunde in einer schritten

            if (stunde == 24) // stunde bis 24
            {
            stunde = 0;     //bei null reset
            }

        }
    }
            mittelwert = summe / POWER_LENGTH; // Berechnung des arithmetischen Mittels der Gesamtleistung

    // Ausgabe
    printf("\nErgebnisse:\n");
    printf("------------------------------------------------------------\n\n");
    printf("Hoechstlast  . . . . . . . . . . . . : %6.2lf uhrzeit: %d:%d\n",pmax,s1,m1);
    printf("Grundlast    . . . . . . . . . . . . : %6.2lf uhrzeit: %d:%d\n",pmin,s2,m2);
    printf("Arithmetisches Mittel  . . . . . . . : %6.2lf\n",mittelwert);

    return 0; //<3
}
