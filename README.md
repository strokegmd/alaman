# alaman
Arch Linux Archive Manager
# Building
From sources (all binaries will be in `bin` directory):
```
$ git clone --depth 1 https://github.com/strokegmd/alaman.git
$ cd alaman
$ make
```
You can install `alaman` using this:
```
$ make install
```
And uninstall using this:
```
$ make uninstall
```
To clear `bin` directory, you can use this:
```
$ make clean
```
That's all.
# Using
Installing package:
```
$ alaman -S neofetch
:: There are 3 versions available for neofetch:
   1) 6.1.0  2) 7.0.0  3) 7.1.0

Enter a number (default=3): 
```
Displaying version:
```
$ alaman --version
Alaman v1.0.00-test
```
Displaying help message:
```
$ alaman -h / alaman --help
alaman -h/--help
alaman --version
alaman -S <packages>
```
Also, if there no such command, `alaman` will execute command as `pacman`.
