# OperatingSystemPracticalExam
Two questions from set 3 (from operating system) implemented using c++

# Question 1 -> Round Robin Scheduling Algorithm
1. It is preemptive in nature and easy to implement.
2. Each process is given a time quanta to execute after which it is moved from Running to Ready State.
3. The above phenomena is known as Context Switching.
4. The terminonoly used is: 
a) Completion Time: Time at which process completes its execution
b) Turn Around Time: Time Difference between completion time and arrival time.
c) Waiting Time: Time Difference between turn around time and burst time.
5. The program has been implemented by creating a class Round Robin in C++
6. Here, the time quanta is specified as 3 and the burst times used are 21, 13, 6, 12. 
7. There are 4 processes and the average waiting time and turn around time is computed.

# Question 2 -> Fork()
1. The fork function is system call in most Unix-based operating systems
2. The function creates two new process, namely the parent and the child
3. Child is the duplicate of the original calling program
4. It is an application of multiprocessing
5. According to the question, both parent and the child run the same code and the parent executes first.
