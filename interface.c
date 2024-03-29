/* Projet réalisé par Brice VAN AKEN et Thomas STREBLER */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main()
{    
    int choix = 0;

    int heures, minutes, secondes, jour, mois, annee;
    time_t t;

    char *placeA = "10";
    char *placeN = "10";
    char *voiture = "50";

    /* time() retourne le temps passée depuis le 1er janvier 1970 à 00:00:00 
       en entier positif dans t de type time_t */
    time(&t);

    /* local time permet de convertir cette valeur en format calendrier dans la structure tm qui est préconfigurée
       avec des membres associée à la date, l'heure, les secondes, les minutes... */
    struct tm *local = localtime(&t);

    heures = local->tm_hour; //on stocke l'heure courante dans heures grâce au membre 'hour' de la structure 'tm'
    minutes = local->tm_min;
    secondes = local->tm_sec;
    jour = local->tm_mday;            
    mois = local->tm_mon + 1;      
    annee = local->tm_year + 1900;
    
    MENU:
        printf("|*****************************************************|\n");
        printf("|  Bienvenue dans le programme de gestion de parking  |\n");
        printf("|                 Ouvert 24h/24 7j/7                  |\n");
        printf("|                                                     |\n");
        printf("|            Heure système: %02d:%02d:%02d                  |\n", heures, minutes, secondes); //%02d permet de forcer l'affichage avec deux chiffres, on met 0 devant si un chiffre
        printf("|           Nous sommes le: %02d/%02d/%d                |\n", jour, mois, annee);
        printf("|                                                     |\n");
        printf("|                                                     |\n");
        printf("|        Disponibilités des places non abonnées :     |\n");
        printf("|         80%% à 18h | 90%% à 19h | 100%% à 00h          |\n");
        printf("|                                                     |\n");
        printf("|  Choisissez les options de lancement du programme   |\n");
        printf("|                                                     |\n");
        printf("*******************************************************\n");
        printf("\n");
        printf("1) Lancer le programme avec l'heure courante du système\n");
        printf("\n");
        printf("2) Lancer le programme en forçant l'heure à 18h\n");
        printf("\n");
        printf("3) Lancer le programme en forçant l'heure à 19h\n");
        printf("\n");
        printf("4) Lancer le programme en forçant l'heure à 00h\n");
        printf("\n");
        printf("5) Choisir le nombre de places Abonné et Non-Abonné\n");
        printf("\n");
        printf("6) Choisir le nombre de voitures\n");
        printf("\n");

    /*Verification du choix utilisateurs*/
    do{
        printf("Attention : votre choix doit être compris entre 1 et 6\n");
        fflush(stdout);
        scanf("%d",&choix);
    }while(choix <1 || choix >6);

    char *h[2];
    /*TO DO attribuer la valeur de "heures" à h*/
    /*lancement main avec le temps systeme en argument (en heure) grâce à execl*/
    switch(choix){
        case 1:
            if(h == 18) execl("./main", "main", "80", placeA, placeN, voiture, NULL); //80% places pour les non abonnées
            else if (h == 19) execl("./main", "main", "90", placeA, placeN, voiture, NULL); //90% places pour les non abonnées
            else execl("./main", "main", "100", placeA, placeN, voiture, NULL); //100% places pour les non abonnées

        case 2:
        execl("./main", "main", "80", placeA, placeN, voiture, NULL); //80% places pour les non abonnées

        case 3:
        execl("./main", "main", "90", placeA, placeN, voiture, NULL); //90% places pour les non abonnées

        case 4:
        execl("./main", "main", "100", placeA, placeN, voiture, NULL); //100% places pour les non abonnées

        case 5:
            placeA=(char *)malloc(11);
            placeN=(char *)malloc(11);
            printf("Nombre de places Abonné : ");
            fflush(stdout);
            scanf(" %s", placeA);
            printf("Nombre de places Non-Abonné : ");
            fflush(stdout);
            scanf(" %s", placeN);
            goto MENU; //revenir à la sélection précédente
        case 6:
            voiture=(char *)malloc(11);
            printf("Nombre de voitures: ");
            fflush(stdout);
            scanf(" %s", voiture);
            goto MENU; //revenir à la sélection précédente
    }

    exit(0);
}