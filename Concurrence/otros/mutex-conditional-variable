#include <iostream>
#include <bits/stdc++.h>

std::mutex lock;
std::condition_variable cv;
bool ready = false;

void trabajando(int id)
{
    std::unique_lock<std::mutex> lckTrabajando(lock);

    while(!ready) //El proceso previo "cualquiera" aun no se ha terminado y hay que esperarlo
        cv.wait(lckTrabajando); //Decimos que el lckTrabajando se va a esperar hasta que cv le diga que puede continuar

    std::cout << "Trabajador " << id << " esta trabajando" << std::endl;
}

int main()
{
    const int NUM_WORKS = 10;
    std::thread trabajadores[NUM_WORKS];

    for(int i = 0; i < NUM_WORKS; i++)
        trabajadores[i] = std::thread(trabajando, i);

    //Fingir un proceso cualquiera
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //Fin del proceso cualquiera

    //Seccionamos/Creamos un bloque de codigo para que el bloqueo exista sólo en este bloque y no en todo el bloque main
    {
        std::lock_guard<std::mutex> lckMain(lock);

        ready = true;
        cv.notify_all();
    }

    //Esperamos a que todos los hilos terminen su trabajo
    for(int i = 0; i < NUM_WORKS; i++)
        trabajadores[i].join();


    return 0;
}
