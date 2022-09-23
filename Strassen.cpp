#include<iostream>
using namespace std;
double a[4][4];
double b[4][4];

void insert(double x[4][4]) {
    double val;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 4; j++)
        {
            cin>>val;
            x[i][j] = val;
        }
        
    }
    
}
double col11(double x[4][4]) {
    return (x[1][1] * x[1][2]) + (x[1][2] * x[2][1]);

}
double col21(double x[4][4]) {
    return (x[3][1] * x[4][2]) + (x[3][2] * x[4][1]);
}
double col12(double x[4][4]) {
    return (x[1][3] * x[2][4]) + (x[1][4] * x[2][3]);
}
double col22(double x[4][4]) {
    return (x[2][3] * x[1][4]) + (x[2][4] * x[1][3]);
}

int main() {
    double a11,a12,a22,a21,b11,b12,b21,b22,a[4][4],b[4][4];
    double p,q,r,s,t,u,v,c11,c12,c21,c22;
    
    // insertion des valeurs dans la matrice a
    cout<<"\n a: \n";
    insert(a);
    // insertion des valeurs dans la matrice b
    cout<<"\n b: \n";
    insert(b);

    // division d'une seule matrice 4*4 en quatre matrices 2*2
    a11 = col11(a);
    a12 = col12(a);
    a21 = col21(a);
    a22 = col22(a);
    b11 = col11(b);
    b12 = col12(b);
    b21 = col21(b);
    b22 = col22(b);

    // affectation des variables selon l'algorithme de strassen
    p = (a11+a22) * (b11+b22);
    q = (a21+a22) * b11;
    r = a11 * (b12-b22);
    s = a22 * (b21-b11);
    t = (a11+a12) * b22;
    u = (a11-a21) * (b11+b12);
    v = (a12-a22) * (b21+b22);

    // sortie de la matrice finale
    cout<<"\n matrice finale";
      cout<<"\n"<<p+s-t+v<<" "<<r+t;
      cout<<"\n"<<q+s<<" "<<p+r-q+u;
      return 0;
}
