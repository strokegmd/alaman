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

#ifndef __STRUTIL_H
#define __STRUTIL_H

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "constants.h"

/**
 * Compares two strings for both content and length equality.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return True if the strings are equal in content and length, false otherwise.
 */
bool cstrcmp(const char *s1, const char *s2);

/**
 * Counts the number of strings in an array.
 *
 * @param arr The array of strings to count.
 * @return The number of strings in the array.
 */
size_t strcnt(char** arr);

/**
 * Checks if a string is contained in an array of strings.
 *
 * @param arr The array of strings to search.
 * @param str The string to search for.
 * @return True if the string is found in the array, false otherwise.
 */
bool arrcon(char **arr, char *str);

/**
 * Splits a string into an array of substrings based on a delimiter.
 *
 * @param string The string to split.
 * @param delim The delimiter to split on.
 * @return An array of substrings.
 */
char** strspl(const char* string, const char* delim);

/**
 * Checks if a string consists only of digits (except for the last character).
 *
 * @param str The string to check.
 * @return True if the string consists only of digits (except for the last character), false otherwise.
 */
bool strdig(const char* str);

#endif
