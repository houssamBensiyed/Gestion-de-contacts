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

int main() {
    Contact contacts[MAX_CONTACTS];
    int nbContacts = 0;
    int choix;
    
    printf("========================================\n");
    printf("   SYSTEME DE GESTION DE CONTACTS\n");
    printf("========================================\n\n");
    
    do {
        afficherMenu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
        
        switch(choix) {
            case 1:
                ajouterContact(contacts, &nbContacts);
                break;
            case 2:
                afficherTousContacts(contacts, nbContacts);
                break;
            case 3:
                rechercherContact(contacts, nbContacts);
                break;
            case 4:
                modifierContact(contacts, nbContacts);
                break;
            case 5:
                supprimerContact(contacts, &nbContacts);
                break;
            case 6:
                printf("\nMerci d'avoir utilisé notre gestionnaire de contacts!\n");
                printf("Au revoir!\n");
                break;
            default:
                printf("\n[ERREUR] Choix invalide! Veuillez réessayer.\n");
        }
        
        if(choix != 6) {
            printf("\n----------------------------------------\n");
            printf("Appuyez sur Entrée pour continuer...");
            getchar();
        }
        
    } while(choix != 6);
    
    return 0;
}

