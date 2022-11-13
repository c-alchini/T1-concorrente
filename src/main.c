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

    /* Init the Sushi Chef */
    sushi_chef_t* sushi_chef = sushi_chef_init();

    /* Setup customer queue */
    globals_set_queue(queue_init());

    /* Init the Hostess */
    hostess_t* hostess = hostess_init();

    /* Join threads and free used memory */
    // Espera hostess finalizar
    hostess_finalize(hostess);

    // Espera chef finalizar
    sushi_chef_finalize(sushi_chef);

    // Confere se ainda restam cliente na esteira
    conveyor_belt_t* conveyor = globals_get_conveyor_belt();

    fprintf(stdout, GREEN "[INFO]" NO_COLOR " Conferindo se ainda restam clientes sentados...\n");

    while (TRUE) {
        for (int i = 0; i < conveyor->_size; i++) {
            if (conveyor->_seats[i] != -1) {
                break;
            }
        }
        break;
    }
    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Todos os clientes foram embora!\n");

    // Encerrando Esteira e Relogio
    globals_finalize();

    fprintf(stdout, BLUE "[INFO]" NO_COLOR " Restaurante encerrado.\n");

    return EXIT_SUCCESS;
}
