#include <iostream>
#include <bits/stdc++.h>


// Funci�n que se ejecutar� en paralelo en cada hilo
void tarea_larga_V2(int id)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Tarea larga " << id << " terminada " << std::endl;
}

int main()
{
    const int TAM_HILOS = 5;
    std::cout << "Comenzando hilos..." << std::endl;
    std::thread hilos[TAM_HILOS];
    for(int i = 0; i < TAM_HILOS; i++)
        hilos[i] = std::thread(tarea_larga_V2, i);

    std::cout << "Hilos iniciados" << std::endl;
    for(int i = 0; i < TAM_HILOS; i++)
    {
        while(hilos[i].joinable())
        {
            hilos[i].join();
            std::cout << "Sigo haciendo otra tarea mientras espero al hilo " << i << std::endl;
        }
    }

    std::cout << "Todos los hilos terminados" << std::endl;

    return 0;
}
