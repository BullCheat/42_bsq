for file in ./maps/*.in
do
	name=`basename $file .in`
	echo "$name"
	../bsq $file &> "results/$name.res"
	diff -c "maps/$name.out" "results/$name.res"
done
