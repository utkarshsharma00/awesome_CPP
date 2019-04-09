## Definition
1. A function which calls itself directly or indirectly is known as a Recursive Function.</br>
2. Recursion is a very powerful approach as it solves certain problems easily for example Depth First Search, Tower of Hanoi, Sudokus and Crosswords etc.</br>
3. In Recursion solution to a bigger problem is attained by thinking and expressing it in terms of a smaller problem and this smaller problem is tackled by the Base case.</br>
4. Base Case is where the Recursion ends. Without the base case (that is the base case is not defined or is not reached) the recurive function may lead to Stack Overflow.</br>
5. Stack Overflow is usually encountered more often in JAVA as compared to C++ because the size of stack in JAVA is less as compared to that of C++. This is primarily because of the fact that JAVA uses a virtual environment.</br>
## Approach to a Recursive Problem
There are 2 styles of approaching any Recursive problem. The first being the Reactive Approach and the second being the Proactive Approach.</br>
### 1. Reactive Approach</br>
In this approach we basically make Stupid calls that is we just call the function without putting even the slightest of thought to the solution of the problem and then we handle/recover from all of the problems in the base case. This type of approach usually has less amount of code. It is slower than the Proactive Approach.</br>
### 2. Proactive Approach</br>
In this approach we make Smart calls that is we put in our thoughts to solve the problem and the base case is a very straight forward one. This type of approach has a lot more lines of code. It is faster than the Reactive Approach.</br>


