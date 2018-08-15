for file in ./maps/*.in
do
	echo `basename $file`
	../bsq $file 2>&1 > /dev/null | grep -q "error" && echo PASS || echo FAIL
done
