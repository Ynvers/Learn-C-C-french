#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventaire.h"

void ajouterProduit(Produit **inventaire, int *taille) {
    Produit nouveau;
    printf("Nom du produit: ");
    scanf("%s", nouveau.nom);
    printf("Categorie du produit: ");
    scanf("%s", nouveau.categorie);
    printf("Prix du produit: ");
    scanf("%f", &nouveau.prix);
    printf("Quantite du produit: ");
    scanf("%d", &nouveau.quantite);

    *inventaire = realloc(*inventaire, (*taille + 1) * sizeof(Produit));
    if (*inventaire == NULL) {
        printf("Erreur d'allocation memoire\n");
        exit(1);
    }

    (*inventaire)[*taille] = nouveau;
    (*taille)++;
    printf("Produit ajoute avec succes\n");
}

void modifierProduit(Produit *inventaire, int taille) {
    char nom[50];
    printf("Entrez le nom du produit à modifier : ");
    scanf("%s", nom);

    for (int i = 0; i < taille; i++) {
        if (strcmp(inventaire[i].nom, nom) == 0) {
            printf("Produit trouvé !\n");
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &inventaire[i].quantite);
            printf("Entrez le nouveau prix : ");
            scanf("%f", &inventaire[i].prix);
            printf("Produit modifié avec succès !\n");
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

void supprimerProduit(Produit **inventaire, int *taille) {
    char nom[50];
    printf("Entrez le nom du produit à supprimer : ");
    scanf("%s", nom);

    for (int i = 0; i < *taille; i++) {
        if (strcmp((*inventaire)[i].nom, nom) == 0) {
            printf("Produit trouvé et supprimé !\n");
            for (int j = i; j < *taille - 1; j++) {
                (*inventaire)[j] = (*inventaire)[j + 1];
            }

            *inventaire = realloc(*inventaire, (*taille - 1) * sizeof(Produit));
            if (*inventaire == NULL && *taille - 1 > 0) {
                printf("Erreur de réallocation mémoire.\n");
                exit(1);
            }

            (*taille)--;
            return;
        }
    }
    printf("Produit non trouvé.\n");
}

void rechercherProduit(Produit *inventaire, int taille) {
    int choix;
    char critere[50];
    printf("Rechercher par :\n");
    printf("1. Nom\n2. Catégorie\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Entrez le nom du produit : ");
        scanf("%s", critere);
        for (int i = 0; i < taille; i++) {
            if (strcmp(inventaire[i].nom, critere) == 0) {
                printf("Produit trouvé : %s, Catégorie : %s, Prix : %.2f, Quantité : %d\n",
                       inventaire[i].nom, inventaire[i].categorie, inventaire[i].prix, inventaire[i].quantite);
                return;
            }
        }
        printf("Produit non trouvé.\n");
    } else if (choix == 2) {
        printf("Entrez la catégorie : ");
        scanf("%s", critere);
        printf("Produits dans la catégorie '%s' :\n", critere);
        int trouve = 0;
        for (int i = 0; i < taille; i++) {
            if (strcmp(inventaire[i].categorie, critere) == 0) {
                printf("- %s, Prix : %.2f, Quantité : %d\n",
                       inventaire[i].nom, inventaire[i].prix, inventaire[i].quantite);
                trouve = 1;
            }
        }
        if (!trouve) {
            printf("Aucun produit trouvé dans cette catégorie.\n");
        }
    } else {
        printf("Choix invalide.\n");
    }
}

void enregistrerInventaire(Produit *inventaire, int taille, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fwrite(&taille, sizeof(int), 1, fichier);
    fwrite(inventaire, sizeof(Produit), taille, fichier);
    fclose(fichier);
    printf("Inventaire sauvegardé dans le fichier '%s'.\n", nomFichier);
}

void chargerInventaire(Produit **inventaire, int *taille, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fread(taille, sizeof(int), 1, fichier);
    *inventaire = realloc(*inventaire, (*taille) * sizeof(Produit));
    if (*inventaire == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        fclose(fichier);
        exit(1);
    }
    fread(*inventaire, sizeof(Produit), *taille, fichier);
    fclose(fichier);
    printf("Inventaire chargé depuis le fichier '%s'.\n", nomFichier);
}
