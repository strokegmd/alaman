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

#include "../../include/strutil.h"

bool cstrcmp(const char *s1, const char *s2)
{
    return !strcmp(s1, s2) && strlen(s1) == strlen(s2);
}

size_t strcnt(char** arr) 
{
    size_t count = 0;
    while (*arr != NULL) 
    {
        count++;
        arr++;
    }
    return count;
}

bool arrcon(char **arr, char *str)
{
    for (size_t i = 0; i < strcnt(arr); i++)
    {
        if (cstrcmp(arr[i], str)) 
        {
            return true;
        }
    }

    return false;
}

char** strspl(const char* string, const char* delim)
{
    static char* result[STRING_LENGTH];
    int index = 0;
    char* s = strtok(strdup(string), delim);

    while (s)
    {
        result[index++] = s;
        s = strtok(NULL, delim);
    }

    return result;
}

bool strdig(const char* str)
{
    size_t amount = 0;
    for (size_t i = 0; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            amount++;
    }

    return strlen(str) - 1 == amount;
}
