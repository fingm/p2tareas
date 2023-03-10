#include "../include/agenda.h"

struct rep_agenda {
    /************ Parte 5.1 ************/
    /*Escriba el código a continuación */
    int tope;
    TEvento ag[MAX_EVENTOS];
    /****** Fin de parte Parte 5.1 *****/
};

TAgenda crearTAgenda() {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    TAgenda nuevaAgenda = new rep_agenda;
    nuevaAgenda->tope = 0;
    /****** Fin de parte Parte 5.2 *****/
    return nuevaAgenda;
}

bool esvaciaAgenda(TAgenda ag){
    return ag == NULL;
}

void hacerlugar(TAgenda &agenda,int lugar){
    agenda->tope++;
    int tope = agenda->tope-1;
    while(tope > lugar){
        agenda->ag[tope] = agenda->ag[tope-1];
        tope--;
    }
}

/// @brief 
/// @param agenda 
/// @param evento 
void agregarEnAgenda(TAgenda &agenda, TEvento evento) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (!esvaciaAgenda(agenda)){
        if(agenda->tope == 0){
            agenda->ag[0] = evento;
            agenda->tope++;
        }else{
            if(agenda->tope == 1){
                int aux = compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->ag[0]));
                if(aux <= 0){
                    agenda->ag[1] = agenda->ag[0];
                    agenda->ag[0] = evento;
                    agenda->tope++;
                }else{
                    agenda->ag[1] = evento;
                    agenda->tope++;
                }
            }else{
                if((compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->ag[0]))) == 0){
                    hacerlugar(agenda,0);
                    agenda->ag[0] = evento;
                }else if((compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->ag[0]))) == -1){
                    hacerlugar(agenda,0);
                    agenda->ag[0] = evento;
                }else{
                    int pos = 0;
                    int aux;
                    while((pos<= agenda->tope-1) && (compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->ag[pos]))) == 1){
                        pos++;
                        if((pos<= agenda->tope-1)){
                            aux = compararTFechas(fechaTEvento(evento),fechaTEvento(agenda->ag[pos]));
                        }
                    }
                    if(aux == 1){
                        agenda->tope++;
                        agenda->ag[agenda->tope-1] = evento;
                    }else if (aux == 0){
                        if(pos == agenda->tope){
                            agenda->tope++;
                            agenda->ag[agenda->tope-1] = evento;
                        }else{
                            hacerlugar(agenda,pos);
                            agenda->ag[pos] = evento;
                        }
                    }else if(aux == -1){
                        hacerlugar(agenda,pos);
                        agenda->ag[pos] = evento;
                    }
                } 
            }
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

void liberarTAgenda(TAgenda &agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if (agenda != NULL){
        while(agenda->tope > 0){
            liberarTEvento(agenda->ag[agenda->tope-1]);
            agenda->tope--;
        }
        delete agenda;
       agenda = NULL;
    }
    /****** Fin de parte Parte 5.2 *****/
}

void imprimirTAgenda(TAgenda agenda) {
    /************ Parte 5.2 ************/
    /*Escriba el código a continuación */
    if(!esvaciaAgenda(agenda)){
        for(int i=0; i<=agenda->tope-1 ; i++){
            imprimirTEvento(agenda->ag[i]);
        }
    }
    /****** Fin de parte Parte 5.2 *****/
}

bool estaEnAgenda(TAgenda agenda, int id) {
    /************ Parte 5.4 ************/
    /*Escriba el código a continuación */
    bool res = false;
    if(agenda != NULL){
        if(agenda->tope>0){
            int contador = 0;
            bool encontrado = false;
            while(contador <= agenda->tope-1 && !encontrado){
                if(idTEvento(agenda->ag[contador]) == id){
                    res = true;
                    encontrado = true;
                }
                contador++;
            }
        }
    }
    /****** Fin de parte Parte 5.4 *****/
    return res;
}

TEvento obtenerDeAgenda(TAgenda agenda, int id) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    int cont = 0;
    while(idTEvento(agenda->ag[cont]) != id){
        cont++;
    }
    /****** Fin de parte Parte 5.5 *****/
    return agenda->ag[cont];
}

void posponerEnAgenda(TAgenda &agenda, int id, nat n) {
    /************ Parte 5.5 ************/
    /*Escriba el código a continuación */
    if(!esvaciaAgenda(agenda)){
        int pos = 0;
        while(idTEvento(agenda->ag[pos]) != id){
            pos++;
        }
        posponerTEvento(agenda->ag[pos],n);
        bool fin = false;
        while((pos <= agenda->tope-2) && !fin){
            if(compararTFechas(fechaTEvento(agenda->ag[pos]),fechaTEvento(agenda->ag[pos+1])) == 1){
                TEvento aux = agenda->ag[pos+1];
                agenda->ag[pos+1] = agenda->ag[pos];
                agenda->ag[pos] = aux;
            }else{
                fin = true;
            }
            pos++;
        }
    }
    /****** Fin de parte Parte 5.5 *****/
}

void imprimirEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    if (!esvaciaAgenda(agenda)){
        int pos = 0;
        bool fin = false;
        while((pos <= agenda->tope-1) && !fin){
            if((compararTFechas(fechaTEvento(agenda->ag[pos]),fecha)) == 0){
                while((pos <= agenda->tope-1) && (compararTFechas(fechaTEvento(agenda->ag[pos]),fecha)) == 0){
                    imprimirTEvento(agenda->ag[pos]);
                    pos++;
                }
                fin = true;    
            }
            pos++;
        }
    }
    /****** Fin de parte Parte 5.7 *****/
}

bool hayEventosFecha(TAgenda agenda, TFecha fecha) {
    /************ Parte 5.7 ************/
    /*Escriba el código a continuación */
    /*La función debe ejecutar una versión */
    /*Iterativa del algoritmo de búsqueda  */
    /*binaria.                              */
    bool res = false;
    if ((agenda != NULL) && (agenda->tope > 0)){
        int inf = 0;
        int sup = agenda->tope-1;
        int mitad;
        while((inf < sup) && !res){
            mitad = (inf+sup)/2;
            if((compararTFechas((fechaTEvento(agenda->ag[mitad])),fecha))== 0){
                res = true;
            }
            if((compararTFechas((fechaTEvento(agenda->ag[mitad])),fecha))== 1){
                sup = mitad;
                mitad = (inf+sup)/2;
            }
            if((compararTFechas((fechaTEvento(agenda->ag[mitad])),fecha))== -1){
                sup = mitad;
                mitad = (inf+sup)/2;
            }
        }            
    }
    return res;
    /****** Fin de parte Parte 5.7 *****/
}

void removerDeAgenda(TAgenda &agenda, int id) {
    /************ Parte 5.8 ************/
    /*Escriba el código a continuación */
    if(!esvaciaAgenda(agenda)){
        if(agenda->tope == 1){
            liberarTEvento(agenda->ag[0]);
            agenda->tope--;
        }else{
            if(idTEvento(agenda->ag[0]) == id){
                if(agenda->tope == 2){
                    liberarTEvento(agenda->ag[0]);
                    agenda->ag[0] = agenda->ag[1];
                    agenda->tope--;
                }else{
                    liberarTEvento(agenda->ag[0]);
                    int pos = 0;
                    while(pos <= (agenda->tope-2)){
                      agenda->ag[pos] = agenda->ag[pos+1];
                      pos++;
                    }
                    agenda->tope--;
                }
            }else if(idTEvento(agenda->ag[agenda->tope-1]) == id){
                liberarTEvento(agenda->ag[agenda->tope-1]);
                agenda->tope--;
            }else{
                int pos = 0;
                while(idTEvento(agenda->ag[pos]) != id){
                    pos++;
                }
                liberarTEvento(agenda->ag[pos]);
                while(pos <= agenda->tope-2){
                    agenda->ag[pos] = agenda->ag[pos+1];
                    pos++;
                }
                agenda->tope--;
            }
        }
    }
    /****** Fin de parte Parte 5.8 *****/
}






