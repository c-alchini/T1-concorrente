#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#include <pthread.h>
#include "conveyor_belt.h"
#include "virtual_clock.h"
#include "queue.h"
#include "menu.h"


/* Soma comidas preparadas */
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

/* Soma de comidas preparadas */



//SUSHI****************************************************************************
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
//SUSHI****************************************************************************



//DANGO============================================================================
/**
 * @brief Estrutura encapsulando a quantidade de dango consumido.
*/
struct dango_consumed {
  int quant;
  pthread_mutex_t dango_consumed_mutex;
};

/**
 * @brief Incrementa a quantidade de dangos consumidos (de modo global)
 */
extern void globals_increment_dango_consumed();

/**
 * @brief Retorna a quantidade de dango consumido
 *
 * @return int
 */
extern int globals_get_dango_consumed();
//DANGO============================================================================



//RAMEN****************************************************************************
/**
 * @brief Estrutura encapsulando a quantidade de ramen consumido.
*/
struct ramen_consumed {
  int quant;
  pthread_mutex_t ramen_consumed_mutex;
};

/**
 * @brief Incrementa a quantidade de ramens consumidos (de modo global)
 */
extern void globals_increment_ramen_consumed();

/**
 * @brief Retorna a quantidade de ramen consumido
 *
 * @return int
 */
extern int globals_get_ramen_consumed();
//RAMEN****************************************************************************



//ONIGIRI============================================================================
/**
 * @brief Estrutura encapsulando a quantidade de onigiri consumido.
*/
struct onigiri_consumed {
  int quant;
  pthread_mutex_t onigiri_consumed_mutex;
};

/**
 * @brief Incrementa a quantidade de onigiri consumidos (de modo global)
 */
extern void globals_increment_onigiri_consumed();

/**
 * @brief Retorna a quantidade de onigiri consumido
 *
 * @return int
 */
extern int globals_get_onigiri_consumed();
//ONIGIRI============================================================================



//TOFU****************************************************************************
/**
 * @brief Estrutura encapsulando a quantidade de tofu consumido.
*/
struct tofu_consumed {
  int quant;
  pthread_mutex_t tofu_consumed_mutex;
};

/**
 * @brief Incrementa a quantidade de sushis consumidos (de modo global)
 */
extern void globals_increment_tofu_consumed();

/**
 * @brief Retorna a quantidade de tofu consumido
 *
 * @return int
 */
extern int globals_get_tofu_consumed();
//TOFU****************************************************************************



/**
 * @brief Incrementa a quantidade de clientes satisfeitos
 */
extern void globals_increment_satisfied();

/**
 * @brief Retorna satisfied
 *
 * @return int
 */
extern int globals_get_satisfied();

/**
 * @brief Inicializa mutexes das globais
 *
 */
extern void init_mutex_();

/**
 * @brief Finaliza mutexes das globais
 *
 */
extern void destroy_mutex_();


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
