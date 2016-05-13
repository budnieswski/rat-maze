Rat Maze
===================



Objective
-------------

The objective is to use a technique known as backtracking (or reverse), often used in Artificial Intelligence to solve problems through trial and error. This technique is useful in situations where, at every moment, we have several possible options and do not know to evaluate the best. So we choose one of them and, if this choice does not lead to solving the problem, fall back and make a new choice.

> **Rules:**

> - Declare a vector (30x30 ) to represent the maze. 
> - Matrix positions can store one of the following brands: free wall visited or alley (you can set the marks as a whole constant). Initially, all position is marked as free or wall, and only free positions can be reached .When the mouse a free position is reached, your brand is changed to visited and when it is determined that a visited position leads to an alley, your brand is changed to end.
> - To set the internal configuration of the array, you must use the random function.
> - To facilitate the visualization of the search process of the maze exit, to display the matrix video, the positions must be marked:
>  * Free: will be represented by a blank space;
>  * wall: is represented by a solid block (ASCII 219);
>  * visited: will be represented by a point;
>  * alley: is represented by a dotted block (ASCII 176);
>  * position in which the mouse is in the maze at the moment in which it appears: will be represented by character - ASCII 1 (happy face)
> - To find the way out of the maze, apply the following algorithm:
>  * Set (i, j) as current mouse position, which initially is (2,2);
>  * Start an empty P stack;
>  * Until the current position (i, j) becomes the output position (n-1, n):
>   * * Mark the current position (i, j) as visited;
>   * * If there is an open position adjacent the current position, piled the current position and we move the mouse to this free position;
>   * * If not, we are in an alley and we need to go back to the last position by which we have to explore other way. For this desempilhamos
a position of P, which becomes the new current position. If the battery is empty, the labyrinth has no outlet and the search fails.
>  * * After reaching the starting position the search ends with success.
> - To facilitate manipulation of the stack, a stack of integers should be applied. Therefore, the pair of coordinates to be transformed (i, j) to a corresponding integer (i * 100 + j). For example, the pair of coordinates (13,12) is stacked as 13 * 100 + 12 which is equal to 1312. When unstacking this number, we can restore the original pair of coordinates, making **i = 1312 div 100** the result is 13 and **j = 1312 mod 100** whose result is 12. This device works properly only when each coordinate has at most two digits.
