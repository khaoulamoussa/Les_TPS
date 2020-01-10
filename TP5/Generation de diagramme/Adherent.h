#ifndef Adherent_h
#define Adherent_h

class Livre;
class Bibliotheque;
class Emprunte;

class Adherent {

 public:

    virtual void emprunterLivre();

    virtual void rendreLivre();

 public:
    String prenom;
    String nom;

 public:

    Livre *0..n;

    /**
     * @element-type Bibliotheque
     */
    Bibliotheque *myBibliotheque;

    /**
     * @element-type Emprunte
     */
    Emprunte *myEmprunte;
};

#endif // Adherent_h
