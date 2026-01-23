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

<h2 style="text-align:center;background: #101080">PTHREAD_DETACH</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_detach(pthread_t th)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Place *th* dans l'etat detache. 
<br>free *th* a la fin de son execution.
<br>Cependant cela empeche les autres threads de se synchroniser sur la mort de *th* en utilisant pthread_join.

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

En cas de succes : **0**
<br>En cas d'erreur : **Code d'erreur non nul**

<h2 style="text-align:center;background: #101080">PTHREAD_MUTEX_DESTROY</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <pthread.h>

int pthread_mutex_destroy(pthread_mutex_t *mutex)

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

Detruit *mutex*, liberant les ressources qu'il detient. **Le mutex doit etre deverouille**

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

<h2 style="text-align:center;background: #be0000ff">BONUS_PART</h2>

<h2 style="text-align:center;background: #101080">KILL</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <sys/types.h><br>
#include <signal.h>

int kill(pid_t pid, int sig);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Envoie un signal à un processus**  

  >**pid \> 0** -> Signal envoye **au processus indique par *pid***
  
  >**pid == 0** -> Signal envoye a **tous les processus appartenant au meme groupe que le processus appelant.**
  
  >**pid == -1** -> Signal envoye a **tous les processus auquels le processus appelant a la permission d'envoyer des signaux** (sauf PID 1 (init))
  
  >**pid < -1 ->** Signal envoye a **tous les processus du groupe dont l'id est *-pid***
  
  >**sig == 0 ->** Aucun signal n'est envoye mais **les conditions d'erreurs** sont verifiees; utile pour **verifier l'existence** d'un id de processus ou de groupe de processus.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes (au moins 1 signal envoye) : **0**<br>
En cas d'echec : **-1** + **errno**

<h2 style="text-align:center;background: #101080">WAITPID</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <sys/wait.h>

pid_t waitpid(pid_t pid, int *status, int options); 

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Attend que le processus *pid* change d'etat.**

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **PID du fils** dont l'etat a change est renvoye ; si WHNOHANG etait specifie et qu'aucun fils specifie par *pid* n'a change d'etat, **0** est renvoye.<br>
En cas d'echec : **-1**

<h2 style="text-align:center;background: #be0000ff">SEMAPHORE</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #be0000ff; color: #be0000ff;">DESCRIPTION</h3>

sémaphore = mécanisme de **synchronisation** utilisé pour gérer l’accès à des ressources partagées entre **processus** (et éventuellement threads)

Un sémaphore repose sur un **compteur entier** représentant le nombre de ressources disponibles.

Un sémaphore peut être dans plusieurs états :
- Compteur > 0 : accès possible
- Compteur = 0 : accès bloqué (processus en attente)

Deux opérations atomiques :
- **P (wait)** : décrémente le compteur  
  → si le compteur devient négatif, le processus est **bloqué**
- **V (signal)** : incrémente le compteur  
  → réveille un processus en attente s’il y en a un

Contrairement au mutex :
- un sémaphore **n’a pas de notion de propriétaire**
- plusieurs processus peuvent accéder à la ressource simultanément (selon la valeur du compteur)

<h2 style="text-align:center;background: #101080">SEM_OPEN</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <fcntl.h>           /* Pour les constantes O_* */<br>
#include <sys/stat.h>        /* Pour les constantes « mode » */<br>
#include <semaphore.h>

sem_t *sem_open(const char *name, int oflag, mode_t mode, unsigned int value);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Initialiser et ouvrir un semaphore nomme.**<br> 
Le semaphore est identifie par *name*<br>
*oflag* -> **O_CREAT** | **O_EXCL**
*mode* -> Permissions a placer sur le nouveau semaphore.
*value* -> Valeur initiale du nouveau semaphore.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **Adresse du nouveau semaphore**
En cas d'echec : **SEM_FAILED** + **errno**

<h2 style="text-align:center;background: #101080">SEM_OPEN</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <semaphore.h>

int sem_close(sem_t *sem);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Ferme et libere le semaphore *sem*.**

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
En cas d'echec : **-1** + **errno**

<h2 style="text-align:center;background: #101080">SEM_POST</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <semaphore.h>

int sem_post(sem_t *sem);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Incremente (deverouille) le semaphore *sem*.**<br>
Si a la suite de cet increment, sem value > 0 : un autre processus/thread qui attend (*sem_wait*) sera reveille et procedera au verrouillage du semaphore

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
En cas d'echec : **-1** + **errno**

<h2 style="text-align:center;background: #101080">SEM_WAIT</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <semaphore.h>

int sem_wait(sem_t *sem);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Decremente (verouille) le semaphore *sem*.**<br>
Si sem value > 0 : La decrementation s'effecture et la fonction revient *immediatement*.<br>
si sem value = 0 : L'appel bloque jusqu'a ce qu'il devienne disponible pour effectuer la decrementation (sem value > 0). **Ou alors** un gestionnaire de signaux interromp l'appel (kill). 

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
En cas d'echec : **-1** + **errno**

<h2 style="text-align:center;background: #101080">SEM_UNLICK</h2>

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">PROTOTYPE</h3>

#include <semaphore.h>

int sem_unlink(const char *name);

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">DESCRIPTION</h3>

**Supprime un semaphore nomme.**<br>
Supprime le semaphore reference par *name*.<br>
Le nom est immediatement supprime mais le semaphore est detruit une fois que tous les autres processus qui l'avaient ouvert l'ont ferme.

<h3 style="padding: 0.5em 3em; background: #aaaaaaff; border: solid 2px #101080; color: #101080;">VALEUR RENVOYEE</h3>

En cas de succes : **0**
En cas d'echec : **-1** + **errno**