#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NOM 50
#define MAX_TELEPHONE 20
#define MAX_EMAIL 50

// Structure pour représenter un contact
typedef struct {
    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];
} Contact;

// Prototypes des fonctions
void afficherMenu();
void ajouterContact(Contact contacts[], int *nbContacts);
void afficherTousContacts(Contact contacts[], int nbContacts);
void rechercherContact(Contact contacts[], int nbContacts);
void modifierContact(Contact contacts[], int nbContacts);
void supprimerContact(Contact contacts[], int *nbContacts);
void viderBuffer();