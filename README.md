**# FINAL_PHILO**

**-> This project consists in solving the famous dining philosophers problem.**

We were allowed to use :  
memset  
printf  
malloc  
free   
write  
usleep  
gettimeofday  
pthread_create  
pthread_detach  
pthread_join  
pthread_mutex_init  
pthread_mutex_destroy  
pthread_mutex_lock  
pthread_mutex_unlock

**-> to run it :**  

$> make  
$> ./philo <number of philosophers> <time to eat (ms)> <time to sleep (ms)> <time to die (ms)> <minimum amount of diners (optional)>  

For example, with something like that :  
$> ./philo 4 399 200 200
a philosopher should die quickly due to starvation.

-> You can check for dataraces using the -fsanitize=thread flag in the compile compile command in the Makefile.  

-> Additionally, there is a site where you can enter the output to make sure all the philosophers are behaving as intended.  
https://nafuka11.github.io/philosophers-visualizer/
