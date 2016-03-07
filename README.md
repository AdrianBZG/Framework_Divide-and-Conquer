# Design and Analysis of Algorithms
# Assignment 2: Divide and Conquer
## By Adrián Rodríguez Bazaga
### Contact email: arodriba@ull.edu.es / alu0100826456@ull.edu.es

# Description

Framework to solve Divide and Conquer problems in an easy way, you just need to define the specific Problem characteristics and the Framework will solve it for you with a D&amp;C approach.
Algorithms included: MergeSort, Fibonacci, Strassen Matrix Multiplication. Also implemented a complexity study between MergeSort and BubbleSort algorithms.

# Dependencies

```sh
$ sudo apt-get install build-essential 
```
Uses *C++14*

# Build Status
![](http://i.imgur.com/7gvWrxI.png?1)

# How to compile?
Use make inside the /src/ directory. Compilation uses dynamic linking, so only classes that have changed will be compiled, the others will be linked using the object (.o) that's inside ./obj/ directory.
```sh
$ make clean
$ make
```


# How to execute?
The result of the compilation is placed inside /src/compiled folder, with the name DCframework, to execute it just use ./src/compiled/DCframework from the root directory

# Download source code

```sh
$ git clone https://github.com/AdrianBZG/Framework_Divide-and-Conquer.git
```

# Documentation

Take a look at the documentation by clicking [here](http://adrianbzg.github.io/Framework_Divide-and-Conquer/html/).

# Copyright and license

    Copyright 2016 - Adrián Rodríguez Bazaga

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
	
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.