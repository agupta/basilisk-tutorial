# basilisk-tutorial

Solves Saint-Venant equations with initial conditions of a Gaussian bump.

```shell
$ qcc -Ofast -Wall bump.c -o bump.out -lm
$ ./bump.out > out.ppm 2> .log
```
