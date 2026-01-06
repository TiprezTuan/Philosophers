<h1 style="text-align:center">Fonctions</h1>

<h2 style="text-align:center;background: #101080">MEMSET</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

void memset (void s, int c, size_t n)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Remplit les **n** premiers octets de **s** par **c**

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

Renvoie un **pointeur sur s**

<h2 style="text-align:center;background: #101080">USLEEP</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <unistd.h>

int usleep(useconds_t usec)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Suspend pendant **usec** microsecondes.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
<br>En cas d'erreur : **1**

<h2 style="text-align:center;background: #101080">GETTIMEOFDAY</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <sys/times.h>

int gettimeofday(struct timeval *tv, struct timezone *tz)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Donne le nombre de **secondes** et **microsecondes** ecoulees depuis 1er janvier 1970.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
<br>En cas d'erreur : **1**

<h2 style="text-align:center;background: #101080">PTHREAD_CREATE</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_create(pthread_t * thread, pthread_attr_t * attr, void * (*start_routine)(void *), void * arg)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Creer un thread s'executant **simulatenement** avec le thread appelant. Le nouveau thread execute la fonction en parametre *start_routine* en lui passant *arg* comme premier argument. 
<br> Le nouveau thread s'arrete en appelant **pthread_exit** ou lorsque *start_routine* est fini.
<br> *attr* indique les attributs du nouveau thread. Peut etre **NULL**

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : l'ID du nouveau thread est stocke a l'emplacement memoire pointe par *thread* et **0** est renvoye.
<br>En cas d'erreur : **Code d'erreur non nul**

<h2 style="text-align:center;background: #101080">PTHREAD_JOIN</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_join(pthread_t th, void **thread_return)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Suspend l'execution du thread appelant jusqu'a ce que th finisse son execution.
<br>Si un thread est annule alors qu'il est suspendu par **pthread_join()**, l'execution du thread reprend immediatement et l'annulation est realise sans attendre la fin du thread *th*.
<br>Si l'annulation du thread intervient durant **pthread_join()**, le thread th demeure non join.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : Le code de retour de *th* est stocke dans *thread_return* et **0** est renvoye.
<br>En cas d'erreur : **Code d'erreur non nul**

<h2 style="text-align:center;background: #be0000ff">MUTEX</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #be0000ff; color: #be0000ff;">DESCRIPTION</h3>

mutex = **MUT**ual **EX**ec -> Pratique pour proteger des donnees des **data races** et pour implementer des **sections critiques**

Un mutex peut etre dans **deux etats** :
- Déverrouillé (pris par aucun thread)
- Verrouillé (Appartenant a un thread)

Un mutex ne peut etre pris que par **un seul thread** a la fois.
<br>Un thread qui tente de verouiller un mutex deja verouiller est **suspendu** jusqu'a ce que le mutex soit déverouillé.

<h2 style="text-align:center;background: #101080">PTHREAD_MUTEX_INIT</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Initialisation *mutex* selon les attributs spécifié par *mutexattr*. Si *mutexattr* vaut NULL, les parametres par défaut sont utilisés.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

**Toujours 0**

<h2 style="text-align:center;background: #101080">PTHREAD_MUTEX_DESTROY</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_mutex_destroy(pthread_mutex_t *mutex)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Detruit *mutex*, liberant les ressources qu'il detient. **Le mutex doit etre deverouille**
<br>**INUTILE** si ce n'est de verifier que le mutex n'est pas verrouille car dans l'implementation de LinuxThreads des threads POSIX, aucune ressource ne peut etre associe a un mutex.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
<br>En cas d'erreur : **Code d'erreur non nul**

<h2 style="text-align:center;background: #101080">PTHREAD_MUTEX_LOCK</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_mutex_lock(pthread_mutex_t *mutex)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Verrouille *mutex*. Si le mutex est **deverrouille**, il devient **verrouille** et est possede par le **thread appelant** et **pthread_mutex_lock()** rend la main **immediatement**.
<br>Si le mutex est deja verrouille par un autre thread, **pthread_mutex_lock()** suspend le thread appelant jusqu'a ce que le mutex soit deverouille.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
<br>En cas d'erreur : **Code d'erreur non nul**


<h2 style="text-align:center;background: #101080">PTHREAD_MUTEX_UNLOCK</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_mutex_unlock(pthread_mutex_t *mutex)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Deverrouille *mutex*. Celui-ci est **suppose verrouille** (Sinon undefined behavior), et ce par le **meme thread** qui l'a verrouille.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
<br>En cas d'erreur : **Code d'erreur non nul**