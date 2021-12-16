#include <array>
#include <vector>

class Matrice{
    public:
    Matrice(std::vector<double> matrice,int l, int c);
    Matrice(const Matrice& autre); 
    void add(Matrice autre);
    void mult(Matrice autre);

    private:
    int l;
    int c;
    bool carree{false};
    std::vector<double> matrice;
};


Matrice::Matrice(std::vector<double> matrice, int n_lignes, int n_colonnes ):l(n_lignes),c(n_colonnes){
    if(l==c){
        this->carree = true;
    }
    this->matrice = matrice;
        
}

Matrice::Matrice(const Matrice& autre){
    this->l = autre.l;
    this->c = autre.c;
    this->matrice = autre.matrice;
}

void Matrice::add(Matrice autre){
    if(autre.l == this->l && autre.c == this->c){
        for(int i=0;i<this->matrice.size();i++){
            this->matrice[i] += autre.matrice[i];
        }
    }

}

void Matrice::mult(Matrice autre){
    for(int I=0;I<this->matrice.size();I++){
        int i = I% this->c;
        int j = I / this->c;
    }



}

int main(int argc, char** argv){
<<<<<<< HEAD

=======

//ya rien ici
>>>>>>> master
}

