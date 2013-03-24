cmake_minimum_required(VERSION 2.6)

#Configuration du projet
project("entrainement_1")

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
    entrainement_1
    ${source_files}
)

#Déclaration des tests
add_test(
    NAME Test_1
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/entrainement_1 ${PROJECT_BINARY_DIR}/test/ 1
)
add_test(
    NAME Test_2
    COMMAND ${PROJECT_BINARY_DIR}/../test.sh ${PROJECT_BINARY_DIR}/${EXECUTABLE_OUTPUT_PATH}/entrainement_1 ${PROJECT_BINARY_DIR}/test/ 2
)

