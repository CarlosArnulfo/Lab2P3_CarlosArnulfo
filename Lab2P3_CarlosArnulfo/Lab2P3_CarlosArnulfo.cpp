#include <iostream>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool GenerarRetroalimentacion(array<char,5> numberle ,array<char,5> input) {
    bool victoria=false;
    array<char, 5> respuesta = {'x','x','x','x','x'};

    for (int item = 0; item < 5; item++)
    {
        cout << numberle[item]<<endl;
        if (input[item]==numberle[item])
        {
            respuesta[item] = '+';
        }
    }

    for (int itemNumberle = 0; itemNumberle < 5; itemNumberle++)
    {
        for (int itemInput = 0; itemInput < 5; itemInput++)
        {
            if (input[itemInput]==numberle[itemNumberle]&&respuesta[itemNumberle]!='+')
            {
                respuesta[itemNumberle] = '-';
            }
        }
    }

    for (int item = 0; item < 5; item++)
    {
        cout << respuesta[item];
    }

    cout << endl;
    if (respuesta[0]=='+'&& respuesta[1] == '+'&& respuesta[2] == '+'&& respuesta[3] == '+'&& respuesta[4] == '+')
    {
        victoria = true;
    }
    return victoria;
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
        numberle[num] = rand() % max+48;
    }
    char numeroIngresado=0;
    cout << "--- Comienza el juego ---" << endl;
    bool victoria=false;
    while (intentos) {
        cout << "Te quedan " << intentos << " intentos " << endl;
        intentos--;
        numeroIngresado = 0;
            cout << "Ingrese un numero de 5 digitos" << endl;
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
        
        cout << "Retroalimentacion" << endl;
        GenerarRetroalimentacion(numberle,input);
        if (victoria)
        {
            cout << "Felicidades, ganaste el Numberle" << endl;
            intentos = 0;
        }
        
    }
    if (!victoria)
    {
        cout << "perdiste womp womp" << endl;
    }
}


int main()
{
    srand(time(NULL));
    int menu = 0;
    do
    {
        cout << "1. Numberle" << endl;
    } while (menu);
    Numberle();
}