using namespace std;

#ifndef fastest_way_hpp
#define fastest_way_hpp

class FastestWay{

    private:
        int n; //Numero di stazioni totali
        int **a; //matrice contenente il tempo necessario per passare da una stazione j alla stazione j+1 sulla medesima linea i
        int **t; //matrice contenente il tempo necessario per passare da una linea all'altra
        int *e; //Tempo di lavoro nelle stazioni iniziali 
        int *x; //tempo di lavoro stazioni in uscita 
        int *f1; //Array contenente il tempo minimo per raggiungere ogni stazione sulla prima linea
        int *f2; //Array contenente il tempo minimo per raggiungere ogni stazione sulla seconda linea
        int *L1; //Array contenente la linea scelta per continuare il percorso
        int *L2;
        int f_final; //Tempo migliore 
        int l_final; //Linea migliore
    public:
        FastestWay(int n, int **a, int **t, int e[2], int x[2]);
        int getFFinal();
        int getLFinal();
        void calcFasWay();

};

FastestWay::FastestWay(int n, int **a, int **t, int e[2], int x[2]){
    this->n = n;
    this->a = a;
    this->t = t;
    this->e = e;
    this->x = x;

    f1 = new int[n];
    f2 = new int[n];
    L1 = new int[n];
    L2 = new int[n];
}

int FastestWay::getFFinal(){
    return f_final;
}

int FastestWay::getLFinal(){
    return l_final;
}

void FastestWay::calcFasWay(){
    f1[1] = e[0] + a[0][0];
    f2[1] = e[1] + a[0][1];

    for(int j = 2; j <= n; j++){
        if(f1[j-1]+a[j-1][0] <= f2[j-1]+t[j-2][1]+a[j-1][0]){
            f1[j] = f1[j-1]+a[j-1][0];
            L1[j] = 1;
        }
        else{
            f1[j] = f2[j-1]+t[j-2][1]+a[j-1][0];
            L1[j] = 2;
        }
        if(f2[j-1]+a[j-1][1] <= f1[j-1]+t[j-2][0]+a[j-1][1]){
            f2[j] = f2[j-1]+a[j-1][1];
            L2[j] = 2;
        }
        else{
            f2[j] = f1[j-1]+t[j-2][0]+a[j-1][1];
            L2[j] = 1;
        }
    }

    if(f1[n]+x[0] <= f2[n]+x[1]){
        f_final = f1[n]+x[0];
        l_final = 1;
    }
    else{
        f_final = f2[n]+x[1];
        l_final = 2;
    }
}

#endif 