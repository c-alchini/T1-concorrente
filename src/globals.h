#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <pthread.h>
#include "conveyor_belt.h"
#include "virtual_clock.h"
#include "queue.h"
#include "menu.h"


/* Codigo para soma de comidas preparadas */
/**
 * @brief Estrutura encapsulando a quantidade de comidas preparadas.
*/
struct food_prepared {
  int sushi;
  int dango;
  int ramen;
  int onigiri;
  int tofu;
};

/**
 * @brief Incrementa a quantidade de uma determinada comida preparada
 *
 * @param menu_item
 */
extern void globals_increment_food_prepared(enum menu_item food);

/**
 * @brief Retorna a quantidade de uma determinada comida preparada
 *
 * @return int
 */
extern int globals_get_food_prepared(enum menu_item food);

/* Fim do codigo para soma de comidas preparadas */



/**
 * @brief Estrutura encapsulando a quantidade de sushi consumido.
*/
struct sushi_consumed {
  int quant;
  pthread_mutex_t sushi_consumed_mutex;
};

/**
 * @brief Incrementa a quantidade de sushis consumidos (de modo global)
 */
extern void globals_increment_sushi_consumed();

/**
 * @brief Retorna a quantidade de sushi consumido
 *
 * @return int
 */
extern int globals_get_sushi_consumed();

/**
 * @brief Incrementa a quantidade de clientes satisfeitos
 */
extern void globals_increment_satisfied();



// estas funcoes ja estao declaradas no codigo do ruan
extern int globals_get_satisfied();
extern void globals_write_satisfied(int satisfied);


// funcoes originais
/**
 * @brief Inicia um relógio virtual (de modo global)
 *
 * @param virtual_clock
 */
extern void globals_set_virtual_clock(virtual_clock_t* virtual_clock);

/**
 * @brief Retorna um relógio virtual (de modo global)
 *
 * @return virtual_clock_t*
 */
extern virtual_clock_t* globals_get_virtual_clock();

/**
 * @brief Inicia uma esteira de sushi (de modo global).
 *
 * @param conveyor_belt
 */
extern void globals_set_conveyor_belt(conveyor_belt_t* conveyor_belt);

/**
 * @brief Retorna uma esteira de sushi (de modo global)
 *
 * @return conveyor_belt_t*
 */
extern conveyor_belt_t* globals_get_conveyor_belt();

/**
 * @brief Inicia uma fila (de modo global)
 *
 * @param queue
 */
extern void globals_set_queue(queue_t* queue);

/**
 * @brief Retorna uma fila (de modo global)
 *
 * @return queue_t*
 */
extern queue_t* globals_get_queue();

/**
 * @brief Finaliza todas as variáveis globais.
 *
 */
extern void globals_finalize();

#endif  // __GLOBALS_H__
