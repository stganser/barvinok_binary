# Barvinok Binary for Polyite

## Description

A binary that can be called by Polyite to use Barvinok's counting algorithm.

This program is part of project Polyite, which is released under the MIT license. It depends on libbarvinok, version 0.39, which is GPL licensed.

## Installation

To get libbarvinok, run

```bash
git clone http://repo.or.cz/barvinok.git
git checkout barvinok-0.39
```

and follow the build instructions.

To build the binary, run
```bash
clang -std=c99 -I <path to libbarvinok installation directory>/include/ -L <path to libbarvinok installation directory>/lib/ -lbarvinok -lisl count_integer_points.c -o count_integer_points
```

(C) 2017 Stefan Ganser
