# 42_project_philosophers
personal implementation of the dining philosophers problem using C laguage.
## What does this project do?
this project will teach you the basics of multithreading/multiprocessing. You will discover mutexes/semaphores to solve the problem.
## The rules
_ One or more philosophers sit at a round table.</br>
there is a large bowl of spaghetti in the middle of the table</br>
_ The philosophers alternatively **eat**, **think**, or **Sleep**. </br>
_ There are as many forks as philosophers on the table.</br>
_ A philosopher takes their right and their left forks to eat, one in each hand.</br>
_ When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again.
The simulation stops when a philosopher dies of starvation.</br>
_ Philosophers don't speak with each other and don't know if another philosopher is about to die. </br>
_ Philosophers should avoid dying.</br>
## why is the dining philosophers problem important ? 
In computer science, the dining philosophers problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them. and it's always useful to dive in the ```multithreading/multiprocessing``` concept and also think about solutions to avoid and solve deadlocks and data race. </br>
## Usage
_ clone the repo, execute ```make``` in one of the directories ```./philo``` or ```./philo_bonus``` command and a program named philo should be created after this. </br>
_ the main difference between the two directories is : ```./philo``` was solved only using threads and mutexes. however the ```./philo_bonus``` was solved using processes to represent each philosopher and also threads to track philos, with semaphores to control access to shared ressources. </br>
_ But in both cases the program takes the following arguments :
 ```number_of_philosophers``` ``` time_to_die``` ```time_to_eat``` ```time_to_sleep``` ```[number_of_times_each_philosopher_must_eat]```</br>
 &emsp; **[number_of_times_each_philosopher_must_eat]** : the last argument is an optional one, if all philosophers have eaten at least **number_of_times_each_philosopher_must_eat** times, the simulation stops. if not specified, the simulation stops when a philosopher dies.</br>
 
# Ressources
_ https://towardsdatascience.com/multithreading-and-multiprocessing-in-10-minutes-20d9b3c6a867 </br>
_ https://www.tutorialspoint.com/difference-between-process-and-thread#:~:text=an%20active%20program.-,A%20thread%20is%20a%20lightweight%20process%20that,managed%20independently%20by%20a%20scheduler.&text=Processes%20require%20more%20time%20for,they%20are%20lighter%20than%20processes.&text=Processes%20are%20totally%20independent%20and%20don't%20share%20memory. </br>
_ https://www.quora.com/How-Semaphore-variable-is-different-from-ordinary-variable </br>
_ https://docs.oracle.com/cd/E19253-01/816-5137/sync-39/index.html#:~:text=Unnamed%20semaphores%20are%20either%20private,rather%20than%20a%20pshared%20value. </br>
_ https://stackoverflow.com/questions/3130079/difference-between-racearound-condition-and-deadlock/3130212#3130212 </br>
_ https://lass.cs.umass.edu/~shenoy/courses/fall15/lectures/Lec09.pdf </br>
_ https://www.geeksforgeeks.org/difference-between-binary-semaphore-and-mutex/ </br>
_ https://stackoverflow.com/questions/806499/threading-vs-parallelism-how-do-they-differ#:~:text=Threading%20is%20usually%20referred%20to,same%20time%20on%20multiple%20CPU's. </br>
_ http://www.embeddedlinux.org.cn/rtconforembsys/5107final/LiB0037.html#:~:text=Ownership%20of%20a%20mutex%20is,lock%20or%20unlock%20that%20mutex. </br>
