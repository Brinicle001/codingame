cmake_minimum_required(VERSION 2.6)

#Configuration du projet
project("20130326-2-CGX")

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
    20130326-2-Formateur_CGX
    ${source_files}
)

#Déclaration des tests
add_test(
    NAME Test_1
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 1
)
add_test(
    NAME Test_2
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 2
)
add_test(
    NAME Test_3
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 3
)
add_test(
    NAME Test_4
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 4
)
add_test(
    NAME Test_5
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 5
)
add_test(
    NAME Test_6
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 6
)
add_test(
    NAME Test_7
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 7
)
add_test(
    NAME Test_8
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 8
)
add_test(
    NAME Test_9
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 9
)
add_test(
    NAME Test_10
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 10
)
add_test(
    NAME Test_11
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 11
)
add_test(
    NAME Test_12
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/20130326-2 ${PROJECT_BINARY_DIR}/test/ 12
)
