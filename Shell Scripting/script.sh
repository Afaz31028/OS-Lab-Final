add(){
	add=$(($1+$2))
	echo $add
}
echo "enter two value for add operation"
read a b
sum=$(add $a $b)
echo "sum:$sum"
echo "print here using loop"

for((i=1;i<=10;i++))
do
	echo "$i"

done
echo "print here uisng while loop "
i=1
while [ $i -le 10 ]
do 
	echo "$i"
        i=$((i+1))
done