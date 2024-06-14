# CPLEX/C++ docker compose container

- CPLEX docker image is required [cplex-docker](https://github.com/natalialidia/cplex-docker)!

- This example uses a C++ Concert/CPLEX implementation of a LP problem.

- Steps to create and execute your own model:

  1. Run the container (edit the docker-compose.yml cplex image version if needed):
    ```
    docker compose run cplex
    ```
  2. Create your cpp program in the same folder of the Makefile and docker-compose.yml
  3. Edit the Makefile, replacing the "lpmodel" with the name of your cpp program
  4. Compile and execute your program in the container bash:
    ```
    make execute
    ```
  5. (Optional) Remove all those files produced by the compile (but not necessary recompile if you need to)
    ```
    make clean
    ```

- To execute de lpmodel.cpp example, just run the container (as in step 1) and use the `make execute` command in the container bash.