#include <stdio.h>

//Funktion zum Überprüfen, ob ein Warnsignal abgespielt werden soll
int WarnsignalCheck(double Geschwindigkeit, double Motortemparatur,
	double Schraeglage, int SchneidwerkRPM, int Drucksensor, int OptischerSensor)
{
    if(Geschwindigkeit>15)
    {
        if(Schraeglage>24)
        {
            return 1;
        }
        if(SchneidwerkRPM>1)
        {
            return 1;
        }
    }
    if(Drucksensor==1)
    {
        if(SchneidwerkRPM>0)
        {
            return 1;
        }
    }
    if(OptischerSensor==1)
    {
        return 1;
    }
    if(Motortemparatur>110)
    {
        return 1;
    }
	return 0;
}

//Einmaliger Test der Funktion durch manuelle Eingaben des Benutzers
int main()
{
    //Deklaration der Variablen
    double Geschwindigkeit;
    double Motortemparatur;
    double Schraeglage;
    double SchneidwerkRPM;
    int Drucksensor;
    int OptischerSensor;

    //Einlesen und Verarbeitung der Eingaben
    printf("Wie hoch ist die Geschwindigkeit? [km/h]\n");
    scanf("%lf",&Geschwindigkeit);
    printf("\nWie hoch ist die Motortemparatur? [C]\n");
    scanf("%lf",&Motortemparatur);
    printf("\nWie hoch ist die Schraeglage? [Grad]\n");
    scanf("%lf",&Schraeglage);
	//Eingabe 1=an, 0=aus
    printf("\nWie hoch sind die RPM des Schneidwerkes?\n");
    scanf("%lf",&SchneidwerkRPM);
    printf("\nHat der Drucksensor ein harten Gegenstand erkannt?\n  1=ja, 0=nein\n");
    scanf("%i",&Drucksensor);
    printf("\nHat der optische Sensor ein Tier erkannt?\n  1=ja, 0=nein\n");
    scanf("%i",&OptischerSensor);

    //Aufruf der Funktion mit Überprüfung des Ergebnisses
    if(WarnsignalCheck(Geschwindigkeit, Motortemparatur, Schraeglage, SchneidwerkRPM, Drucksensor,
		OptischerSensor)==1)
    {
        printf("\nEin Warnsignal wurde in der Fahrerkabine abgespielt!\n");
        return 0;
    }
	else
	{
		printf("Alles ist in Ordnung, die Funktion kann erneut aufgerufen werden.\n");
		return 0;
	}
}
