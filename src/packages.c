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

#include "../include/packages.h"

/* used to fix a memory leak, when invalid versions appear */
size_t version_index = 0;

char ***get_package_data(const char *package)
{
    regex_t regex;
    regcomp(&regex, URL_REGEX, REG_EXTENDED);

    char **urls = malloc(STRING_LENGTH * sizeof(char *));
    size_t url_index = 0;

    char **versions = malloc(STRING_LENGTH * sizeof(char *));
    size_t ver_index = 0;

    char package_url[STRING_LENGTH];
    sprintf(package_url, ALA_BASE_URL, package[0], package);

    char *data = curl_get_content(package_url);
    regmatch_t match;

    while (!regexec(&regex, data, 1, &match, 0))
    {
        char *prelink = data + match.rm_so + 6;
        url_decode(prelink);

        char link[STRING_LENGTH];
        sprintf(link, ALA_DOWNLOAD_URL, package[0], match.rm_eo - match.rm_so - 6, prelink);

        char **parts = strspl(link, "/");
        char **ver = strspl(parts[4], package);
        char *version = strspl(ver[0], "-")[0];

        if (strstr(link, URL_UNALLOWED1) || strstr(link, URL_UNALLOWED2) || arrcon(versions, version))
        {
            data += match.rm_eo;
            continue;
        }

        urls[url_index] = malloc(strlen(link) + 1);
        strcpy(urls[url_index], link);
        
        versions[ver_index] = malloc(strlen(version) + 1);
        strcpy(versions[ver_index], version);

        url_index++;
        ver_index++;
        data += match.rm_eo;
    }

    regfree(&regex);

    char ***final = malloc(2 * sizeof(char **));
    final[0] = urls;
    final[1] = versions;
    return final;
}

void install_package(const char *package)
{
    char ***data = get_package_data(package);
    char **urls = data[0];
    char **vers = data[1];

    if (!strcnt(vers))
    {
        fprintf(stderr, "error: target not found: %s\n", package);
        return;
    }
    
    printf(":: There are %zu versions available for %s:\n   ", strcnt(vers) - version_index, package);

    size_t i = version_index;
    for (; i < strcnt(vers); i++)
    {
        printf("%zu) %s  ", i + 1 - version_index, vers[i]);
    }

    printf("\n\n");
    while (true)
    {
        printf("Enter a number (default=%zu): ", i - version_index);

        char input[STRING_LENGTH];
        fgets(input, STRING_LENGTH, stdin);

        if (atoi(input) > (int) i - (int) version_index)
        {
            fprintf(stderr, 
                    "error: invalid value: %s is not between 1 and %zu\n\n", 
                    strtok(input, "\n"), i - version_index);
            continue;
        }

        if (strdig(input))
        {
            int value = atoi(input) - 1;
            if (strlen(input) == 1)
                value = i - version_index - 1;

            char cmd[STRING_LENGTH];
            sprintf(cmd, PACMAN_BASE_CMD, urls[value + version_index]);
            system(cmd);

            break;
        }

        fprintf(stderr, "error: invalid number: %s\n", input);
    }
    
    version_index++;
}