

void P (semaforo s){
    if (s > 0)
    s = s -1;
    else
    pause();
}

void V (semaforo a){
    if(ExisteProcessoEsperando(s))
        AtivaProcessoEsperando(s);
    else
        s = s +1;
}

semaforos binarios ou mutex.

######

#define N 10

semaforo mutex = 1;
semaforo vazio = N;
semaforo cheio = 0;

void produtor(void){
    int item;
    while(1)
    {
        produz_algum_item();
        P(&vazio);
        P(&mutex);
        insere_item_produzido();
        V(&mutex);
        V(&cheio);
    }
}
void consumidor(void){
    int item;
    while(1)
    {
        produz_algum_item();
        P(&cheio);
        P(&mutex);
        remove_item();
        V(&mutex);
        V(&vazio);
        consome_item(item);
    }
}