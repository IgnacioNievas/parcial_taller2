#include "parcial1.h"

int main(void){

ingresaProceso();
recorreCola();
mostrarScheduler();
return 0;
};

void asignaEstado(Proceso*p){
if(strcmp(p->estado,"Nuevo")==0){
    strcpy(p->estado,"Listo");
}else if(strcmp(p->estado,"Listo")==0){
    strcpy(p->estado,"Corriendo");
}else if(strcmp(p->estado,"Corriendo")==0){
strcpy(p->estado,"Terminado");
}
};

void ingresaProceso(){
 srand(getpid());
    for(int i=0 ; i < N ;i++){
        
        if(scheduling[i]==NULL){
     scheduling[i]=(Proceso*) malloc(sizeof(Proceso));
   assert(  scheduling[i] != NULL );
      scheduling[i]->prioridad=id;
      scheduling[i]->procesador=id;
      scheduling[i]->id_proceso= rand() % 55555;
       strcpy( scheduling[i]->estado,"Nuevo");

    }

    }

};

int terminaProceso(){
    int libre;

    for(int i = 0;i< N; i++){
        if(strcmp(scheduling[i]->estado,"Terminado")==0){
            free(*(scheduling+i));
            libre= i;
        }
  }

  return libre;
};

void recorreCola(){
// int libre;
//   for(int i =0; i<N ;i++){ 
    
    //   scheduling[i]->prioridad=id++;
    //   scheduling[i]->procesador=rand()%2;
    //   asignaEstado( scheduling[i]);
  //}  
//libre =terminarProceso();
// scheduling[libre]=NULL;    
};

void mostrarScheduler(){
    for(int i=0;i< N;i++){
    printf("[%d]-> {%d ; %d ; %d ;%s }\n",i ,scheduling[i]->procesador,scheduling[i]->id_proceso,scheduling[i]->prioridad,scheduling[i]->estado);}
};