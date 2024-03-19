#include <greetings.h>
#include <stdio.h>

#include <dynamic.h>
#include <static.h>

int main(int argc, char *argv[])
{
    printf("Hello OS II. Welcome to 2024 \n");
    greetings();
    printf("Calling shared lib from main. I get '%d' \n", dynamic_lib_function("Hello OS II"));
    printf("Calling static lib from main. I get '%d' \n", static_lib_function("Bye OS II"));
    return 0;
}