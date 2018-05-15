cmake_minimum_required(VERSION 3.9)
project(asm_corewar C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_COMPILER "/usr/bin/gcc")

#set ( CMAKE_C_FLAGS "-Wall -Wextra -Werror")
#
file(GLOB head "includes/*.h")
#file(GLOB head "libft/ft_printf/include/*.h")
#file(GLOB head "libft/libft/*.h")
#include_directories(${PROJECT_SOURCE_DIR}/include)


file(GLOB sources0 "src/*.c")
file(GLOB sources1 "libft/libft2/*.c")
file(GLOB sources2 "libft/ft_printf/src/*.c")
file(GLOB sources3 "src/sources/src/**/**/**/*.c")
file(GLOB sources4 "src/sources/src/**/**/**/**/*.c")
file(GLOB sources5 "src/sources/src/**/**/**/**/**/*.c")
file(GLOB sources6 "test/*.c")

file(GLOB sources00 "src/*.c")
file(GLOB sources01 "src/**/*.c")
file(GLOB sources02 "src/**/**/*.c")
file(GLOB sources03 "src/**/**/**/*.c")
file(GLOB sources04 "src/**/**/**/**/*.c")
file(GLOB sources05 "src/**/**/**/**/**/*.c")

file(GLOB sources06 "test/*.c")

file(GLOB sources07 "header/*.c")
file(GLOB sources08 "header/*.h")

# all sources
set(
        sources
        ${sources1}
        ${sources2}
        ${sources3}
        ${sources4}
        ${sources5}
        ${sources6}

        ${sources00}
        ${sources01}
        ${sources02}
        ${sources03}
        ${sources04}
        ${sources05}
        ${sources06}
        ${sources07}
        ${sources08}

)

add_executable(asm_corewar

        ${sources}
        ${head}

        )

#target_link_libraries(push_swap ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)
#
#target_link_libraries(push_swap "-framework OpenGL")
#target_link_libraries(push_swap "-framework AppKit")

