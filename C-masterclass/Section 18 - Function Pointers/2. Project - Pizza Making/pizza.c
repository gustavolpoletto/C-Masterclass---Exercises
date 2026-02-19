//sistem to automate the process of making pizza
// Pizza = dough + sauce + cheese
// but there are 2 tipes of dough, 2 of sauce and 2 different cheese -> 8 combinations
     // but only 1 function to create an customizable pizzas

#include <stdio.h>

void thinDough ()
{
    printf("Thin Dough\n");
}

void thickDough ()
{
    printf("Thick Dough\n");
}

void tomatoSauce ()
{
    printf("Tomato Sauce\n");
}

void pastaSauce ()
{
    printf("Pasta Sauce\n");
}

void MozzarelaCheese ()
{
    printf("Mozzarela Cheese\n");
}

void CheddarCheese ()
{
    printf("Ceeddar Cheese\n");
}

void makePizza (void(*dough)(),void(*sauce)(),void(*cheese)())
{
    dough();
    sauce();
    cheese();
}

int main ()
{
    void (*dough[])() = {thinDough , thickDough};
    void (*sauce[])() = {tomatoSauce , pastaSauce};
    void (*cheese[])() = {MozzarelaCheese , CheddarCheese};

    printf("-PIZZA 1-\n");
    makePizza(dough[1], sauce[0], cheese[1]);

    printf("\n");

    printf("-PIZZA 2-\n");
    makePizza(dough[0], sauce[1], cheese[0]);
}
