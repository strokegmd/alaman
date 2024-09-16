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

#include <unistd.h>

#include "../include/constants.h"
#include "../include/curlutil.h"
#include "../include/strutil.h"
#include "../include/packages.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, 
                "error: no operation specified (use -h for help)\n");
        return 1;
    }

    if (cstrcmp(argv[1], "-h") || cstrcmp(argv[1], "--help"))
    {
        printf("alaman -h/--help\n");
        printf("alaman --version\n");
        printf("alaman -S <packages>\n");
    }
    else if (cstrcmp(argv[1], "--version"))
    {
        printf("%s\n", "Alaman v1.0.00-test");
    }
    else if (cstrcmp(argv[1], "-S"))
    {
        if (geteuid())
        {
            fprintf(stderr, 
                    "error: you cannot perform this operation unless you are root.\n");
            return 1;
        }

        for (size_t i = 2; i < (size_t) argc; i++)
        {
            install_package(argv[i]);
        }
    }
    else
    {
        argv[0] = "pacman";
        execvp(argv[0], argv);
        return 1;   
    }

    return 0;
}
