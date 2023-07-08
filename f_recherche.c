#include <stdlib.h>
#include <stdio.h>

int f_optimal(int n,int x,int**tab);
int max(int a,int b);
int main(){
  int n,i,x,t,resultat;
  int **tab;
  printf("Quelle est la taille du tableau?\n");
  scanf("%d",&n);
  tab=malloc(sizeof(int*)*2);
  tab[0]=malloc(sizeof(int)*n);
  tab[1]=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    printf("Entrer la donnée du temps %d de la calculatrice A \n",i+1);
    scanf("%d",&tab[0][i]);
  }
  for(i=0;i<n;i++){
    printf("Entrer la donnée du temps %d de la calculatrice B \n",i+1);
    scanf("%d",&tab[1][i]);
  }
  printf("Choisissez la valeur de X\n 0 pour A\n 1 pour B\n");
  scanf("%d",&x);
  printf("Choisissez la valeur de T\n");
  scanf("%d",&t);
  resultat=f_optimal(t,x,tab);
  if(x==0)printf("f(%d,A)=%d\n",t,resultat);
  else printf("f(%d,B)=%d\n",t,resultat);
  free(tab[0]);
  free(tab[1]);
  free(tab);
}
int f_optimal(int n,int x,int**tab){
  if(n<=0){
    return 0;
  }
  if(n==1){
    if(x==1)
      return tab[1][0];
    else
      return tab[0][0];
  }else{
    return max(f_optimal(n-1,x,tab),f_optimal(n-2,!x,tab))+tab[x][n-1];
  }
}
int max(int a,int b){
  if(a<b)
    return b;
  else
    return a;
}
