








#include "vecin.h"
#include "vecout.h"
#include "veccalc.h"


int main()
{
    static_vector_t v1,v2,v3;
    
    printf("\n\n\nSTART:\n");
    printf("Author: Jan Czechowski\n");

    printf("Define v1:\n");
    switch(vec_fromkeyboard(&v1))
    {
        case _VEC_OK:
            break;
        case _VEC_NULL:
            printf("Error: NULL pointer\n");
            return 0;
        case _VEC_DIM:
            printf("Error: invalid vector length\n");
            return 0;
        case _VEC_INPUT:
            printf("Error: not a number\n");
            return 0;
        default:
            printf("Error: unknown\n");
            return 0;
     }
    
    printf("\nDefine v2:\n");
    switch(vec_fromkeyboard(&v2))
    {
        case _VEC_OK:
            break;
        case _VEC_NULL:
            printf("Error: NULL pointer\n");
            return 0;
        case _VEC_DIM:
            printf("Error: invalid vector length\n");
            return 0;
        case _VEC_INPUT:
            printf("Error: not a number\n");
            return 0;
        default:
            printf("Error: unknown\n");
            return 0;
     }
    
    //(b) display v1 and v2 here using functions defined in vecout.h
    printf("\nVector v1 (horizontal):\n");
    vec_print_horizontally(&v1);
 
    printf("\nVector v1 (vertical):\n");
    vec_print_vertically(&v1);
 
    printf("\nVector v2 (horizontal):\n");
    vec_print_horizontally(&v2);
 
    printf("\nVector v2 (vertical):\n");
    vec_print_vertically(&v2);
    double dot_product=0.0;
    //(c) calculate dot product of v1 and v2 using functions defined in veccalc.h. Provide full error handling. 
int err = 0;

dot_product = vec_dotproduct(&v1, &v2, &err);

if (err == _VEC_OK) {
    printf("\nv1 * v2 = %f\n", dot_product);
} else {
    printf("Error: Dot product calculation failed with error code %d\n", err);
    return 0;
}


    //(d) calculate v3=v1+v2 using functions defined in veccalc.h. Provide full error handling. 
printf("\nv1+v2=v3\n");
int sum_err = 0;

vec_sum(&v1, &v2, &v3, &sum_err);

if (sum_err == _VEC_OK) {
    printf("\nVector v3 (horizontal):\n");
    vec_print_horizontally(&v3);

    printf("\nVector v3 (vertical):\n");
    vec_print_vertically(&v3);
} else {
    printf("Error: Vector sum calculation failed with error code %d\n", sum_err);
    return 0;
}
    //(e) use vec_print_to_compare to inspect whether the sum is correct
    printf("\nInspecting vector addition correctness (v1 + v2 = v3):\n");
    vec_print_to_compare(&v1, &v2, &v3);
    

    return 0;
}


//Task 3:
//Answer 1:
/*
Dlaczego program się nie kompiluje po zakomentowaniu linii #ifndef, #define i #endif?

Zakomentowanie tych linii usuwa ochronę przed wielokrotnym dołączeniem pliku nagłówkowego.
Gdy plik veccommon.h zostanie dołączony więcej niż raz, kompilator napotka błędy 
wielokrotnej definicji symboli (np. stałych lub struktur). Mechanizm #ifndef zapobiega temu problemowi.
*/

//Answer 2:
/*
Dlaczego plik wykonywalny nie jest tworzony po zakomentowaniu zawartości pliku veccin.c?

Zakomentowanie zawartości veccin.c usuwa definicje funkcji potrzebnych programowi.
Kompilacja przebiega poprawnie, ale podczas linkowania linker nie znajduje wymaganych funkcji 
i zgłasza błąd „undefined reference”. W rezultacie plik wykonywalny nie powstaje.
*/



