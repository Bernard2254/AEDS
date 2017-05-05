#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Valores
{
    int v_int;
    double v_dbl;
};

bool Compara_Valores(Valores e, Valores d);

int main()
{
    int i;
    int n = 10;
    int v1[] = {1, 7, 6, 8, 3, 4, 5, 9, 2, 0};
    string nms[] = {"wqa", "www", "bvc", "abc", "req", "aab", "bba", "aaa", "ahb", "cac"};
    Valores vals[] = {{9, 2.2}, {7, 1.3}, {9, 1.1}, {3, 4.1}, {7, 1.2}, {2, 3.4}, {1, 2.1}, {1, 1.2}, {5, 6.1}, {3, 4.2}};
    
    sort(v1+4, v1 + n);
    cout << "v1 crescente:" << endl;
    for(i = 0; i < n; i++) cout << v1[i] << ' ';
    cout << endl;
    
    sort(v1, v1 + n, [](int e, int d){return e > d;}); //Função lambda -> se a condição imposta for verdadeira, haverá troca no vetor
    cout << "v1 decrescente:" << endl;
    for(i = 0; i < n; i++) cout << v1[i] << ' ';
    cout << endl;
    
    sort(nms, nms + n);
    cout << "nms crescente:" << endl;
    for(i = 0; i < n; i++) cout << nms[i] << ' ';
    cout << endl;
    
    sort(vals, vals + n, &Compara_Valores);
    cout << "vals decrescente:" << endl;
    for(i = 0; i < n; i++) cout << vals[i].v_int << ' ' << vals[i].v_dbl << endl;
    
    return 0;
}

bool Compara_Valores(Valores e, Valores d)
{
    if(e.v_int < d.v_int)
        return true;
    else if(e.v_int == d.v_int && e.v_dbl < d.v_dbl)
        return true;
    else
        return false;
}
