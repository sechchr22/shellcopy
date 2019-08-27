# shellcopy
- _getenv.c - Función con la cual extraemos la variable de ambiente que necesitamos, en este caso PATH
- _getline.c - nuestro getline
- hsh_v0.c - main de nuestra shell
- myshell_execute.c - función donde se ejecutan builtin o ejecutables dependiendo de lo que requiera el usuario
- read_command.c - función que lee y guarda lo que el usuario ingresa por teclado al prompt
- shellheader.h - nuestro header file
- split_into_arguments.c - función que tokeniza (divide) en argumentos lo que el usuario ingresó por teclado
- split_path.c - funcion que tokeniza (divide) la variable de ambiente PATH en los diferentes directorios
