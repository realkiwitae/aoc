HEADER=all_headers.h
echo "#ifndef __ALL_HEADERS__" > $HEADER
echo "#define __ALL_HEADERS__" >> $HEADER
for i in $(seq 2024 2024)
do
    for file in $i/*/*.h
    do
        echo "#include <$file>" >> $HEADER
    done
done

echo "#endif" >> $HEADER