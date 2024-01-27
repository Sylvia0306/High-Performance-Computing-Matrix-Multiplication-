# High-Performance-Computing-Matrix-Multiplication-

To test a single function, you can use:
gcc main.c -o main
./main {function name} {n} {pad} (run on header node for debugging) (for
example ./main dgemm0 1024 1)
srun main {function name} {n} {pad} (run on compute nodes)
{function name} is the name of the matrix multiplication function you want to
test.
{n} is the length of the matrix. For example n=2048 means you want the matrix
size to be 2048^2
.
{pad} is the length of padding. You can use proper padding to avoid corner
cases if necessary. For example n=2048 and pad=30 means n=2070.

To run multiple tests at the same time, you can use starter.py. Some of the
padding in starter.py are set as 1, and you may want to change them.

We use main.c to measure the running time and performance. You can modify
your main.c, but this file will be in its original version when grading.

We use hpc-001 to test your performance when grading. You can test and
debug your code on other computers, but make sure to check them before
submission on hpc-001.
