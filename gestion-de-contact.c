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

// Fonction pour vider le buffer d'entrée
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour ajouter un nouveau contact
void ajouterContact(Contact contacts[], int *nbContacts) {
    if (*nbContacts >= MAX_CONTACTS) {
        printf("\n[ERREUR] Le carnet de contacts est plein!\n");
        return;
    }
    
    printf("\n========== AJOUTER UN CONTACT ==========\n");
    
    Contact nouveauContact;
    
    // Saisie du nom
    printf("Nom : ");
    fgets(nouveauContact.nom, MAX_NOM, stdin);
    nouveauContact.nom[strcspn(nouveauContact.nom, "\n")] = 0;
    
    // Saisie du numéro de téléphone
    printf("Numéro de téléphone : ");
    fgets(nouveauContact.telephone, MAX_TELEPHONE, stdin);
    nouveauContact.telephone[strcspn(nouveauContact.telephone, "\n")] = 0;
    
    // Saisie de l'adresse e-mail
    printf("Adresse e-mail : ");
    fgets(nouveauContact.email, MAX_EMAIL, stdin);
    nouveauContact.email[strcspn(nouveauContact.email, "\n")] = 0;
    
    // Ajout du contact dans le tableau
    contacts[*nbContacts] = nouveauContact;
    (*nbContacts)++;
    
    printf("\n[SUCCES] Contact ajouté avec succès!\n");
}

// Fonction pour afficher tous les contacts
void afficherTousContacts(Contact contacts[], int nbContacts) {
    printf("\n========== LISTE DES CONTACTS ==========\n");
    
    if (nbContacts == 0) {
        printf("\n[INFO] Aucun contact dans le carnet.\n");
        return;
    }
    
    printf("\nNombre total de contacts : %d\n\n", nbContacts);
    
    for (int i = 0; i < nbContacts; i++) {
        printf("Contact #%d:\n", i + 1);
        printf("  Nom        : %s\n", contacts[i].nom);
        printf("  Téléphone  : %s\n", contacts[i].telephone);
        printf("  E-mail     : %s\n", contacts[i].email);
        printf("  ------------------------\n");
    }
}

// Fonction pour rechercher un contact par nom
void rechercherContact(Contact contacts[], int nbContacts) {
    if (nbContacts == 0) {
        printf("\n[INFO] Aucun contact dans le carnet.\n");
        return;
    }
    
    printf("\n========== RECHERCHER UN CONTACT ==========\n");
    
    char nomRecherche[MAX_NOM];
    printf("Entrez le nom du contact à rechercher : ");
    fgets(nomRecherche, MAX_NOM, stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = 0;
    
    int trouve = 0;
    
    for (int i = 0; i < nbContacts; i++) {
        if (strcasecmp(contacts[i].nom, nomRecherche) == 0) {
            printf("\n[SUCCES] Contact trouvé!\n");
            printf("  Nom        : %s\n", contacts[i].nom);
            printf("  Téléphone  : %s\n", contacts[i].telephone);
            printf("  E-mail     : %s\n", contacts[i].email);
            trouve = 1;
            break;
        }
    }
    
    if (!trouve) {
        printf("\n[INFO] Aucun contact trouvé avec le nom '%s'.\n", nomRecherche);
    }
}

// Fonction pour modifier un contact existant
void modifierContact(Contact contacts[], int nbContacts) {
    if (nbContacts == 0) {
        printf("\n[INFO] Aucun contact dans le carnet.\n");
        return;
    }
    
    printf("\n========== MODIFIER UN CONTACT ==========\n");
    
    char nomRecherche[MAX_NOM];
    printf("Entrez le nom du contact à modifier : ");
    fgets(nomRecherche, MAX_NOM, stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = 0;
    
    int index = -1;
    
    for (int i = 0; i < nbContacts; i++) {
        if (strcasecmp(contacts[i].nom, nomRecherche) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\n[INFO] Aucun contact trouvé avec le nom '%s'.\n", nomRecherche);
        return;
    }
    
    printf("\n[INFO] Contact actuel:\n");
    printf("  Nom        : %s\n", contacts[index].nom);
    printf("  Téléphone  : %s\n", contacts[index].telephone);
    printf("  E-mail     : %s\n", contacts[index].email);
    
    printf("\n[INFO] Entrez les nouvelles informations (laissez vide pour garder l'ancienne valeur):\n");
    
    char nouveauTelephone[MAX_TELEPHONE];
    char nouvelEmail[MAX_EMAIL];
    
    // Modification du numéro de téléphone
    printf("Nouveau numéro de téléphone : ");
    fgets(nouveauTelephone, MAX_TELEPHONE, stdin);
    nouveauTelephone[strcspn(nouveauTelephone, "\n")] = 0;
    
    if (strlen(nouveauTelephone) > 0) {
        strcpy(contacts[index].telephone, nouveauTelephone);
    }
    
    // Modification de l'adresse e-mail
    printf("Nouvelle adresse e-mail : ");
    fgets(nouvelEmail, MAX_EMAIL, stdin);
    nouvelEmail[strcspn(nouvelEmail, "\n")] = 0;
    
    if (strlen(nouvelEmail) > 0) {
        strcpy(contacts[index].email, nouvelEmail);
    }
    
    printf("\n[SUCCES] Contact modifié avec succès!\n");
}

// Fonction pour supprimer un contact
void supprimerContact(Contact contacts[], int *nbContacts) {
    if (*nbContacts == 0) {
        printf("\n[INFO] Aucun contact dans le carnet.\n");
        return;
    }
    
    printf("\n========== SUPPRIMER UN CONTACT ==========\n");
    
    char nomRecherche[MAX_NOM];
    printf("Entrez le nom du contact à supprimer : ");
    fgets(nomRecherche, MAX_NOM, stdin);
    nomRecherche[strcspn(nomRecherche, "\n")] = 0;
    
    int index = -1;
    
    for (int i = 0; i < *nbContacts; i++) {
        if (strcasecmp(contacts[i].nom, nomRecherche) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("\n[INFO] Aucun contact trouvé avec le nom '%s'.\n", nomRecherche);
        return;
    }
    
    // Affichage du contact à supprimer
    printf("\n[INFO] Contact à supprimer:\n");
    printf("  Nom        : %s\n", contacts[index].nom);
    printf("  Téléphone  : %s\n", contacts[index].telephone);
    printf("  E-mail     : %s\n", contacts[index].email);
    
    // Confirmation de suppression
    char confirmation;
    printf("\nÊtes-vous sûr de vouloir supprimer ce contact? (o/n) : ");
    scanf("%c", &confirmation);
    viderBuffer();
    
    if (confirmation == 'o' || confirmation == 'O') {
        // Décalage des éléments pour supprimer le contact
        for (int i = index; i < *nbContacts - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        (*nbContacts)--;
        printf("\n[SUCCES] Contact supprimé avec succès!\n");
    } else {
        printf("\n[INFO] Suppression annulée.\n");
    }
}