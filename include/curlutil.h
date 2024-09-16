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

#ifndef __CURLUTIL_H
#define __CURLUTIL_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#include "constants.h"

/**
 * Decodes a URL-encoded string.
 * 
 * @param str The URL-encoded string to decode.
 */
void url_decode(char *str);

/**
 * Writes data to a user-provided buffer using cURL.
 * 
 * @param buffer The buffer to write to.
 * @param size The size of each element.
 * @param nmemb The number of elements.
 * @param userp The user-provided buffer.
 * @return The number of elements written.
 */
size_t curl_write(void *buffer, size_t size, size_t nmemb, void *userp);

/**
 * Downloads content from a URL using cURL.
 * 
 * @param url The URL to download.
 * @return The downloaded content as a string.
 */
char *curl_get_content(const char *url);

#endif
