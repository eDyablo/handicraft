**Build**

To build executable by means of GNU C++ compiler run the following command.
```
g++ -std=c++14 src/main.cpp -o calc
```
Or use build.sh script from the repository
```
./build.sh
```
**Usage**

All the command line arguments passed are treated as expressions. Each expression gets evaluated separately. Results are separated by whitespaces. See examples bellow.

```
calc '1 + 2'
```
output: `3`

```
calc '1 + 2' '3 - 4'
```
output: `3 -1`

```
calc '1 + 2 - (8 - 4) / 2'
```
output: `1`
