# Exec Gen

This directory contains the quads to be checked: it is not necesary untill you want to generate your executables.

# Generate execs

In `main.go` file, change the name, `QuadD` to the name of the quad function from `quadF` directory that you want to make an exec of. 
after: for example if you changed it to `QuadE`

you would run the following command:

```
go build -o quadE main.go
```
