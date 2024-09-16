# This file is part of alaman (https://github.com/strokegmd/alaman).
# Copyright (C) 2024  strokegmd.
# 
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CC=gcc
CFLAGS=-c -Wall -Wextra
LFLAGS=-lcurl

all: bin/alaman

bin/alaman: bin/main.o bin/curlutil.o bin/strutil.o bin/packages.o
	$(CC) $(LFLAGS) -o bin/alaman $^

bin/%.o: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@

bin/%.o: src/util/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@

install: bin/alaman
	cp bin/alaman /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/alaman

clean:
	rm -f bin/*.o bin/alaman