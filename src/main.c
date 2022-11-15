#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "args.h"
#include "customer.h"
#include "sushi_chef.h"
#include "hostess.h"
#include "globals.h"


int main(int argc, char** argv) {
    /* Read command line options */
    config_t config = parse(argc, argv);

    /* Setup random seed */
    srand(time(0));

    /* Setup simulation virtual clock */
    globals_set_virtual_clock(virtual_clock_init(&config));

    /* Setup sushi conveyor belt */
    globals_set_conveyor_belt(conveyor_belt_init(&config));

    /* Init consumed food mutexes */
    init_mutex_();

    /* Init the Sushi Chef */
    sushi_chef_t* sushi_chef = sushi_chef_init();

    /* Setup customer queue */
    globals_set_queue(queue_init());

    /* Init the Hostess */
    hostess_t* hostess = hostess_init();

    /* Join threads and free used memory */

    /* Espera hostess finalizar */
    hostess_finalize(hostess);

    /* Espera chef finalizar */
    sushi_chef_finalize(sushi_chef);

    conveyor_belt_t* conveyor = globals_get_conveyor_belt();

    fprintf(stdout, GREEN "[INFO]" NO_COLOR " Conferindo se ainda restam clientes sentados...\n");

    /* Confere se ainda restam cliente na esteira */
    while (TRUE) {
        for (int i = 0; i < conveyor->_size; i++) {
            if (conveyor->_seats[i] != -1) {
                break;
            }
        }
        break;
    }
    fprintf(stdout, GREEN "[INFO]" NO_COLOR " Todos os clientes foram embora!\n");

    /* destroy consumed food mutexes */
    destroy_mutex_();

    /* Encerrando Esteira e Relogio */
    globals_finalize();
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Restaurante encerrado.\n");


    /* Imprimindo resultados */
    printf("\n ************** RESULTADOS: ************** \n");
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Clientes satisfeitos: %d.\n", globals_get_satisfied());
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Sushi consumida: %d.\n", globals_get_sushi_consumed());
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Dango consumida: %d.\n", globals_get_dango_consumed());
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Ramen consumida: %d.\n", globals_get_ramen_consumed());
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Onigiri consumida: %d.\n", globals_get_onigiri_consumed());
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Tofu consumida: %d.\n", globals_get_tofu_consumed());
    printf("\n");
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Sushi preparada: %d.\n", globals_get_food_prepared(0));
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Dango preparada: %d.\n", globals_get_food_prepared(1));
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Ramen preparada: %d.\n", globals_get_food_prepared(2));
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Onigiri preparada: %d.\n", globals_get_food_prepared(3));
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Quantidade de Tofu preparada: %d.\n", globals_get_food_prepared(4));
    printf("******************************************* \n");

    return EXIT_SUCCESS;
}
