cmake_minimum_required(VERSION 3.26)
project(untitled4 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled4 main.c
        myMath.h
        cmake-build-debug/tarif_ara.h
        tarif_ara.h
        tarif_ekle.h
        menuleri_yazdir.h
        tarif_duzenle.h
        language.h)
