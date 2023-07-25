#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>






int _printf(const char *format, ...)
{
  int count = 0;
  va_list args;
  va_start(args, format);
  if (!format || !format[0]) // check if the format is NULL or empty
        return -1;
  while (*format != '\0')
        {
      if (*format != '%')
       {
       _putchar(*format);
       count++;
      }
      else
      {
     format++; // Skip to access the next character after the % symbol
               if (*format == 'c')
               {
               char c = va_arg(args, int);
               _putchar(c);
                count++;
               }
               else if (*format == 's')
               {
               char *str = va_arg(args, char *);
               count += print_string(str);
              }
              else if  (*format == '%')
              {
                 _putchar('%');
                   count++;
              }
               else if  (*format == 'd')
              {
              }
               else if  (*format == 'u')
              {
              }
  }
      format++; // Move to the next character in the format string
    }
  va_end(args);
  return count;
}
