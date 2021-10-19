#ifndef IMPUT_H_
#define IMPUT_H_


/// @brief Pide al usuario que ingrese un nro entero
///
/// @param mensaje
/// @return numeroIngresado
int PedirEntero (char mensaje[]);

/// @brief Pide al usuario que ingrese un nro entero validado entre un minimo y un maximo
///
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @return numeroIngresado
int PedirEnteroValidar(char mensaje[],char mensajeError[], int minimo, int maximo);

/// @brief Pide al usuario que ingrese un nro flotante
///
/// @param mensaje
/// @return numeroIngresado
float PedirFloat (char mensaje[]);

/// @brief Pide al usuario que ingrese un nro flotante validado entre un minimo y un maximo
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return numeroIngresado
float PedirFloatValidar(char mensaje[], int minimo, int maximo);

/// @brief Pide al usuario que ingrese un nro flotante validado entre un minimo de tipo flotante y un maximo de tipo flotante
///
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return numeroIngresado
float PedirFloatValidarConFloat(char mensaje[], float minimo, float maximo);

/// @brief
///
/// @param mensaje
/// @param stringIngresado
void PedirString (char mensaje[], char stringIngresado[]);


#endif /* IMPUT_H_ */
