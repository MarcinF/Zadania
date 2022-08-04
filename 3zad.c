#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
//English only
char los;
void* losowanie() //losowanie p-papier, k-kamien, n-nozyce
{
int liczba = rand()%3+1;
if(liczba == 1){
  los = 'p';
}
else if (liczba == 2){
  los = 'k';
}
else{
  los = 'n';
}

int* wynik = malloc(sizeof(int));
*wynik = los;

    return (void*) wynik;
}


int main()
{
    int* wynik_gracz1;
    int* wynik_gracz2;
    int g1=0;
    int g2 =0;
    int remis =0;

  srand(time(NULL));
  pthread_t gracz1;
  pthread_t gracz2;

  for(int i=0; i<10; i++)
  {
    printf("gra numer: %d\n",i+1);
    pthread_create(&gracz1, NULL, &losowanie, NULL);
    sleep(1);
    pthread_create(&gracz2, NULL, &losowanie, NULL);
    pthread_join(gracz1, (void**)&wynik_gracz1);
    pthread_join(gracz2, (void**)&wynik_gracz2);

    printf("gracz 1 - %c, gracz 2 - %c\n", *wynik_gracz1, *wynik_gracz2);
    if(*wynik_gracz1 == *wynik_gracz2){
    printf("-----Remis-----\n");
    remis++;
    }
    if (*wynik_gracz1 == 'k' && *wynik_gracz2 == 'p'){
    printf("-----Wygrywa gracz 2-----\n");
    g2++;
    }
    else if (*wynik_gracz1 == 'p' && *wynik_gracz2 == 'k'){
    printf("-----Wygrywa gracz 1-----\n");
    g1++;
    }

    if (*wynik_gracz1 == 'k' && *wynik_gracz2 == 'n'){
    printf("-----Wygrywa gracz 1-----\n");
    g1++;
    }
    else if (*wynik_gracz1 == 'n' && *wynik_gracz2 == 'k'){
    printf("-----Wygrywa gracz 2-----\n");
    g2++;
    }
    if (*wynik_gracz1 == 'n' && *wynik_gracz2 =='p'){
    printf("-----Wygrywa gracz 1-----\n");
    g1++;
    }
    else if(*wynik_gracz1 == 'p' && *wynik_gracz2 == 'n'){ //gracz1 przegrywa
    printf("-----Wygrywa gracz 2-----\n");
    g2++;
    }
  }
  printf("\nRemis padl - %d razy\n", remis);
  printf("\nGracz 1 wygral - %d razy\n", g1);
  printf("\nGracz 2 wygral - %d razy\n", g2);

  if(remis>g1 && remis>g2)
  {
    printf("\n-----Remis pojawial sie najczesciej - %d-----\n", remis);
  }
  else if (g1>remis && g1>g2)
  {
    printf("\n-----Gracz 1 wygrywal najczesciej - %d-----\n", g1);
  }
  else if(g2>remis && g2>>g1)
  {
    printf("\n-----Gracz 2 wygrywal najczesciej - %d-----\n", g2);
  }
  return 0;
}
