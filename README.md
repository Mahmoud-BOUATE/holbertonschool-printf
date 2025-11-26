Projet _printf.c

#Description

Ce projet vise à reccoder la fonction printf() de la libc. L'objectif est d'apprendre à utiliser une variété d'arguments et de maîtriser le traitement de différents formats de données. C'est une excellente occasion d'améliorer vos compétences en programmation C, en mettant en œuvre une fonction complexe et polyvalente.

#Fonctionnalités

La fonction _printf implémente les spécificateurs suivants :

| spécificateur    | Description                        |
|:-----------------|:----------------------------------:|
| %c               | Affiche un caractère               |
|:-----------------|:----------------------------------:|
| %s               | Affiche une chaîne de caractères   |
|:-----------------|:----------------------------------:|
| %d / %i          | Affiche un entier signé            |
|:-----------------|:----------------------------------:|
| %%               | Affiche un entier signé            |
|:-----------------|:----------------------------------:|

#Architecture du projet

Le projet est composé de plusieurs fichiers principaux :

##_printf.c

- Fonction principale reconstituant le comportement de printf
- Utilise va_list pour gérer les arguments variables
- Redirige les différents formats vers des fonctions utilitaires

##_putstr.c

Fonction utilitaire permettant d’afficher une chaîne de caractères :
- Affiche (null) si la chaîne est NULL
- Retourne le nombre de caractères écrits

##_putsnbr.c

Fonction utilitaire permettant d’afficher un nombre entier :
- Gère les nombres négatifs
- Fonction récursive pour afficher chaque chiffre

##main.h

- Contient les prototypes utilisés dans le projet.

#Exemple d'utilisation :
int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello");
    _printf("Integer: %d\n", 123);
    _printf("Percent: %%\n");
    _printf("cj)

    return 0;
}





