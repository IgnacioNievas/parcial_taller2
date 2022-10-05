#include "parcial1.h"

int main(void){
 srand(getpid());
 for(int i =0; i<N ;i++){ 
     scheduling[i]=NULL;
 }

 for(int i =0; i<6 ;i++){ 
ingresaProceso();
ingresaProceso();
ingresaProceso();
mostrarScheduler();
printf("\n");
recorreCola();
mostrarScheduler();
printf("\n");
ingresaProceso();
ingresaProceso();
mostrarScheduler();
printf("\n");
recorreCola();
mostrarScheduler();
printf("\n");
}
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

    for(int i=0 ; i < N ;i++){
        
        if(scheduling[i]==NULL){
     scheduling[i]=(Proceso*) malloc(sizeof(Proceso));
   assert(  scheduling[i] != NULL );
      scheduling[i]->prioridad=id++;
      scheduling[i]->procesador=0;
      scheduling[i]->id_proceso= 1+ rand() % 55555;
       strcpy( scheduling[i]->estado,"Nuevo");
break;
    }

    }

};

void terminaProceso(int libre){
         free(*(scheduling+libre));
         scheduling[libre]=NULL;
       
  }




void recorreCola(){
 int priorid,proce = 0;

      for(int i = 0;i< N; i++){
        if(scheduling[i]!=NULL){
                         if(strcmp(scheduling[i]->estado,"Terminado")==0){
                                priorid = scheduling[i]->prioridad;
                                        terminaProceso(i);
                                                                 }
                                                                    }
                                                                      }
      for(int i = 0;i< N; i++){
        if(scheduling[i]!= NULL){
            if((proce < 2 && (scheduling[i]->prioridad == priorid+1 ))||(proce < 2 && (scheduling[i]->prioridad == priorid+2 ))){
                scheduling[i]->procesador= proce + 1;
                proce++;
            }else if((proce < 2 && (scheduling[i]->prioridad == 1 ))||(proce < 2 && (scheduling[i]->prioridad == 2 ))){
                 scheduling[i]->procesador=proce+1;
                  proce++;
            }
    
      asignaEstado( scheduling[i]);  }
                                       }
  
};

void mostrarScheduler(){
    for(int i=0;i< N;i++){
        if(scheduling[i]!=NULL){
    printf("[%d]-> {%d ; %d ; %d ;%s }\n",i ,scheduling[i]->procesador,scheduling[i]->id_proceso,scheduling[i]->prioridad,scheduling[i]->estado);
    }else{
        printf("[%d] \n",i);
    }
    }
};