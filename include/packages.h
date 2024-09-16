/* 
 * This file is part of alaman (https://github.com/strokegmd/alaman).
 * Copyright (C) 2024  strokegmd.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __PACKAGES_H
#define __PACKAGES_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#include "curlutil.h"
#include "strutil.h"
#include "constants.h"

/**
 * Retrieves package data from name.
 *
 * @param package The package to retrieve data for.
 * @return A 3D array containing the package URLs and versions.
 */
char ***get_package_data(const char *package);

/**
 * Installs a package using pacman.
 *
 * @param package The package to install.
 */
void install_package(const char *package);

#endif
