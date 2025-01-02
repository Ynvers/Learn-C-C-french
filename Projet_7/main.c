#include <stdio.h>
#include <stdlib.h>
#include "inventaire.h"


int main() {
    Produit *inventaire = NULL;
    int taille = 0;
    int choix;
    char nomFichier[] = "iventaire.dat";

    do{
        printf("\n--- Menu Gestion d'Inventaire ---\n");
        printf("1. Ajouter un produit\n");
        printf("2. Modifier un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Rechercher un produit\n");
        printf("5. Enregistrer l'inventaire\n");
        printf("6. Charger l'inventaire\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterProduit(&inventaire, &taille);
                break;
            case 2:
                modifierProduit(inventaire, taille);
                break;
            case 3:
                supprimerProduit(&inventaire, &taille);
                break;
            case 4:
                rechercherProduit(inventaire, taille);
                break;
            case 5:
                enregistrerInventaire(inventaire, taille, nomFichier);
                break;
            case 6:
                chargerInventaire(&inventaire, &taille, nomFichier);
                break;
            case 7:
                printf("Au revoir!\n");
                break;
            default:
            printf("Choix invalide\n");
        }
    } while (choix != 7);

    free(inventaire);
    return 0;
}