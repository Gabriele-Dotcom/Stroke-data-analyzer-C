cmake_minimum_required(VERSION 3.31)
project(stroke_prediction_dataset C)

set(CMAKE_C_STANDARD 11)

add_executable(stroke_prediction_dataset
        main.c)

configure_file(healthcare-dataset-stroke-data.csv healthcare-dataset-stroke-data.csv COPYONLY)


