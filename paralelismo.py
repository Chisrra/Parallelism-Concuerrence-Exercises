import threading
import time

def tarea_larga():
    # Simulamos una tarea larga que toma 5 segundos en completarse
    time.sleep(5)
    print("Tarea larga terminada")

def tarea_hilos():
    print("Comenzando hilos...")
    hilos = []
    for i in range(5):
        hilo = threading.Thread(target=tarea_larga)
        hilos.append(hilo)
        hilo.start()
    
    print("Hilos iniciados")
    # Esperamos a que los hilos terminen por un tiempo máximo de 2 segundos
    for hilo in hilos:
        hilo.join(timeout=2)
        print("Sigo haciendo otras cosas mientras espero")
    
    print("Hilos terminados")

if __name__ == '__main__':
    tarea_hilos()
    print("Proceso principal terminado")
