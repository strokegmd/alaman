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

#include "../../include/curlutil.h"

void url_decode(char *str) 
{
    char *p = str;
    while (*p) 
    {
        if (*p == '%') 
        {
            char hex[3] = { *(p + 1), *(p + 2), '\0' };
            *p = (char) strtol(hex, NULL, 16);
            memmove(p + 1, p + 3, strlen(p + 3) + 1);
        }
        else
            p++;
    }
}

size_t curl_write(void *buffer, size_t size, size_t nmemb, void *userp)
{
    UNUSED(size);
    userp += strlen(userp);
    memcpy(userp, buffer, nmemb);
    return nmemb;
}

char *curl_get_content(const char *url)
{
    static char data[BIG_STRING_LENGTH];
    CURL *curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curl_write);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return data;
}
