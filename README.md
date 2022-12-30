# Philosophers

##The Dining Philosophers problem is a classic concurrency problem that illustrates the challenges of coordinating the actions of multiple threads or processes that share a common resource.

<img width="450" alt="image" src="https://user-images.githubusercontent.com/66947064/209930372-c8fec921-4502-4632-97ed-0ca6ec4bbad5.gif">


##Learning Outcomes:

1. Threads and Processes
2. Difference between Mutex and Semaphores
3. Building Multithreaded applications and designing distributed systems
4. Avoiding Deadlocks(So all don't eat at the same time)

![Deadlock_at_a_four-way-stop](https://user-images.githubusercontent.com/66947064/209935144-c60c9ba8-5876-4a3a-837d-6bb345647a4e.gif)

5. Race Conditions and Data Race

<img width="450" alt="image" src="https://user-images.githubusercontent.com/66947064/209933249-65fbaa48-da7c-41c3-addb-d9614ae496b1.png">

Live Coding Demonstration Example:

<img width="565" alt="image" src="https://user-images.githubusercontent.com/66947064/210025526-0570d3e3-7f1d-4618-9d79-3a6f5cf69cbb.png">
Output : 
Its different everytime.  This is not thread safe . Two threads are racing or who gets first.

<img width="730" alt="image" src="https://user-images.githubusercontent.com/66947064/210025562-4351d5c9-dc7c-4d43-8f90-94b8b95bf3b0.png">



<p>----------- Data Race ---------------</p>

<img width="450" alt="image" src="https://user-images.githubusercontent.com/66947064/209933187-3b843c61-ab69-42db-9afe-6a935e017779.png">


Detailed explanation: 
https://ckk.ai/datarace


6. Helgrind (Tool to check datarace)




6. Avoiding Resource starvation.












Sources:

1.https://ckk.ai/miro

2.https://en.wikipedia.org/wiki/Dining_philosophers_problem
3.
