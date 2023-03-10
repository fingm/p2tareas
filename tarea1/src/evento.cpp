#include "../include/evento.h"
#include <strings.h>

struct rep_evento {
    /************ Parte 4.1 ************/
    /*Escriba el código a continuación */
    int id;
    char descripcion[MAX_DESCRIPCION];
    TFecha fecha;
    /****** Fin de parte Parte 4.1 *****/
};

TEvento crearTEvento(int id, const char descripcion[MAX_DESCRIPCION], TFecha fecha) {
    /************ Parte 4.2 ************/
    /*Escriba el código a continuación */
    TEvento nuevoEvento = new rep_evento;
    nuevoEvento->id = id;
    nuevoEvento->fecha = fecha;
    strcpy(nuevoEvento->descripcion,descripcion);
    /****** Fin de parte Parte 4.2 *****/
    return nuevoEvento;
}

void imprimirTEvento(TEvento evento) {
    /************ Parte 4.3 ************/
    /*Escriba el código a continuación */
    if (evento != NULL){
        printf("Evento %d: ",evento->id);
        int tope = strlen(evento->descripcion)-1;
        for (int i = 0 ; i <= tope ; i++){
            printf("%c",evento->descripcion[i]);
        }
        printf("\nFecha: ");
        imprimirTFecha(evento->fecha);
    }
    /****** Fin de parte Parte 4.3 *****/
}

void liberarTEvento(TEvento &evento) {
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    if (evento != NULL){
        liberarTFecha(evento->fecha);
        delete evento;
        evento = NULL;
    }
    /****** Fin de parte Parte 4.4 *****/
}

int idTEvento(TEvento evento) {
    int res = 0;
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    if (evento != NULL){
        res = evento->id;
    }
    /****** Fin de parte Parte 4.4 *****/
    return res;
}

TFecha fechaTEvento(TEvento evento) {
    /************ Parte 4.4 ************/
    /*Escriba el código a continuación */
    return evento->fecha;
    /****** Fin de parte Parte 4.4 *****/
}

void posponerTEvento(TEvento &evento, int dias) {
    /************ Parte 4.5 ************/
    /*Escriba el código a continuación */
    if (evento!= NULL && dias >=1){
        aumentarTFecha(evento->fecha,dias);
    }
    /****** Fin de parte Parte 4.5 *****/
}
