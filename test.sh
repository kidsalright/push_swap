from=$1
to=$2
ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; 
#./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
#./push_swap $ARG | ./checker -v $ARG
