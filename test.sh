#!/bin/bash
# $1 = solution's dir to test

testing_dir=../../test

if [ ! -d "$1" ]
then
    echo "Seems the directory '$1' doesn't even exist."
    exit 1
fi
cd "$1"
binary=`ls -1 | head -n1`
if [ ! -x "${binary}" ]
then
    echo "Seems the directory '$1' doesn't contain a solution."
    exit 1
fi
if [ ! -f "${testing_dir}/in1.txt" ]
then
    echo "Seems the directory 'test' doesn't contain a test."
    exit 1
fi
if [ ! -f "${testing_dir}/out1.txt" ]
then
    echo "Seems the directory 'test' doesn't contain a solution reference."
    exit 1
fi

all_ok="0"
for test_in in `ls ${testing_dir}/in*.txt`
do
    test_out=`echo ${test_in} | sed -e "s#\/in#\/out#"`
    echo "./${binary} < ${test_in} | tee out.txt; diff out.txt ${test_out}"
    ./${binary} < ${test_in} | tee out.txt 
    diff -B --suppress-common-lines out.txt ${test_out}
    ok=$?
    if [ "${ok}" = "0" ]
    then
        echo "
****************** REUSSITE DU TEST"
    else
        all_ok="1"
        echo "
****************** ECHEC DU TEST"
    fi
done
echo "
*****************"
if [ "${all_ok}" = "0" ]
then
    echo "REUSSITE COMPLETE"
else
    echo "ECHEC (COMPLETE OU PARTIELLE)"
fi
echo "******************"
rm out.txt

