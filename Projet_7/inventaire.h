#ifndef INVENTAIRE_H
#define INVENTAIRE_H

typedef struct {
    char nom[50];
    char categorie[50];
    float prix;
    int quantite;
} Produit;

void ajouterProduit(Produit **inventaire, int *taille);
void modifierProduit(Produit *inventaire, int taille);
void supprimerProduit(Produit **inventaire, int *taille);
void rechercherProduit(Produit *inventaire, int taille);
void enregistrerInventaire(Produit *inventaire, int taille, const char *nomFichier);
void chargerInventaire(Produit **inventaire, int *taille, const char *nomFichier);

#endif