#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c;
    int i, j, temp;

    scanf("%d %d %d", &a, &b, &c);

    int v[3] = {a, b, c};

    for(i=0; i<2; i++)
    {
        for(j=i+1; j<3; j++)
        {
            if(v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }

    for(i=0; i<3; i++) { printf("%d\n", v[i]); }
    
    printf("\n%d\n%d\n%d\n", a, b, c);
    

/*
    int v[3], v2[3], aux;
    aux = 1;

    for(int i=0; i<3; i++)
    {
        scanf("%d", &v[i]);
        v2[i] = v[i];
    }

    while(aux != 0)
    {
        aux = 0;
        for(int i=0; i<3; i++)
        {
            if(i != 2)
            {
                if(v[i] > v[i+1])
                {
                    aux = v[i];
                    v[i] = v[i+1];
                    v[i+1] = aux;
                }
            }
        }

    }

    for(int i=0; i<3; i++)
    {
        printf("%d\n", v[i]);
    }
    printf("\n");
    for(int i=0; i<3; i++)
    {
        printf("%d\n", v2[i]);
    }   

*/

    return 0;
}