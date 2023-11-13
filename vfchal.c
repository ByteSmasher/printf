#include "main.h"


/**
 * get_precision - A
 * @p: A
 * @params: A
 * @ap: A
 * Return: A
 */


char *get_precision(char *p, params_t *params, va_list ap) {

    int d = 0;

    // Check if the current character is a dot (.)
    if (*p != '.') {
        return p; // If not, return the current pointer
    }

    p++; // Advance to the next character

    // Handle optional '*' modifier for dynamic precision
    if (*p == '*') {
        // Extract the dynamic precision value from the argument list
        d = va_arg(ap, int);
        p++; // Advance to the next character
    } else {
        // Parse the precision value from the format string
        while (_isdigit(*p)) {
            d = d * 10 + (*p++ - '0');
        }
    }

    // Store the extracted precision value in the params structure
    params->precision = d;

    // Return the pointer to the next character after the precision specifier
    return p;
}

