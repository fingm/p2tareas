#include "../include/fecha.h"

struct rep_fecha {
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes ,anio;
    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio) {
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    TFecha nuevaFecha = new rep_fecha;
    nuevaFecha->dia  = dia;
    nuevaFecha->mes  = mes;
    nuevaFecha->anio = anio;
    return nuevaFecha;
    /****** Fin de parte Parte 3.1 *****/
}

void liberarTFecha(TFecha &fecha) {
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    if (fecha != NULL){
        delete fecha;
        fecha = NULL;
    }
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha) {
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    if (fecha != NULL){
        printf("%d/%d/%d\n",fecha->dia,fecha->mes,fecha->anio);
    }

    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/


int diasmes (TFecha &fecha){
    int res = 31;
    if (fecha->mes == 2){
        if ((fecha->anio % 4) == 0){
            res = 29;
        }else{
            res = 28;
        }
    }else if((fecha->mes == 4) || (fecha->mes == 6) || (fecha->mes == 9) || (fecha->mes == 11)){
        res = 30; 
    } 
    return res;
}

void aumentarTFecha(TFecha &fecha, nat dias) {
    if (fecha != NULL){
        fecha->dia += dias;
        nat dias = diasmes(fecha);    
        while(fecha->dia > dias){
            fecha->dia -= dias;
            fecha->mes++;
            if(fecha->mes == 13){
                fecha->mes = 1;
                fecha->anio++;
            }
            dias = diasmes(fecha);
        }
    }
}

/****** Fin de parte Parte 3.9 *****/

int compararTFechas(TFecha fecha1, TFecha fecha2) {
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    if (fecha1 != NULL && fecha2 != NULL){
        if(fecha1->anio < fecha2->anio){
            res = -1;
        }else if (fecha1->anio > fecha2->anio){
            res = 1;
        }else{
            if (fecha1->mes < fecha2->mes){
                res = -1;
            }else if (fecha1->mes > fecha2->mes){
                res = 1;
            }else{
                if(fecha1->dia < fecha2->dia){
                    res = -1;
                }else if (fecha1->dia > fecha2->dia){
                    res = 1;
                }else{
                    res = 0;
                }
            }
        }
    }

    /****** Fin de parte Parte 3.10 *****/
    return res;
}
