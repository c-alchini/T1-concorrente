#include <stdlib.h>

#include "globals.h"

/*
    VOCÊ DEVE CRIAR VARIÁVEIS GLOBAIS PARA ARMAZENAR DADOS SOBRE A SIMULAÇÃO.
    NOTAS:
    1.  OS SEGUINTES DADOS DEVEM SER ARMAZENADOS E PRINTADOS AO FIM DA SIMULAÇÃO:
        a. Quantidade de clientes que sentaram-se no conveyor e consumiram todos os itens desejados
        b. Quantidades produzidas de cada alimento
        c. Quantidades consumidas de cada alimento
    2.  SIGA OS EXEMPLOS DE VARIÁVEIS GLOBAIS JÁ EXISTENTES NESSE ARQUIVO PARA CRIAR AS NOVAS.
*/

// Comidas Preparadas==========================================
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
// Comidas Preparadas==========================================



//SUSHI*******************************************************
struct sushi_consumed global_sushi_cons = { 0 };

void globals_increment_sushi_consumed() {
    pthread_mutex_lock(&global_sushi_cons.sushi_consumed_mutex);
    global_sushi_cons.quant++;
    pthread_mutex_unlock(&global_sushi_cons.sushi_consumed_mutex);
}

int globals_get_sushi_consumed() {
    return global_sushi_cons.quant;
}
//SUSHI*******************************************************


//DANGO*******************************************************
struct dango_consumed global_dango_cons = { 0 };

void globals_increment_dango_consumed() {
    pthread_mutex_lock(&global_dango_cons.dango_consumed_mutex);
    global_dango_cons.quant++;
    pthread_mutex_unlock(&global_dango_cons.dango_consumed_mutex);
}

int globals_get_dango_consumed() {
    return global_dango_cons.quant;
}
//DANGO*******************************************************


//RAMEN*******************************************************

struct ramen_consumed global_ramen_cons = { 0 };

void globals_increment_ramen_consumed() {
    pthread_mutex_lock(&global_ramen_cons.ramen_consumed_mutex);
    global_ramen_cons.quant++;
    pthread_mutex_unlock(&global_ramen_cons.ramen_consumed_mutex);
}

int globals_get_ramen_consumed() {
    return global_ramen_cons.quant;
}
//RAMEN*******************************************************

//ONIGIRI*******************************************************
struct onigiri_consumed global_onigiri_cons = { 0 };

void globals_increment_onigiri_consumed() {
    pthread_mutex_lock(&global_onigiri_cons.onigiri_consumed_mutex);
    global_onigiri_cons.quant++;
    pthread_mutex_unlock(&global_onigiri_cons.onigiri_consumed_mutex);
}

int globals_get_onigiri_consumed() {
    return global_onigiri_cons.quant;
}
//ONIGIRI*******************************************************

//TOFU*******************************************************

struct tofu_consumed global_tofu_cons = { 0 };

void globals_increment_tofu_consumed() {
    pthread_mutex_lock(&global_tofu_cons.tofu_consumed_mutex);
    global_tofu_cons.quant++;
    pthread_mutex_unlock(&global_tofu_cons.tofu_consumed_mutex);
}

int globals_get_tofu_consumed() {
    return global_tofu_cons.quant;
}
//TOFU*******************************************************


// Satisfied Clients=========================================
pthread_mutex_t satisfied_lock;
int global_satisfied = 0;

void globals_increment_satisfied() {
    pthread_mutex_lock(&satisfied_lock);
    global_satisfied++;
    pthread_mutex_unlock(&satisfied_lock);
}

int globals_get_satisfied() {
    return global_satisfied;
}
// Satisfied Clients=========================================


// Globais originais
virtual_clock_t* global_virtual_clock = NULL;
conveyor_belt_t* global_conveyor_belt = NULL;
queue_t* global_queue = NULL;

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
 * @brief Inicializa os mutexes usados.
 */
void init_mutex_() {
    pthread_mutex_init(&satisfied_lock, NULL);
    pthread_mutex_init(&global_sushi_cons.sushi_consumed_mutex, NULL);
    pthread_mutex_init(&global_dango_cons.dango_consumed_mutex, NULL);
    pthread_mutex_init(&global_ramen_cons.ramen_consumed_mutex, NULL);
    pthread_mutex_init(&global_onigiri_cons.onigiri_consumed_mutex, NULL);
    pthread_mutex_init(&global_tofu_cons.tofu_consumed_mutex, NULL);
}

/**
 * @brief Destrói os mutexes usados.
 */
void destroy_mutex_() {
    pthread_mutex_destroy(&satisfied_lock);
    pthread_mutex_destroy(&global_sushi_cons.sushi_consumed_mutex);
    pthread_mutex_destroy(&global_dango_cons.dango_consumed_mutex);
    pthread_mutex_destroy(&global_ramen_cons.ramen_consumed_mutex);
    pthread_mutex_destroy(&global_onigiri_cons.onigiri_consumed_mutex);
    pthread_mutex_destroy(&global_tofu_cons.tofu_consumed_mutex);
}

/**
 * @brief Finaliza todas as variáveis globais.
 * Se criar alguma variável global que façae 
 * de usar o free dentro dessa função.
 */
void globals_finalize() {
    conveyor_belt_finalize(global_conveyor_belt);
    virtual_clock_finalize(global_virtual_clock);
}