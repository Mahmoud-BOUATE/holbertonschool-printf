<h1 align="center"># Projet _printf.c</h1>

## Description

Ce projet consiste à recréer une version simplifiée de la fonction standard printf en C.
Il gère plusieurs spécificateurs de format et repose uniquement sur l'appel système write().

## Fonctionnalités

**La fonction _printf implémente les spécificateurs suivants :**

| spécificateur    | Description                        |
|:-----------------|:----------------------------------:|
| %c               | Affiche un caractère               |
|:-----------------|:----------------------------------:|
| %s               | Affiche une chaîne de caractères   |
|:-----------------|:----------------------------------:|
| %d / %i          | Affiche un entier signé            |
|:-----------------|:----------------------------------:|
| %%               | Affiche le caractère %             |
|:-----------------|:----------------------------------:|

## Architecture du projet

**Le projet est composé de plusieurs fichiers principaux :**

### _printf.c

- Fonction principale reconstituant le comportement de printf
- Utilise va_list pour gérer les arguments variables
- Redirige les différents formats vers des fonctions utilitaires

### function.s
**1- _putstr.c**

**Fonction utilitaire permettant d’afficher une chaîne de caractères :**
- Affiche (null) si la chaîne est NULL
- Retourne le nombre de caractères écrits

**2- _putsnbr.c**

**Fonction utilitaire permettant d’afficher un nombre entier :**
- Gère les nombres négatifs
- Fonction récursive pour afficher chaque chiffre

### main.h

- Contient les prototypes utilisés dans le projet.

## Exemple d'utilisation :

```c
int main(void)
{
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello");
    _printf("Integer: %d\n", 123);
    _printf("Percent: %%\n");
    _printf("Hell%c" %d, 'o', 158);

    return 0;
}
```
# Compilation :

**Compiler le projet avec :**

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

## test :

```c
_printf("Test char: %c\n", 'X');
_printf("Test string: %s\n", "Bonjour");
_printf("Test integer: %d\n", -42);
_printf("Testing percent: %%\n");
_printf("Mixed: %s %c %d %%\n", "Test", 'A', 100);
```
# Auteur 
Lucas Podevin
mahmoud BOUATE