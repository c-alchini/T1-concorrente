#include <stdlib.h>

#include "globals.h"

//**********************************************************************************
//PARA FAZER:
//Implementar as variáveis globais
// - Alguma ideia como compartilhar essas variáveis desse arquivo com os outros?
//**********************************************************************************

/*
    VOCÊ DEVE CRIAR VARIÁVEIS GLOBAIS PARA ARMAZENAR DADOS SOBRE A SIMULAÇÃO.
    NOTAS:
    1.  OS SEGUINTES DADOS DEVEM SER ARMAZENADOS E PRINTADOS AO FIM DA SIMULAÇÃO:
        a. Quantidade de clientes que sentaram-se no conveyor e consumiram todos os itens desejados
        b. Quantidades produzidas de cada alimento
        c. Quantidades consumidas de cada alimento
    2.  SIGA OS EXEMPLOS DE VARIÁVEIS GLOBAIS JÁ EXISTENTES NESSE ARQUIVO PARA CRIAR AS NOVAS.
*/

/* Codigo para soma de comidas preparadas */
struct food_prepared global_food_prepared = { 0, 0, 0, 0, 0 };

void globals_increment_food_prepared(enum menu_item food) {
    switch (food) {
    case Sushi:
        global_food_prepared.sushi++;
        break;
    case Dango:
        global_food_prepared.dango++;
        break;
    case Ramen:
        global_food_prepared.ramen++;
        break;
    case Onigiri:
        global_food_prepared.onigiri++;
        break;
    case Tofu:
        global_food_prepared.tofu++;
        break;
    default:
        fprintf(stdout, RED "[ERROR] Invalid menu_item variant passed to `globals_increment_food_prepared()`.\n" NO_COLOR);
        exit(EXIT_FAILURE);
    }
}

int globals_get_food_prepared(enum menu_item food) {
    switch (food) {
    case Sushi:
        return global_food_prepared.sushi;
    case Dango:
        return global_food_prepared.dango;
    case Ramen:
        return global_food_prepared.ramen;
    case Onigiri:
        return global_food_prepared.onigiri;
    case Tofu:
        return global_food_prepared.tofu;
    default:
        fprintf(stdout, RED "[ERROR] Invalid menu_item variant passed to `customer_eat()`.\n" NO_COLOR);
        exit(EXIT_FAILURE);
    }
}

/* Fim do Codigo para soma de comidas preparadas */


struct sushi_consumed global_sushi_cons = { 0 };

void globals_increment_sushi_consumed() {
    pthread_mutex_lock(&global_sushi_cons.sushi_consumed_mutex);
    global_sushi_cons.quant++;
    pthread_mutex_unlock(&global_sushi_cons.sushi_consumed_mutex);
}

int globals_get_sushi_consumed() {
    return global_sushi_cons.quant;
}

virtual_clock_t* global_virtual_clock = NULL;
conveyor_belt_t* global_conveyor_belt = NULL;
queue_t* global_queue = NULL;

int global_produced = 0;
int global_consumed = 0;
int global_satisfied = 0;

//declaração de locks para incrementação ordenada das globais
pthread_mutex_t consumed_lock;
pthread_mutex_t satisfied_lock;

void globals_increment_satisfied() {
    pthread_mutex_lock(&satisfied_lock);
    global_satisfied++;
    pthread_mutex_unlock(&satisfied_lock);
}


int globals_get_produced() {
    return global_produced;
}

void globals_write_produced(int produced) {
    global_produced = produced;
}

int globals_get_consumed() {
    return global_consumed;
}

void globals_write_consumed(int consumed) {
    global_consumed = consumed;
}

int globals_get_satisfied() {
    return global_satisfied;
}

void globals_write_satisfied(int satisfied) {
    global_satisfied = satisfied;
}


void globals_set_virtual_clock(virtual_clock_t* virtual_clock) {
    global_virtual_clock = virtual_clock;
}

virtual_clock_t* globals_get_virtual_clock() {
    return global_virtual_clock;
}

void globals_set_conveyor_belt(conveyor_belt_t* conveyor_belt) {
    global_conveyor_belt = conveyor_belt;
}

conveyor_belt_t* globals_get_conveyor_belt() {
    return global_conveyor_belt;
}

void globals_set_queue(queue_t* queue) {
    global_queue = queue;
}

queue_t* globals_get_queue() {
    return global_queue;
}

/**
 * @brief Finaliza todas as variáveis globais.
 * Se criar alguma variável global que faça usoe 
 * de usar o free dentro dessa função.
 */
void globals_finalize() {
    conveyor_belt_finalize(global_conveyor_belt);
    virtual_clock_finalize(global_virtual_clock);
}

//   int dango = 0;
//   pthread_mutex_t dango_mutex;
//   int ramen;
//   pthread_mutex_t ramen_mutex;
//   int onigiri;
//   pthread_mutex_t onigiri_mutex;
//   int tofu;
//   pthread_mutex_t tofu_mutex;