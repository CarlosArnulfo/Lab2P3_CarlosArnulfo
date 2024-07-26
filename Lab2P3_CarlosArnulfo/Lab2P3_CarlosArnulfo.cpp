#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generarFibonacci(array<int,20> fibonacci,int longitud) {//imprimo cuantos valores del fibonacci el usuario haya decidido imprimir
    cout << "Secuencia de Fibonacci de longitud " << longitud <<": "<< endl;
    for (int item = 0; item < longitud; item++)
    {
        cout << fibonacci[item] << " ";
    }
    cout << endl;
}

void Fibonacci() {
    cout << "Ingrese un numero entre 1 y 20 para la longitud del fibonacci"<<endl;
    int longitud = 0;
    array<int, 20> fibonacci;
    fibonacci[0] = 0;
    fibonacci[1] = 1;
    for (int item = 2; item < 20; item++)
    {
        fibonacci[item] = fibonacci[item - 1] + fibonacci[item - 2];//hago un fibonacci hardcoded de 20 numeros, el usuario cree que los esta generando, sin embargo solo esta decidiendo cuantos seran impresos de estos 20 hardcoded
    }
    do
    {
        cin >> longitud;//el usuario ingresa cuantos numeros seran impresos
        if (longitud > 20 || longitud < 1) //validacion de entrada para cuantos numeros de fibonacci seran impresos
        {
            cout << "La longitud debe ser mayor a 0 y menor que 100" << endl;
        }
    } while (longitud>20||longitud<1);
    generarFibonacci(fibonacci,longitud);
}



bool GenerarRetroalimentacion(array<char,5> numberle ,array<char,5> input, int longitud=5) {
    bool victoria=false;
    array<char, 5> respuesta = {'x','x','x','x','x'};

    for (int item = 0; item < longitud; item++)//la retroalimentacion verifica primero los numeros uno por uno para ver los valores que tienen mismo valor en misma posicion
    {
        if (input[item]==numberle[item])
        {
            respuesta[item] = '+';
        }
    }

    for (int itemNumberle = 0; itemNumberle < longitud; itemNumberle++)//luego comparamos todos los valores del input ingresado con todos los valores del numberle
    {
        for (int itemInput = 0; itemInput < longitud; itemInput++)
        {
            if (input[itemInput]==numberle[itemNumberle]&&respuesta[itemInput]!='+')//uno por uno, si el valor en la respuesta ya tiene un '+', entonces no se hace nada, de lo contrario, si un valor es igual al del numberle, su posicion en la retroalimentacion cambia por un '-'
            {
                respuesta[itemInput] = '-';
            }
        }
    }

    for (int item = 0; item < longitud; item++)
    {
        cout << respuesta[item];
    }

    cout << endl;
    if (respuesta[0]=='+'&& respuesta[1] == '+'&& respuesta[2] == '+'&& respuesta[3] == '+'&& respuesta[4] == '+')
    {
        victoria = true;
    }
    return victoria;//al final la retroalimentacion tambien regresa un boolean de verificacion de victoria en caso de que la respuesta del usuario sea correcta
}


void Numberle() {
    int intentos = 0;
    int decision = 0;
    int max = 0;
    cout << "1. dificultad facil" << endl;
    cout << "2. dificultad normal" << endl;
    cout << "3. dificultad dificil" << endl;
    cin >> decision;
    while (decision>3||decision<1) {
        cout << "Ingrese una opcion valida (entre 1 y 3)" << endl;
        cin >> decision;
    }
    
    if (decision==1) {
        intentos = 20;
        max = 5;
    }
    else if (decision==2) {
        intentos = 15;
        max = 7;
    }
    else {
        intentos = 10;
        max = 10;
    }
    array<char, 5> input;
    
    array<char, 5> numberle;
    for (int num = 0; num < 5; num++)
    {
        numberle[num] = rand() % max+48;//generacion del numberle
    }
    char numeroIngresado=0;
    cout << "--- Comienza el juego ---" << endl;
    bool victoria=false;
    while (intentos) {
        cout << "Te quedan " << intentos << " intentos " << endl;
        intentos--;
        numeroIngresado = 0;
            cout << "Ingrese un numero de 5 digitos: ";//input del usuario
            for (int item = 0; item < 5; item++)
            {
                cin >> input[item];
            }
        
            cout << "tu entrada: ";
        for (int item = 0; item < 5; item++)
        {
            cout<<input[item];
        }
        cout<< endl;
        
        cout << "Retroalimentacion de este intento: ";
        victoria=GenerarRetroalimentacion(numberle,input);
        if (victoria)
        {
            
            intentos = 0;
        }
        
    }
    cout << "El juego a terminado!" << endl;
    if (!victoria)
    {
        cout << "perdiste womp womp" << endl;
    }
    else {
        cout << "Felicidades, ganaste el Numberle!" << endl;
    }
}


int main()
{
    srand(time(NULL));
    int menu = 0;
    do
    {
        cout << "1. Numberle" << endl;
        cout << "2. Fibonacci"<<endl;
        cout << "3. Salir" << endl;
        cin >> menu;

        if (menu == 1)
        {
            Numberle();
        }
        else if (menu == 2) {
            Fibonacci();
        }
        else if (menu==3) {
            cout << "gracias por revisar mi laboratorio" << endl;
        }
        else {
            cout << "Ingrese un numero valido" << endl;
        }
    } while (menu!=3);
}