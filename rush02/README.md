
# Rush 02

A command-line program that converts numeric values into their written form using a configurable dictionary.

## Overview  
`rush-02` takes a numeric input and prints its corresponding value in words.  
It ships with a default number dictionary, and optionally allows you to supply a custom dictionary at runtime.

The program supports numbers of any length, as long as the dictionary provides the necessary entries.

## Features
- Convert any valid positive integer to its written text representation.
- Support for custom dictionaries provided at runtime.
- Robust dictionary parsing with whitespace trimming and error detection.
- Guaranteed memory safety: all allocated memory is freed.
- Flexible dictionary structure:
  - Values can be modified.
  - Additional entries can be added.
  - Initial reference keys must remain present.
  - Dictionary entries may appear in any order and may include empty lines.

## Build Instructions

```bash
make fclean
make
```

This generates the executable:

```
rush-02
```

## Usage

### One Argument  
Convert a number using the default dictionary:

```bash
./rush-02 <number>
```

### Two Arguments  
Use a custom dictionary instead of the default:

```bash
./rush-02 <dictionary_file> <number>
```

### Rules  
- The input must be a **valid positive integer**.  
  If invalid, the program outputs:
  ```
  Error
  ```

- If the dictionary is malformed or insufficient to resolve the number, the program outputs:
  ```
  Dict Error
  ```

- Dictionary line format:
  ```
  <number><spaces> : <spaces><printable characters>
  ```

## Examples

```bash
$ ./rush-02 42 | cat -e
forty two$

$ ./rush-02 0 | cat -e
zero$

$ ./rush-02 10.4 | cat -e
Error$

$ ./rush-02 100000 | cat -e
one hundred thousand$

$ grep "20" numbers.dict | cat -e
20$
:$ 
hey$
everybody !$

$ ./rush-02 20 | cat -e
hey everybody !$
```

## Dictionary Behavior  
- Initial reference keys must exist; their values may be modified.  
- Extra custom entries may be added.  
- Only initial dictionary entries are required for conversion.  
- Spaces around keys and values are ignored.  
- Empty lines are allowed.
