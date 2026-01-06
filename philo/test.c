/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttiprez <ttiprez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:14:48 by ttiprez           #+#    #+#             */
/*   Updated: 2026/01/06 16:53:24 by ttiprez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_THREADS 4
#define N_INCREMENTS 1000000

int counter = 0;
pthread_mutex_t mutex;

void *increment(void *arg)
{
    for (int i = 0; i < N_INCREMENTS; i++)
        counter++;   // pas protege
    return NULL;
}

void *increment_mutex(void *arg)
{
	pthread_mutex_lock(&mutex);
    for (int i = 0; i < N_INCREMENTS; i++)
        counter++;   // Protege
	pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(void)
{
    pthread_t threads[N_THREADS];

	// SANS MUTEX
	pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_create(&threads[i], NULL, increment, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
	printf("SANS MUTEX : \n");
    printf("Counter final = %d (attendu %d)\n",
           counter, N_THREADS * N_INCREMENTS);
	
	// AVEC MUTEX
	counter = 0;
	for (int i = 0; i < N_THREADS; i++)
        pthread_create(&threads[i], NULL, increment_mutex, NULL);
    for (int i = 0; i < N_THREADS; i++)
        pthread_join(threads[i], NULL);
	printf("\nVEC MUTEX : \n");
	printf("Counter final = %d (attendu %d)\n",
           counter, N_THREADS * N_INCREMENTS);
    return 0;
}

