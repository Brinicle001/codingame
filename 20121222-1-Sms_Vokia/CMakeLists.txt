cmake_minimum_required(VERSION 2.6)

#Configuration du projet
project("20121222-1-Sms_Vokia")

set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
ENABLE_TESTING()

#Génération de la liste des fichiers sources
file(
    GLOB_RECURSE
    source_files
    src/*
)

#Déclaration de l'exécutable
add_executable(
    20121222-1
    ${source_files}
)

#Déclaration des tests
add_test(
    NAME Test_1
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 1
)
add_test(
    NAME Test_2
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 2
)
add_test(
    NAME Test_3
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 3
)
add_test(
    NAME Test_4
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 4
)
add_test(
    NAME Test_5
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 5
)
add_test(
    NAME Test_6
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 6
)
add_test(
    NAME Test_7
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 7
)
add_test(
    NAME Test_8
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 8
)
add_test(
    NAME Test_9
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20121222-1 ${PROJECT_BINARY_DIR}/test/ 9
)

