# Quadchecker

`quadchecker` is a program that takes a string as input and determines which quad pattern(s) it matches. It then displays the name of each matching quad along with its dimensions.

There are **two implementations** of this project, the `C` and the `Go` versions that are in `rush02` and `quadchecker` directories respectively.

### Behavior

The program accepts a single string argument, if the string corresponds to one or more known quad patterns, the program outputs:
```
[quad_name] [width] [height]
```

If multiple quad patterns match, they must be:

- Listed alphabetically
- Separated with `||`

If the string does not match any quad pattern, the program prints:
```
Not a quad function
```
